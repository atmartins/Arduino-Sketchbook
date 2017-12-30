// Understanding networking
//
// December 2017
// Nolan Price and Aaron Martins
//
// See https://github.com/atmartins/Arduino-Sketchbook/blob/master/README.md
//

int PIN_IN = 12;
int PIN_TALK = 13; //show what we received with on-board LED

void setup() {
  pinMode(PIN_IN, INPUT);
  pinMode(PIN_TALK, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pinState = digitalRead(PIN_IN);
  digitalWrite(PIN_TALK, pinState);
  Serial.println(pinState);
  delay(1); // delay in between reads for stability
}

