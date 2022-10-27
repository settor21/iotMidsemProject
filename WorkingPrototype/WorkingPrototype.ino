/**
 * based on code by Niel Cameron
 * Setup: connect a RED led to pin 21 and a green LED to pin 23
 * YOu may rename your Acess point from ESP32Svr to make it identifiable and uniqe
 * You may change your IP if you wish, but not neccessary.
 * Only difference betwen this an STA version is in the setup of the wireless
 */


#include <WebServer.h>
#include "htmltext.h"

WebServer server(80);
char ssidAP[] = "ESP32AP";
char passwordAP[] = "12345678"; 
IPAddress local_ip(192,168,2,1); 
IPAddress gateway(192,168,2,1); 
IPAddress subnet(255,255,255,0); 


int LEDGpin = 23;
int LEDRpin = 21;

int LEDR = LOW;
int LEDG = LOW;
int counter = 0;
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  delay(1000);
  WiFi.softAP(ssidAP, passwordAP); 
  WiFi.softAPConfig(local_ip, gateway, subnet);  // initialise Wi-Fi 
  server.begin();
  server.on("/", base);
  server.on("/LEDGurl",LEDGfunct);
  server.on("/LEDRurl",LEDRfunct);
  server.on("/zeroUrl",zerofunct);
  server.on("/countUrl",countFunct);  //new optional funciton to always update the counter
  pinMode(LEDGpin, OUTPUT);
  pinMode(LEDRpin, OUTPUT);
}

void base(){
  server.send(200, "text/html", page);
}

void LEDGfunct(){
  LEDG = !LEDG;
  digitalWrite(LEDGpin, LEDG);
  counter++;
  String str = "ON";    //modification below
  if(LEDG == LOW) str = "OFF";
  server.send(200, "text/plain", str);
  Serial.println("green");
}

//modified to use AJAX
void LEDRfunct()
{
  LEDR = !LEDR;
  digitalWrite(LEDRpin, LEDR);
  counter++;
  String str = "ON";    //very little returned
  if(LEDR == LOW) str = "OFF";
  server.send(200, "text/plain", str);
  Serial.println("red");
}

void zerofunct() // function to zero counter
{
  // and send HTML code to client
  counter = 0;
  String str = String(counter);   //only this is sent
  server.send(200, "text/html", str);
  Serial.println("zero");
}

//new optional funciton to always update the counter
void countFunct() {
  String str = String(counter);   //only this is sent
  server.send(200, "text/plain", str);
  Serial.println("counter");
}

void loop() {
  server.handleClient(); // manage HTTP requests 
}