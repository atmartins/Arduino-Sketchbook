/*
   BYJ48 Stepper motor code
   Connect :
   IN1 >> D8
   IN2 >> D9
   IN3 >> D10
   IN4 >> D11
   VCC ... 5V Prefer to use external 5V Source
   Gnd
   written By :Mohannad Rawashdeh
  http://www.instructables.com/member/Mohannad+Rawashdeh/
     28/9/2013
  */
#define SWITCH  2
#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
#define LED  13


int Step = 0;
int stepsToTake = 4096*3; //4096 is one revolution
boolean Direction = 1;
unsigned long last_time;
unsigned long currentMillis;
int steps_left = 0;
long time;
void setup()
{
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
}

void loop()
{
  
  int buttonState = digitalRead(SWITCH);
  Serial.println(buttonState); //1 off, 0 hand in front
  digitalWrite(LED, LOW);
  if(buttonState == 0){
    digitalWrite(LED, HIGH);
    steps_left=stepsToTake;
    while(steps_left>0){
      currentMillis = micros();
      if(currentMillis-last_time>=1000){
        stepper(); 
        time=time+micros()-last_time;
        last_time=micros();
        steps_left--;
      }
    }
    Serial.println(time);
    Serial.println("Wait...!");
    Direction=!Direction;
    
  }
  
  delay(50);
  
  steps_left=stepsToTake;
}

void stepper(){
    switch(Step){
       case 0:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
       break; 
       case 1:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, HIGH);
       break; 
       case 2:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
       break; 
       case 3:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, HIGH);
         digitalWrite(IN4, LOW);
       break; 
       case 4:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
       case 5:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, HIGH);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
         case 6:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
       case 7:
         digitalWrite(IN1, HIGH); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, HIGH);
       break; 
       default:
         digitalWrite(IN1, LOW); 
         digitalWrite(IN2, LOW);
         digitalWrite(IN3, LOW);
         digitalWrite(IN4, LOW);
       break; 
    }
    SetDirection();
}

void SetDirection(){
  if(Direction==1){ Step++;}
  if(Direction==0){ Step--; }
  if(Step>7){Step=0;}
  if(Step<0){Step=7;}
}

