#include <Servo.h>
Servo sr;
Servo sr2;
int Vrx=A0;
int Vry=A1;
int X=0;
int Y=0;
int xpos=0;
int ypos=0;

void setup() {
  pinMode(Vrx, INPUT);
  pinMode(Vry, INPUT);
  sr.attach(6);
  sr2.attach(3);
  Serial.begin(9600);
}

void loop() {
  X = analogRead(Vrx);
  Y = analogRead(Vry);
  xpos = map(X, 0, 1023, 0, 180);
  ypos = map(Y, 0, 1023, 0, 180);
  Serial.println(xpos);
  Serial.println(ypos);
  sr.write(xpos);
  sr2.write(ypos);
  delay(400);
}
