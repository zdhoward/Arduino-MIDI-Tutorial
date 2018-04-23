// references at http://arduinomidilib.fortyseveneffects.com

void setupCallbacks() {
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  //MIDI.setHandleControlChange(handleControlChange);
  //MIDI.setHandlePitchBend(handlePitchBend);
  //MIDI.setHandleContinue(handleContinue);
  //MIDI.setHandleStart(handleStart);
  //MIDI.setHandleStop(handleStop);
  //MIDI.setHandleClock(handleClock);
}

// MIDI CONTROLS//
void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  Serial.println(String("") + "CH: " + channel + " P: " + pitch + " V: " + velocity);
  
  digitalWrite(testLED, HIGH);
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  digitalWrite(testLED, LOW);
}

void handleControlChange(byte channel, byte number, byte value) {
  
}

void handlePitchBend(byte channel, int bend) {
  
}

// TRANSPORT CONTROL
void handleContinue() {
  
}

void handleStart() {
  
}

void handleStop() {
  
}

void handleClock() {
  
}

void handleProgramChange(byte channel, byte number) {
  
}

