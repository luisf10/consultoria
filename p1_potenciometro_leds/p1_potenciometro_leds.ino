/*
Autor: Luis F.
University: UNI 
Faculty:    FIEE

Target:  8 -leds on/off  with  delay variable.

*/

const int n=8;
int potentiometer=0; //PIN A0:
int timer;
int i;
void setup(){
  for(i=0;i<n;i++) pinMode(i+2,OUTPUT);  // pins: 2,3,...,9  digital outputs
  
  for(i=0;i<n;i++) digitalWrite(i+2,LOW);  //INITIAL VALUES: LOW, ALL LEDS
}

void loop(){

 //Process: counter;
     
   for(i=0;i<n;i++){
       timer = analogRead(potentiometer);
       delay(1);
       digitalWrite(i+2,HIGH);
       delay(timer);
       timer = analogRead(potentiometer);  //get value 10-bits  
       delay(1);
       digitalWrite(i+2,LOW);
       delay(timer);
  }
 
}
