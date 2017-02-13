/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */
import processing.serial.*;
Serial myPort;  // Serial port you are using

int valueLen = 250; //number of data points to keep in the values array
float[] values = new float[valueLen]; //array of values
int lf = 10;    // Linefeed in ASCII
String serValStr = null;
float num;
float lastY = 0; //y value from previous
int spread = 2; //multiply data point distance (horizontally) by this factor.
int verticalMin = 0;
int verticalMax = 200;
float col = 0;

void setup() 
{
  size(630, 350);
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 115200);
  myPort.clear();
  fill(0,0,0);
  for(int i = 0; i < valueLen; i++){
    values[i] = 0;
  }
  strokeWeight(1);
}

void draw()
{
  while (myPort.available() > 0) {
    serValStr = myPort.readStringUntil(lf);
    if (serValStr != null) {
      num=float(serValStr);  // Converts and prints float
      if(Float.isNaN(num)){
        num = 0.0;
      } 
    } else {
      num = 0.0;
    }
  }
  paint(num);
  myPort.clear();
  delay(10);
}

void paint(float val){

  val = map(val, 0, 1024, verticalMax, verticalMin);
  col = map(val, 0, 1024, 0, 255);
  background(255,255,255, 200);
  values = append(values, val);
  values = subset(values, 1);

  //draw stuff
  translate(50,70);
  drawScale();
  drawValues();  
}

void calcValues(){
}

void drawValues(){
  for(int i = 0; i < valueLen; i++){
    int x = i*spread;
    float y = values[i];
    stroke(255-(x*1.5),255-(x*1.5),255,255);
    line(x-1,lastY,x,y);
    lastY = y;
  }
}

void drawScale(){
  stroke(150,150,150,150);
  fill(50,50,50); //text colour
  float w = valueLen*spread;
  float ym5 = (verticalMax*0);
  float padLeft = w+10;
  int padTop = 5;
  line(0, ym5, w, ym5); //5v line
  text("5v", padLeft, ym5+padTop);
  
  float ym3 = (verticalMax*0.25);
  line(0, ym3, w, ym3); //3.75v line
  text("3.75v", padLeft, ym3+padTop);
  
  float ym2 = (verticalMax*0.5);
  line(0, ym2, w, ym2);
  text("2.5v", padLeft, ym2+padTop);
  
  float ym1 = (verticalMax*0.75);
  line(0, ym1, w, ym1);
  text("1.25v", padLeft, ym1+padTop);
  
  float ym0 = (verticalMax);
  line(0, ym0, w, ym0);
  text("0v", padLeft, ym0+padTop);
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
