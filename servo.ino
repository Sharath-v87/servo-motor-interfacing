#include <Servo.h>
int pos=0;
Servo mykek;
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
  mykek.write(90);
  delay(100);
}

void servoforward(){
  mykek.write(0);
  delay(400);
  mykek.write(180);
  delay(400);
  mykek.write(180);
  delay(400);
  mykek.write(0);  
  delay(400);
  // mykek.write(90);
  // delay(400);
}

void setup(){
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    mykek.attach(9);
    Serial.begin(9600);
}

void loop(){
    dist = ultrasonicop();
    Serial.println("Distance : ");
    Serial.println(dist);
    if (dist <= 30.0){
      servostop();
    }
    else{
      servoforward();
    }

}