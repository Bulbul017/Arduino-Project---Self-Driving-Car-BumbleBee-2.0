#include <SoftwareSerial.h>

#define echopin  A0 // echo pin
#define trigpin A1 // Trigger pin

SoftwareSerial BT(0, 1); // 0 -> TX PIN , 1 -> RX PIN , check with ardiono and bluetooth module fro clarity

char Incoming_value = 0;
long duration;
int distanceFwd;
                
void setup() 
{
  Serial.begin(9600);
  BT.begin(9600); // Setting the baud rate of Software Serial Library  
  delay(500);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT );         
  pinMode(10, OUTPUT);       
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  if(BT.available() > 0)  
  {
    Incoming_value = BT.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1'){             
      digitalWrite(10, HIGH);
      Serial.print(Incoming_value);        
      Serial.print("\n");}  
    else if(Incoming_value == '0'){       
      digitalWrite(10, LOW);}
    else if(Incoming_value == '2'){       
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);}
    else if(Incoming_value == '3'){       
      digitalWrite(7, HIGH);   
      digitalWrite(8, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);}
    else if(Incoming_value == '4'){       
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);}   
    else if(Incoming_value == '5'){       
      digitalWrite(6, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(7, LOW);}   
      
  }

  distanceFwd = data();
  BT.print(distanceFwd); //send distance to MIT App 
  BT.println(";"); 
  Serial.print(distanceFwd); 
}

long data()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn (echopin,HIGH);
  return duration / 29 / 2; 
}
