#include <Servo.h>

int led=6;
int i=0;  

void setup() {
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  

}

void loop() 
{
  //Analogwrite aceota un valor de 0 a 255----
  for(i=0;i<256;i++)
  {
     analogWrite(led, i );
     delay(80);
     Serial.println(i);

  }
  
  
  for(i=255;i>1;i--)
  {
      analogWrite(led, i );
      delay(100);
      Serial.println(i);
  }
  

}




