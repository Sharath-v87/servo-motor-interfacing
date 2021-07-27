#include <Servo.h>
int pos=0;
Servo sr1;
Servo sr2;
Servo sr3;
Servo sr4;
Servo sr5;
int trig = 3;
int echo = 4;
int time;
float distance;
float dist;

float ultrasonicop(){
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  time = pulseIn(echo,HIGH,30000);
  distance = 343*0.0001*(time/2); // in centimeters
  return distance;
  delay(3000);
}

void servostop(){
  sr1.write(180);
  sr2.write(80);
  sr3.write(125);
  sr4.write(130);
  delay(100);
}

void servoforward(){
  sr1.write(120);
  delay(200);
  sr1.write(180);  
  sr2.write(30);
  delay(200);
  sr2.write(90);  
  sr3.write(100);
  delay(200);
  sr3.write(145); 
  sr4.write(90);
  delay(200);
  sr4.write(150);  
  
}


void setup(){
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    sr1.attach(9);
    sr2.attach(10);
    sr3.attach(11);
    sr4.attach(6);
    sr5.attach(5);    
    Serial.begin(9600);
}

void loop(){
    dist = ultrasonicop();
    Serial.println("Distance : ");
    Serial.println(dist);
    if (dist <= 15.0){
      servostop();
    }
    else {
      servoforward();
    }
}