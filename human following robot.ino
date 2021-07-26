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
int angles[] = {0,90,180};

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

void servobackward(){
  sr1.write(180);
  delay(200);
  sr1.write(120);  
  sr2.write(90);
  delay(200);
  sr2.write(30);  
  sr3.write(145);
  delay(200);
  sr3.write(100); 
  sr4.write(150);
  delay(200);
  sr4.write(90);  

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

void servoright(){
  sr1.write(120);
  delay(200);
  sr1.write(180);  
  sr2.write(90);
  delay(200);
  sr2.write(30);  
  sr3.write(100);
  delay(200);
  sr3.write(145); 
  sr4.write(150);
  delay(200);
  sr4.write(90);  
}

void servoleft(){
  sr1.write(180);
  delay(200);
  sr1.write(120);  
  sr2.write(30);
  delay(200);
  sr2.write(90);  
  sr3.write(145);
  delay(200);
  sr3.write(100); 
  sr4.write(90);
  delay(200);
  sr4.write(150);  
}

void detect(){
  for(int i=0; i<3; i++){
    sr5.write(angles[i]);
    float detectop = ultrasonicop();
    if(detectop<=40 && angles[i] == 0){
      servostop();
      delay(2000);
      for(int loopa=0; loopa <= 10; loopa++){
        servoleft();
        delay(500);
      }
    }
    else if(detectop<=40 && angles[i] == 180){
      servostop();
      delay(2000);
      for(int loopb=0; loopb <= 10; loopb++){
        servoright();
        delay(500);
      }
    }
    delay(2000);
  }
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
      servobackward();
    }
    else if(dist > 15.0 && dist < 40.0){
      servoforward();
    }
    else{
      detect();
    }
}