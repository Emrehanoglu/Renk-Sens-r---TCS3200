#include <Servo.h>
#define s0 4
#define s1 5
#define s2 6
#define s3 7
#define sensorOut 8

Servo motor;
#define kled 9
#define yled 10
#define mled 11


int kirmizi,yesil,mavi = 0;

void setup(){
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(sensorOut,INPUT);
  pinMode(kled,OUTPUT);
  pinMode(yled,OUTPUT);
  pinMode(mled,OUTPUT);
  motor.attach(3);
  
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);

  Serial.begin(9600);  
}

void loop(){
  //KIRMIZI için
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);

  kirmizi = pulseIn(sensorOut,LOW);
  kirmizi = map(kirmizi,63,100,0,255);

  Serial.print("K= ");
  Serial.print(kirmizi);
  Serial.print(" ");
  delay(100);

  //YEŞİL için
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);

  yesil = pulseIn(sensorOut,LOW);
  yesil = map(yesil,58,129,0,255);

  Serial.print("Y= ");
  Serial.print(yesil);
  Serial.print(" ");
  delay(100);

  //MAVİ için
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);

  mavi = pulseIn(sensorOut,LOW);
  mavi = map(mavi,49,109,0,255);

  Serial.print("M= ");
  Serial.print(mavi);
  Serial.println(" "); 
  delay(100);

  if(kirmizi > 0 and kirmizi < 90 and kirmizi < yesil and kirmizi < mavi){
    digitalWrite(kled,HIGH);
    digitalWrite(yled,LOW);
    digitalWrite(mled,LOW);
    motor.write(54);
  }
  else if(yesil > 0 and yesil < 90 and yesil < kirmizi and yesil < mavi){
    digitalWrite(kled,LOW);
    digitalWrite(yled,HIGH);
    digitalWrite(mled,LOW);
    motor.write(135);
  }
  else if(mavi > 0 and mavi < 90 and mavi < kirmizi and mavi < yesil){
    digitalWrite(kled,LOW);
    digitalWrite(yled,LOW);
    digitalWrite(mled,HIGH);
    motor.write(93);
  }
  else if(mavi < 0 and kirmizi < 0 and mavi < yesil and kirmizi < yesil){
    analogWrite(kled,255);
    analogWrite(yled,0);
    analogWrite(mled,255);
    motor.write(170);
  }
  else if(yesil < 0 and kirmizi < 0 and yesil < mavi and kirmizi < mavi){
    analogWrite(kled,255);
    analogWrite(yled,255);
    analogWrite(mled,0);
    motor.write(0);
  }  
  else{
    digitalWrite(kled,LOW);
    digitalWrite(yled,LOW);
    digitalWrite(mled,LOW);
  }     
}
