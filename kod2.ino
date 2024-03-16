#include <QTRSensors.h>

#define MIN_SPEED 70
#define ENA_PIN 11
#define SAG_AIN1_PIN 10
#define SAG_PWM_PIN 5
#define SOL_BIN1_PIN 8
#define ENB_PIN 7
#define SOL_PWM_PIN 6
#define SOL_ENCODER_PIN 2
#define SAG_ENCODER_PIN 3
#define LINE_SENSOR_PINS {A0, A1, A2, A3, A4, A5, A6, A7}

QTRSensorsAnalog qtra(LINE_SENSOR_PINS, 8);

// PID Parameters
double Kp = 0.1;
double Ki = 0.01;
double Kd = 0.05;
double setpoint = 4000; // Setpoint for the line position
double integral = 0;
double lastError = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(SAG_AIN1_PIN, OUTPUT);
  pinMode(SAG_PWM_PIN, OUTPUT);
  pinMode(SOL_BIN1_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  pinMode(SOL_PWM_PIN, OUTPUT);
  pinMode(SOL_ENCODER_PIN, INPUT);
  pinMode(SAG_ENCODER_PIN, INPUT);
  
  delay(1000);
  calibrateSensors();
}

void loop() {
  double position = readSensors();
  double error = setpoint - position;
  integral += error;
  double derivative = error - lastError;
  
  // PID control
  double correction = Kp * error + Ki * integral + Kd * derivative;
  
  // Adjust motor speeds
  int leftSpeed = MIN_SPEED + correction;
  int rightSpeed = MIN_SPEED - correction;
  
  motorControl(leftSpeed, rightSpeed);
  
  lastError = error;
}

void calibrateSensors() {
  for (int i = 0; i < 250; i++) {
    if (i < 50 || (i >= 50 && i < 250 && i % 10 == 5)) {
      motorControl(30, -30);
    } else if (i >= 250) {
      motorControl(0, 0);
      delay(3);
    }
    qtra.calibrate();
    delay(1);
  }
}

void motorControl(int leftSpeed, int rightSpeed) {
  analogWrite(SOL_PWM_PIN, leftSpeed);
  analogWrite(SAG_PWM_PIN, rightSpeed);
}

double readSensors() {
  return qtra.readLine();
}
