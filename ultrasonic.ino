int trig = 3;
int echo = 4;
int time;
float distance;

void setup(){
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    Serial.begin(9600);
}

void loop(){
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    time = pulseIn(echo,HIGH,30000);
    //Serial.println(time);
    distance = 343*0.00001*(time/2);
    Serial.println("Distance : ");
    Serial.println(distance);
    delay(400);
}