int DATA = 13;
int CLOCK = 12;
void setup() {
  
}


void sendByte(byte bite) {
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  for(int i = 0; i < 8; i++) {
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
  
//  digitalWrite(PIN_OUT, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(4000);                       // wait for a second
//  digitalWrite(PIN_OUT, LOW);    // turn the LED off by making the voltage LOW
//  delay(500);
}

