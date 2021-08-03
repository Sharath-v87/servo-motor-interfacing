#include <Servo.h>
int RM1 = 7;
int RM2 = 6;
int LM1 = 8;
int LM2 = 9;
int trig = 11;
int echo = 12;
Servo sensor;
float dist;
int angles[] = {0,180};
float avg;
float temp;
float distavg;

float ultrasonicop(){
  int time;
  float distance;
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


void forward(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW); 
}

void backward(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH); 
}

void right(){
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW); 
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH); 
}

void left(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH); 
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}

void stop(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW); 
}

void setup(){
    pinMode(LM1, OUTPUT);
    pinMode(LM2, OUTPUT);
    pinMode(RM1, OUTPUT);
    pinMode(RM2, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    sensor.attach(5);
    Serial.begin(9600);
}

void loop(){
    float tot = 0;
    for(int i=0; i<30; i++){
      dist=ultrasonicop();
      tot += dist;
    }
    distavg = tot/30;
    Serial.println(distavg);    
    if(distavg > 30.0){
        forward();
    }
    else {
        stop();
        Serial.println("stopped");
        delay(1000);
        int flag=0;
        for(int i=0; i<2; i++){
            sensor.write(angles[i]);
            delay(1000);
            float detectop=0;
            for(int j=0; j<20; j++){
                temp = ultrasonicop();
                detectop += temp;
            }
            avg=detectop/20;
            if(avg >= 30.0 && i==0){
                for (int i=0; i<130; i++){
                    right();
                    Serial.println("rig");              
                }    
                stop();
                flag = 1;
                delay(2000);
                break;
            }
            else if(avg >= 30.0 && i == 1){
                for (int i=0; i<130; i++){
                    left();
                    Serial.println("left");
                }    
                stop();     
                flag = 2;
                delay(2000);   
                break;
            }
            delay(300);  
        }
        if(flag !=1 && flag !=2){
            for (int i=0; i<200; i++){
                backward();
                Serial.println("back");
            }    
            stop();    
            delay(2000);    
        }
        sensor.write(100);
    }
  delay(400);    
 }