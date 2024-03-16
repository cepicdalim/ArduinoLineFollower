#define CALIBRATION_SPEED 42
#define ENA 11
#define SAG_AIN1_PIN 10
#define SAG_PWM_PIN 5
#define SOL_BIN1_PIN 8
#define ENB 7
#define SOL_PWM_PIN 6
#define SOL_ENCODER_PIN 2
#define SAG_ENCODER_PIN 3
#define MZ80_PIN 4
#define LINE_SENSOR_PINS \
  { A0, A1, A2, A3, A4, A5, A6, A7 }
#define SWITCH_ONE 12
#define SWITCH_TWO 13

void preparePins(){
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(SAG_AIN1_PIN, OUTPUT);
  pinMode(SAG_PWM_PIN, OUTPUT);
  pinMode(SOL_BIN1_PIN, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(SOL_PWM_PIN, OUTPUT);
  pinMode(SOL_ENCODER_PIN, INPUT);
  pinMode(SAG_ENCODER_PIN, INPUT);
  pinMode(MZ80_PIN, INPUT);
  pinMode(SWITCH_ONE, INPUT);
  pinMode(SWITCH_TWO, INPUT);
}