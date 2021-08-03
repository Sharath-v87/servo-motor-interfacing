#include <Servo.h>
Servo sr;
int Vrx=A0;
int Vry=A1;
int X=0;
int Y=0;
int xpos=0;
int ypos=0;

void setup() {
  pinMode(Vrx, INPUT);
  pinMode(Vry, INPUT);
  sr.attach(A6);
  Serial.begin(9600);
}

void loop() {
  X = analogRead(Vrx);
  Y = analogRead(Vry);
  xpos = map(X, 0, 1023, 0, 180);
  ypos = map(Y, 0, 1023, 0,50);
  Serial.println(xpos);
  Serial.println(ypos);
  sr.write(xpos);
  delay(400);
}
