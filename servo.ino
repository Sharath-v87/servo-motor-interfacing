#include <Servo.h>
int pos=0;
Servo mykek;
void setup(){
  mykek.attach(9);
}


void loop(){
  for(pos=0; pos<=180; pos++){
    mykek.write(pos);
    delay(20);
  }
  for(pos=180; pos>=0; pos--){
    mykek.write(pos);
    delay(20);
  }
}