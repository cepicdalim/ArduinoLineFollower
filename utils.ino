void beep(int count, int delayAfter) {
  for (int i = 0; i < count; i++) {
    motorControl(200, -200); // Spin motors in opposite directions
    delay(10); // Adjust delay for desired sound duration
    motorControl(0, 0); // Stop motors
    delay(150); // Adjust delay for desired pause between sounds
  }
  delay(delayAfter);
}


void log(char msg[]) {
  Serial.println(msg);
}