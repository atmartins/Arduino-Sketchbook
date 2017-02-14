// Turn on a Single Channel Relay based on a HC-SR04 ultrasonic sensor.
// Aaron Martins. 2016-12-11
// http://playground.arduino.cc/Code/NewPing#Methods
#include <Average.h>

#define TRIGGER_PIN 11 //orange
#define ECHO_PIN 12 //yellow
#define RELAY_PIN 13

#define CAT_DISTANCE 30 //cm
int MAX_RANGE; //cm

Average<int> ds(25);

void setup() {
  Serial.begin (9600);
  MAX_RANGE = CAT_DISTANCE * 2; // to create equal drag on avg in high direction.
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  relayOff();
}

void loop() {
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;
  
  if (distance >= MAX_RANGE || distance <= 0) {
    Serial.println("Out of range");
    distance = MAX_RANGE; //avoid 0 in avg
  }
  float avg = ds.rolling(distance);
  if (avg < CAT_DISTANCE) {
    relayOn();
  } else {
    relayOff();
  }

  Serial.print("avg ");
  Serial.print(avg);
  Serial.println(" cm");
  
  Serial.print("actual ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}

void relayOn() {
  digitalWrite(RELAY_PIN, HIGH);
}

void relayOff() {
  digitalWrite(RELAY_PIN, LOW);
}


