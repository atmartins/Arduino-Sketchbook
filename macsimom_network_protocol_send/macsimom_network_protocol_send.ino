// Understanding networking
//
// December 2017
// Nolan Price and Aaron Martins
//
// See https://github.com/atmartins/Arduino-Sketchbook/blob/master/README.md
//

int DATA = 13;
//int CLOCK = 12; //Not used yet

void setup() {}

void sendByte(byte bite) {
  pinMode(DATA, OUTPUT);
  //pinMode(CLOCK, OUTPUT);

  for (int i = 0; i < 8; i++) {
    int binaryVal = bitRead(bite, i);
    digitalWrite(DATA, binaryVal);
    delay(500);
  }
}

void loop() {
  sendByte('M');
  sendByte('A');
  sendByte('C');
  sendByte('S');
  sendByte('M');
  sendByte('O');
  sendByte('M');
}

