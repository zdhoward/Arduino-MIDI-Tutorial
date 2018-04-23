void flashLED(const int LED) {
  digitalWrite(LED, HIGH);
  delay(1500);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);
}
