#include <MIDI.h>
#include <Bounce2.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// BUTTONS
const int B5 = 4; // B1 is reserved so its B5 for now
Bounce B5bounce = Bounce();
const int B2 = 5;
Bounce B2bounce = Bounce();
const int B3 = 6;
Bounce B3bounce = Bounce();
const int B4 = 7;
Bounce B4bounce = Bounce();

// POTENTIOMETERS
const int P1 = 0;
const int P2 = 1;
const int P3 = 2;
const int P4 = 3;

// FADERS
const int F1 = 4;

// SWITCHES
//const int S1 = 

// LED
const int testLED = 2;
const int LED = 3;

// Initialize Variables
int B5state, B2state, B3state, B4state, _B5state, _B2state, _B3state, _B4state, P1val, P2val, P3val, P4val, _P1val, _P2val, _P3val, _P4val, F1val, _F1val = 0;
int triggerValue = 100; // 1-127

void setup() {
  // SETUP PINS
  Serial.begin(9600); // For testing
  pinMode(testLED, OUTPUT); // For testing and maybe tx monitor
  pinMode(LED, OUTPUT);

  pinMode(B5, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);

  // Attach Debouncers
  B5bounce.attach(B5);
  B2bounce.attach(B2);
  B3bounce.attach(B3);
  B4bounce.attach(B4); 

  MIDI.begin(MIDI_CHANNEL_OMNI);

  startLED(LED);
}

void loop() {
  // BUTTONS
  updateButton(B5, &B5bounce);
  updateButton(B2, &B2bounce);
  updateButton(B3, &B3bounce);
  updateButton(B4, &B4bounce);

  // POTENTIOMETERS
  //updatePot(P1, &P1val, &_P1val);
  //updatePot(P2, &P2val, &_P2val);
  //updatePot(P3, &P3val, &_P3val);
  //updatePot(P4, &P4val, &_P4val);

  // FADERS
  //updatePot(F1, &F1val, &_F1val);
}

