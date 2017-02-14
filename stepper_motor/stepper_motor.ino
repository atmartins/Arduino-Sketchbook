/*
Adafruit Arduino - Lesson 16. Stepper
*/
 
#include <Stepper.h>
 
int in1Pin = 4;
int in2Pin = 3;
int in3Pin = 2;
int in4Pin = 1;
 
Stepper motor(512, in1Pin, in2Pin, in3Pin, in4Pin);  
 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
 
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  //while (!Serial);
  
  Serial.begin(9600);
  motor.setSpeed(20);
}
 
void loop()
{
  int steps = 20;
    motor.step(steps);
  /*if (Serial.available())
  {
    int steps = Serial.parseInt();
    motor.step(steps);
  }*/
}
