void motorControl(int rightSpeed, int leftSpeed) {
  if (leftSpeed >= 0) {
    digitalWrite(ENB, HIGH);
    digitalWrite(SOL_BIN1_PIN, LOW);  // Set direction forward
    analogWrite(SOL_PWM_PIN, min(abs(leftSpeed), MAX_SPEED));
  } else {
    digitalWrite(ENB, LOW);
    digitalWrite(SOL_BIN1_PIN, HIGH);  // Set direction reverse
    analogWrite(SOL_PWM_PIN, min(abs(leftSpeed), MAX_SPEED));
  }

  // Right Motor Control
  if (rightSpeed >= 0) {
    digitalWrite(ENA, HIGH);
    digitalWrite(SAG_AIN1_PIN, LOW);  // Set direction forward
    analogWrite(SAG_PWM_PIN, min(abs(rightSpeed), MAX_SPEED));
  } else {
    digitalWrite(ENA, LOW);
    digitalWrite(SAG_AIN1_PIN, HIGH);  // Set direction reverse
    analogWrite(SAG_PWM_PIN, min(abs(rightSpeed), MAX_SPEED));
  }
}

void stop() {
  motorControl(0, 0);
}