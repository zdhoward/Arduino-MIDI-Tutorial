#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const int testLED = 13;

void setup() {
  // Set the test LED's pin to be OUTPUT
  pinMode(testLED, OUTPUT);

  // Flash LED to more easily see it starting, this is not necessary but I like it
  flashLED(testLED);

  // With this library we can bind standard midi messages to trigger specific commands
  // See the Callbacks tab to configure these to your liking
  setupCallbacks();

  // Select which MIDI channel to watch
  // We will be watching all channels, you can still filter through specific channels in the code
  MIDI.begin(MIDI_CHANNEL_OMNI);

  // This is the baud rate on which MIDI runs
  // Do not change this unless you know what you are doing
  Serial.begin(31250);

  // This msg will be sent over 31250 to our Processing program
  Serial.println("Setup Complete");

}

void loop() {
  // Keep this loop as small as possible in order to keep latency down
  MIDI.read();

  // For debugging your Processing connection
  // Will continue to send a string over 31250 over and over
  //Serial.println("TEST READ");
}



