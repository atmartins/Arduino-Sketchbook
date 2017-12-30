int PIN_IN = 12;
int PIN_TALK = 13; //show what we received

void setup() {
  pinMode(PIN_IN, INPUT);
  pinMode(PIN_TALK, OUTPUT);
}

void loop() {
  int pinState = digitalRead(PIN_IN);
  digitalWrite(PIN_TALK, pinState);
  delay(1);        // delay in between reads for stability
}
