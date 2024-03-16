#include <QTRSensors.h>
#include "pins.h"

QTRSensorsAnalog QTRA((unsigned char[]){ A0, A1, A2, A3, A4, A5, A6, A7 }, 8);
unsigned int sensors[8];
int lastError = 0;
float Kp = 0.5;
float Kd = 0.2;

int INITIAL_MIN_SPEED = 24;
int MIN_SPEED = 24;
int MAX_SPEED = 56;

const int ERROR_TOLERANCE = 500;
const int MAX_ERROR = 3500;
const int MAX_ERROR_COUNT = 10;
int errorList[MAX_ERROR_COUNT];
int adjustSpeed = 20;
int index = 0;

void setup()
{
  clearError();
  preparePins();
  beep(2, 1000);
  calibrateSensors();
}

void loop() {
  if (digitalRead(SWITCH_ONE) == HIGH || detectWall()) {
    stop();
    delay(10);
    return;
  }

  int speedDifference = followLine();
  int l = speedDifference > 0 ? speedDifference : 0;
  int r = speedDifference < 0 ? speedDifference : 0;
  
  motorControl(MIN_SPEED + l, MIN_SPEED + r);
}

void calibrateSensors() {
  for (int i = 0; i < 64; i++) {
    motorControl(-CALIBRATION_SPEED, -CALIBRATION_SPEED);
    QTRA.calibrate();
    delay(1);
  }
  stop();
  beep(3, 2000);
}

bool detectWall() {
  bool r = digitalRead(MZ80_PIN) == HIGH;
  if (r){
    log("Wall Detected");
    delay(10);
  }
  return r;
}

int followLine() {
  int error = QTRA.readLine(sensors, 1, 1) - 3500; // [-3500, 3500]
  int speedDifference = Kp * error + Kd * (error - lastError); // PID
  lastError = error;
  addError(error);
  adjustMotorMinSpeed();
  return speedDifference;
}

void addError(int error)
{
  error = abs(error); //abs
  errorList[index % MAX_ERROR_COUNT] = error;
  index++;
}

void clearError()
{
  for (int i = 0; i < MAX_ERROR_COUNT; i++)
  {
    errorList[i] = MAX_ERROR;
  }
  index = 0;
}

int calculateAverageError()
{
  int sum = 0;
  for (int i = 0; i < MAX_ERROR_COUNT; i++)
  {
    sum += errorList[i];
  }
  return sum / MAX_ERROR_COUNT;
}

void adjustMotorMinSpeed(){
  if (index < MAX_ERROR_COUNT) return;

  int averageError = calculateAverageError();

  if(averageError < 70){
    // İyi gidiyoruz
    MIN_SPEED += 2;
    MIN_SPEED = min(MIN_SPEED,MAX_SPEED);
  }else{
    // Kötü gidiyoruz
    if(MIN_SPEED > INITIAL_MIN_SPEED){
      // Hızlanmışısız
      stop();
    }
    MIN_SPEED = INITIAL_MIN_SPEED;
    clearError();
  }
}
