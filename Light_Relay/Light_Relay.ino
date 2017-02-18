// Turn on a Single Channel Relay based on a HC-SR04 ultrasonic sensor.
// Aaron Martins. 2016-12-11

/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

#define trigPin 11 //orange
#define echoPin 12 //yellow
#define relay 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay, OUTPUT);
  relayOff();
  
}

void relayOn() {
  digitalWrite(relay, HIGH);
}
void relayOff() {
  digitalWrite(relay, LOW);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  if (distance < 100) {  // This is where the relay On/Off happens
    relayOn();
    delay(60000); //stay on for 1 minute
  }
  else {
    relayOff();
  }
  
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(1000); //don't flicker too frequently. Only turn on/off every X millis.
}
