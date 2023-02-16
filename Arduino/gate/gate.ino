
#include<Servo.h>
int ir1=8;
int ir2=9;
int led=13;
Servo servo;
int angle=0;
int state=0;

void setup()
{
  Serial.begin(100);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(led,OUTPUT);
  servo.attach(10);
  servo.write(0);
  
}
void loop()

{ 
  int value = digitalRead(ir1);
  int value1 = digitalRead(ir2);
  Serial.println("");
  Serial.print("Ir1 value=");
  Serial.print(value);
   Serial.println("");
  Serial.print("Ir2 value=");
  Serial.print(value1);
  delay(1000);


  if(value==0)
  {
     digitalWrite(led,HIGH);
     servo.write(90);
  }
  if(value1==0)
  {
    digitalWrite(led,LOW);
    servo.write(0);
  }

 
    
  
   
}
