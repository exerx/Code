
int umbral = 500;
int volume;
 
void setup() {                
  Serial.begin(9600);  
}
 
void loop() {
  
  volume = analogRead(A0); 

  if(volume>=umbral){
    Serial.println("Niño despierto");
  }  

 
}
