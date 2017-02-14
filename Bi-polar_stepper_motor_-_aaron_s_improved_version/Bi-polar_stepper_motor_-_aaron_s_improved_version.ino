int A = 2;
int B = 3;
int C = 4;
int D = 5;
long del = 2000;
int stap = 1;

void setup() {                
  pinMode(A, OUTPUT);     
  pinMode(B, OUTPUT);     
  pinMode(C, OUTPUT);     
  pinMode(D, OUTPUT);     
}

void een(){
  digitalWrite(A, LOW);   
  digitalWrite(B, HIGH);   
  digitalWrite(C, HIGH);   
  digitalWrite(D, LOW);   
  delayMicroseconds(del);
}
void twee(){
  digitalWrite(A, LOW);   
  digitalWrite(B, LOW);   
  digitalWrite(C, HIGH);   
  digitalWrite(D, HIGH);   
  delayMicroseconds(del);
}
void drie(){
  digitalWrite(A, HIGH);   
  digitalWrite(B, LOW);   
  digitalWrite(C, LOW);   
  digitalWrite(D, HIGH);   
  delayMicroseconds(del);
}
void vier(){
  digitalWrite(A, HIGH);   
  digitalWrite(B, HIGH);   
  digitalWrite(C, LOW);   
  digitalWrite(D, LOW);   
  delayMicroseconds(del);
}
void motorOff(){
  digitalWrite(A, LOW);   
  digitalWrite(B, LOW);   
  digitalWrite(C, LOW);   
  digitalWrite(D, LOW);   
}

// the loop routine runs over and over again forever:
void loop() {

  for (int i=0; i<=500; i++){
    een(); 
    twee();
    drie();
    vier();
  }
  motorOff();
  
  delay(2000);
 
}

