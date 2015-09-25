
float temperatura = 0; //variable para la temperatura
int fan = 8; //pin digital dodne conectar el ventildor
void setup(){

 Serial.begin (9600); //inicia comunicacion serial

 pinMode(8,OUTPUT);//configuracion del pin 8
}
 
void loop(){

  digitalWrite(8,HIGH);
  delay(20000);
  digitalWrite(8,LOW);
  delay(10000);


}

