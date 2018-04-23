// BUTTONS - MIDI NOTE / TRANSPORT CONTROL
const int B5MIDI = 36;
const int B2MIDI = 40;
const int B3MIDI = 44;
const int B4MIDI = 48;

// POTS - CONTROL CHANGE
const int P1CC = 1;
const int P2CC = 2;
const int P3CC = 3;
const int P4CC = 4;

// FADERS - CONTROL CHANGE
const int F1CC = 5;

const byte MIDIstart = B11111010;
const byte MIDIstop = B11111100;
const byte MIDIcontinue = B11111011;


// MODES
bool transportMode = false; // True = default = transport buttons | False = general midi

void activateButton(int pin) { // TODO NEEDS TESTING
  if (transportMode) { // TRANSPORT MODE
    switch (pin) {
      case 4: // BUTTON 1
        //MIDI.sendRealTime(MidiType type = Start);
        break;

      case 5: // BUTTON 2
        //MIDI.sendRealTime(Stop);
        break;

      case 6: // BUTTON 3
        //MIDI.sendRealTime(Continue);
        break;

      case 7: // BUTTON 4
        //MIDI.sendRealTime(Continue);
        break;
    }
  } else {
    switch (pin) { // GENERAL MIDI MODE
      case 4: // BUTTON 1
        MIDI.sendNoteOn(B5MIDI, triggerValue, 1);
        break;

      case 5: // BUTTON 2
        MIDI.sendNoteOn(B2MIDI, triggerValue, 1);
        break;

      case 6: // BUTTON 3
        MIDI.sendNoteOn(B3MIDI, triggerValue, 1);
        break;

      case 7: // BUTTON 4
        MIDI.sendNoteOn(B4MIDI, triggerValue, 1);
        break;
    }
  }
}

void deactivateButton(int pin) {
  if (transportMode) { // TRANSPORT MODE
    switch (pin) {
      case 4: // BUTTON 1
        //MIDI.sendRealTime(MidiType type = Start);
        break;

      case 5: // BUTTON 2
        //MIDI.sendRealTime(Stop);
        break;

      case 6: // BUTTON 3
        //MIDI.sendRealTime(Continue);
        break;

      case 7: // BUTTON 4
        //MIDI.sendRealTime(Continue);
        break;
    }
  } else {
    switch (pin) { // GENERAL MIDI MODE
      case 4: // BUTTON 1
        MIDI.sendNoteOff(B5MIDI, 0, 1);
        break;

      case 5: // BUTTON 2
        MIDI.sendNoteOff(B2MIDI, 0, 1);
        break;

      case 6: // BUTTON 3
        MIDI.sendNoteOff(B3MIDI, 0, 1);
        break;

      case 7: // BUTTON 4
        MIDI.sendNoteOff(B4MIDI, 0, 1);
        break;
    }
  }
}

void activatePot(int pin, int potVal) {
  switch (pin) {
    case 0:
      // POT 1
      MIDI.sendControlChange(P1CC, potVal, 1);
      break;

    case 1:
      // POT 2
      MIDI.sendControlChange(P2CC, potVal, 1);
      break;

    case 2:
      // POT 3
      MIDI.sendControlChange(P3CC, potVal, 1);
      break;

    case 3:
      // POT 4
      MIDI.sendControlChange(P4CC, potVal, 1);
      break;

    case 4:
      // FADER 1
      MIDI.sendControlChange(F1CC, potVal, 1);
      break;
  }
}

