/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */
import processing.serial.*;
int valueLen = 255;
float[] values = new float[valueLen];
int left = 0;
int lf = 10;    // Linefeed in ASCII
String myString = null;
Serial myPort;  // Serial port you are using
float num;
float lastY = 0;

void setup() 
{
  size(600, 600);
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
  fill(0,0,0);
  for(int i = 0; i < valueLen; i++){
    values[i] = 0;
  }
  strokeWeight(2);
}

void draw()
{
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil(lf);
    if (myString != null) {
      num=float(myString);  // Converts and prints float
      if(!Float.isNaN(num)){
        background(255,255,255, 200);
        values = append(values, num);
        values = subset(values, 1);
        println(values);
        for(int i = 0; i < valueLen; i++){
          int x = i;
          float y = values[i]/2;
          stroke(255-x,255-x,x,105);
          line(x-1,lastY,x,y);
          lastY = y;
        }
        
      }
    }
  }
  myPort.clear();

}



/*

// Wiring / Arduino Code
// Code for sensing a switch status and writing the value to the serial port.

int switchPin = 4;                       // Switch connected to pin 4

void setup() {
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.write(1);               // send 1 to Processing
  } else {                               // If the switch is not ON,
    Serial.write(0);               // send 0 to Processing
  }
  delay(100);                            // Wait 100 milliseconds
}

*/
