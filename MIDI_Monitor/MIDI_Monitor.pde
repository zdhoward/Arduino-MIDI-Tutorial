import processing.serial.*;
Serial myPort;
String DATA = "";

// You must configure this manually to whatever COM port you want to monitor
// My arduino runs on COM11 for me
String comPort = "COM11";

void setup() {
  size(500, 500);
  myPort = new Serial(this, comPort, 31250);
  myPort.bufferUntil('\n');
}

void serialEvent(Serial myPort) {
   DATA = myPort.readStringUntil('\n');
}

void draw() {
  background(0,0,40);
  text(DATA,height/2,width/2);
  fill(255);
  textSize(60);
  textAlign(CENTER);
}
