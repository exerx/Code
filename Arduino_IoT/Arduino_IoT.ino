

   #include <SPI.h>
   #include <Ethernet.h>

   // Enter a MAC address for your controller below.
   // Newer Ethernet shields have a MAC address printed on a sticker on the shield
   byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };


   // Initialize the Ethernet client library
   // with the IP address and port of the server
   // that you want to connect to (port 80 is default for HTTP):
   EthernetClient client;

   String idvariable = "YourIDVariable";
   String token = "Yourtoken";


   void setup() {
    // Open serial communications and wait for port to open:
     Serial.begin(9600);
     while (!Serial) {
       ; // wait for serial port to connect. Needed for Leonardo only
     }

     // start the Ethernet connection:
     if (Ethernet.begin(mac) == 0) {
       Serial.println("Failed to configure Ethernet using DHCP");
       // no point in carrying on, so do nothing forevermore:
       for(;;);
     }
     // give the Ethernet shield a second to initialize:
     delay(1000);
     Serial.println("connecting...");
   }

   void loop()
   {
     int value = analogRead(A0);
     save_value(String(value));
   }

   void save_value(String value)
   {
     // if you get a connection, report back via serial:
     int num=0;
     String var = "{\"value\":"+ String(value) + "}";
     num = var.length();
     delay(2000);
     if(client.connect("things.ubidots.com", 80))
     {
       Serial.println("connected");

       // New lines according to ubidots support:

       client.println("POST /api/v1.6/variables/"+idvariable+"/values HTTP/1.1");
       Serial.println("POST /api/v1.6/variables/"+idvariable+"/values HTTP/1.1");
       client.println("Content-Type: application/json");
       Serial.println("Content-Type: application/json");
       client.println("Content-Length: "+String(num));
       Serial.println("Content-Length: "+String(num));
       client.println("X-Auth-Token: "+token);
       Serial.println("X-Auth-Token: "+token);
       client.println("Host: things.ubidots.com\n");
       Serial.println("Host: things.ubidots.com\n");
       client.print(var);
       Serial.print(var+"\n");
     }
     else
     {
       // if you didn't get a connection to the server:
       Serial.println("connection failed");
     }

     if (!client.connected())
     {
       Serial.println();
       Serial.println("disconnecting.");
       client.stop();
     }

     if (client.available())
     {
       char c = client.read();
       Serial.print(c);
     }
     // client.stop(); // Add this line to make sure you don't leave the socket open...only case you are experiencing problems when posting data several times.
   }
