int Puerto_Sensor_Humedad = 0; //Analogico A0
int Humedad;
void setup() {
Serial.begin(9600);
}
void loop() {
Humedad = analogRead(Puerto_Sensor_Humedad);
Serial.print("Lectura de Humedad ");
Serial.println( Humedad );
delay(500);

}
