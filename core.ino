#include <QTRSensors.h>
#include "pins.h"

QTRSensorsAnalog QTRA((unsigned char[]){ A0, A1, A2, A3, A4, A5, A6, A7 }, 8);
unsigned int sensors[8];
int lastError = 0;
float Kp = 0.5;
float Kd = 0.2;

void setup() {
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
  return speedDifference;
}
