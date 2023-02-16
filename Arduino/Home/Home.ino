/*code by Vivek Agarwal , you can change the code and make your creativity to reality and make excellent projects .
 * Let's code
 */
#include <Servo.h>
#define trigPin 2
#define echoPin 3
#define LEDlampRed 9
#define LEDlampYellow 10
#define LEDlampGreen 11
#define soundbuzzer 7
int sound = 500;

Servo servo1;
Servo servo2;
int led1=8;
int led2=9;
int trig=4;
int echo=5;
int servo1_pin=6;
int servo2_pin=7;
int duration=0,dist=0;
void setup()
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LEDlampRed, OUTPUT);
pinMode(LEDlampYellow, OUTPUT);
pinMode(LEDlampGreen, OUTPUT);
pinMode(soundbuzzer, OUTPUT);

{
Serial.begin(9600);
  
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  servo1.write(90);
  servo2.write(90);
}

void loop()
{
  digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);
duration = pulseIn(echo, HIGH);
dist = (duration*0.034) / 2;    //obtain distance

if(dist<20)
{
  Serial.println("Door Open");
  digitalWrite(led2,LOW);
  digitalWrite(led1,HIGH);
  servo1.write(90);
  servo2.write(0);
  delay(2000);
 
}
else
{
  Serial.println("Door Closed");
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  servo1.write(0);
  servo2.write(90);
  delay(1000);
}

***


}
void loop() {
long durationindigit, distanceincm;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
durationindigit = pulseIn(echoPin, HIGH);
distanceincm = (durationindigit/5) / 29.1;

if (distanceincm < 20) {
digitalWrite(LEDlampGreen, HIGH);
}
else {
digitalWrite(LEDlampGreen, LOW);
}

if (distanceincm < 10) {
digitalWrite(LEDlampYellow, HIGH);
}
else {
digitalWrite(LEDlampYellow,LOW);
}
if (distanceincm < 5) {
digitalWrite(LEDlampRed, HIGH);
sound = 1000;
}
else {
digitalWrite(LEDlampRed,LOW);
}

if (distanceincm > 5 || distanceincm <= 0){
Serial.println("Outside the permissible range of distances");
noTone(soundbuzzer);
}
else {
Serial.print(distanceincm);
Serial.println(" cm");
tone(soundbuzzer, sound);
}

delay(300);
}
