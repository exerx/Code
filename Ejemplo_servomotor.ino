#include <Servo.h>

Servo obj_servo;
int i=0;


void setup() {
  
  
  Serial.begin(9600);

  
  obj_servo.attach(2);

}

void loop() {
  

  

  
  for(i=0;i<181;i++)
  {
  
    obj_servo.write(i);
    Serial.println(i);
   delay(10);
    
  }
  for(i=180;i>1;i--)
  {
    
    obj_servo.write(i);
    Serial.println(i);
    delay(10);
  
  }
  
  

}
