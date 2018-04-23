void updatePot(int pin, int* potVal, int* oldPotVal) {
  float temp = 0.00;
  temp = ((analogRead(pin) * 100) / 700);

  if (temp != *oldPotVal) {
    if ((temp > *oldPotVal + 1) | (temp < *oldPotVal - 1)) {
      *potVal = temp;
      activatePot(pin, *potVal);

      // Update old values last
      *oldPotVal = *potVal;
    }
  }
}

void updateButton(int pin, Bounce* buttonBounce) {
  buttonBounce->update();

  if (buttonBounce->rose()) {
    // Button 1 Pressed
    activateButton(pin);
    digitalWrite(testLED, HIGH);  // LED FOR TESTING
  }
  
  if (buttonBounce->fell()) {
    deactivateButton(pin);
    digitalWrite(testLED, LOW);   // LED FOR TESTING
  }
}

void startLED(int pin) {
  // POWER ON LED
  digitalWrite(pin, HIGH);
}

