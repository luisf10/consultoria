/*
  Autor: Luis F.
  Fecha: 06/09/2016
  UNI-FIEE
  Target: Activación de reledes por conteo de pulsador
  	    -Pimera pulsada se activa un relay1.
	    -Segunda pulsada se activa un relay2 (el relay 1 sigue prendido).
	    -Tercera pulsada se activa otro relay3 (el relay 1 y 2 siguen prendido9
	    -Cuarta pulsada se activa otro relay4, pero el relay1  se apaga(relay 2,3,4, esta prendidos pero relay 1 se apaga)
	    -Quinta pulseada se apagan todos los relays

  El pulsador se activa con 0 volt(normalmente conectada a Vcc,y cuando se presiona,manda un 0V).

*/
int flagProcess=0;
int pulsador=2;  //# pin
int relay1=3;    //# pin
int relay2=4;    //# pin
int relay3=5;    //# pin
int relay4=6;    //# pin

volatile int counter=0;
long T0 = 0;  //Tiempo util para eliminar el efecto rebote:
void proceso();

void setup(){
  pinMode(relay1,OUTPUT);
  pinMode(relay3,OUTPUT); 
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
  
  //Initial values: LOW
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  digitalWrite(relay3,LOW);
  digitalWrite(relay4,LOW);
  
  //Activamos la interrupción: pin2,detecta flancos de bajada
  attachInterrupt(0,pulsador_isr,FALLING);   //0:INT0( PIN2) ,   1:INT1 (PIN3) arduino uno:
}

//////////////////////loop principal////////////////////////
void loop(){
 proceso();
 
}
///////////////Función proces        /////////////////////
void proceso(){
 if(flagProcess==1){
     switch(counter){
    
    case 1:  
            digitalWrite(relay1,HIGH);
            digitalWrite(relay2,LOW);
            digitalWrite(relay3,LOW);
            digitalWrite(relay4,LOW);
            break;
            
    case 2:  
            digitalWrite(relay1,HIGH);
            digitalWrite(relay2,HIGH);
            digitalWrite(relay3,LOW);
            digitalWrite(relay4,LOW);
            break;
            
    case 3:  
            digitalWrite(relay1,HIGH);
            digitalWrite(relay2,HIGH);
            digitalWrite(relay3,HIGH);
            digitalWrite(relay4,LOW);
            break;
         
            
    case 4:  
            digitalWrite(relay1,LOW);
            digitalWrite(relay2,HIGH);
            digitalWrite(relay3,HIGH);
            digitalWrite(relay4,HIGH);
            break;
            
    case 5: //resetea todo. 
            digitalWrite(relay1,LOW);
            digitalWrite(relay2,LOW);
            digitalWrite(relay3,LOW);
            digitalWrite(relay4,LOW);
            counter = 0;
            break;
     }
  
  
  }

}
////////////////////////Función de interrupción//////////////////////////
void pulsador_isr(){
  
  if(millis()>T0+250){  //Si supera los 250ms,entonces no es un rebote
     counter++;
     flagProcess=1;
     T0 = millis();
  }
 
  
} 
////////////////////////////////////////////////////////////////////////
