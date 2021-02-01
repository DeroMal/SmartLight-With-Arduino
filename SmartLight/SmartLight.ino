
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //Setting MAC Address for Ethernet Shieldconst int ledPin = 13;

int ledPin = 13;

int ldrPin = A0;

int ldrStatus;

int   State;

char server[] = "10.10.29.106";
IPAddress ip(10, 10, 18, 182);
byte gateway[] = { 10, 10, 24, 1 };
byte subnet[] = { 255, 255, 248, 0 };
String readString;
EthernetClient client;

void setup() {

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  pinMode(ldrPin, INPUT);

  //-------CONNECTING TO NETWORK--------------------
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    int c;
    Ethernet.begin(mac, ip);
  }

}

void loop() {

  ldrStatus = analogRead(ldrPin);
//  GetTimetest();
  light();

  

  delay(1000);

}
///---------------LIGHT CONTROL--------------------
void light(){
  if (ldrStatus >= 30) {
    Serial.println(ldrStatus);
    GetTime();
    
    if (State==1){
      digitalWrite(ledPin, HIGH);
      Serial.print("Its DARK, Turn on the LED : ");
     }
     else{
      digitalWrite(ledPin, LOW);
      Serial.print("Its BRIGHT, Turn on the LED : ");
     }
     
  }
  
  else {

    Serial.println(ldrStatus);
    GetTime();
    
    if (State==0){
      digitalWrite(ledPin, LOW);
      Serial.print("Its BRIGHT, Turn on the LED : ");
     }
     else{
      digitalWrite(ledPin, LOW);
      Serial.print("Its DARK, Turn on the LED : ");
     }
  }
 }

//-------------GET CURRENT TIME-----------------
void GetTime()   //CONNECTING WITH MYSQL
{
  Serial.println();
  Serial.println("Send2");
  Serial.println();
  if (client.connect(server, 80)) {
    Serial.println("Getting_Data_connected");

    // Make a HTTP request
    client.print("GET https://localhost/Tstamp.php?&x=");
//    client.println(ldrStatus);
    client.println(6);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 10.10.18.182");
    client.println("Connection: close");
    client.println();
    updateSerial2();
  }
  else{
    // if you didn't get a connection to the server:
    Serial.println("Getting_Data_connection failed");
  }
  Serial.println();
  Serial.println();
}

//-------------GET CURRENT TIME-----------------
void GetTimetest()   //CONNECTING WITH MYSQL
{
  Serial.println();
  Serial.println("Send2");
  Serial.println();
  if (client.connect(server, 80)) {
    Serial.println("Getting_Data_connected");

    // Make a HTTP request
    client.print("GET https://localhost/test.php?&x=");
//    client.print("&x=");
    client.println(8);
//    client.print(25);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 10.10.18.182");
    client.println("Connection: close");
    client.println();
    Serial.println("sample test");
    updateSerial2();
  }
  else{
    // if you didn't get a connection to the server:
    Serial.println("Getting_Data_connection failed");
  }
  Serial.println();
  Serial.println();
}

//.............................................................................................
float updateSerial2()
{
  Serial.println(".............................Max/Min Set Values.....................................");
  // Receive multiple numeric fields using Arduino 1.0 Stream parsing
  const int NUMBER_OF_FIELDS = 1; // how many comma-separated fields we expect
  int fieldIndex = 0; // the current field being received
  int values[NUMBER_OF_FIELDS]; // array holding values for all the fields
  if ( client.available()) {
    for (fieldIndex = 0; fieldIndex < 1; fieldIndex ++)
    {
      values[fieldIndex] = client.parseInt(); // get a numeric value
    }
    Serial.print( fieldIndex);
    Serial.println(" fields received:");
    for (int i = 0; i < fieldIndex; i++)
    {
      Serial.println(values[i]);
    }
    State = values[0];
    Serial.print("State = ");
    Serial.println(State);
    fieldIndex = 0; // ready to start over
  }
  Serial.println("..................................................................");
}
