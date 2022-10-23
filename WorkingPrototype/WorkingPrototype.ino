#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#define USE_SERIAL Serial

WiFiMulti wifiMulti;

#define TRIG_PIN 33 // ESP32 pin GIOP35 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 34 // ESP32 pin GIOP33 connected to Ultrasonic Sensor's ECHO pin
#define LED_PIN  18 // LED pin set on/off based on water level
#define SDA_PIN 21 // SDA pin for LCD
#define SCL_PIN 22 // SCL pin for LCD


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

float duration_us, distance_cm,Water_level;

void setup() {
  // begin serial port
  Serial.begin (115200); 

  // initialize the lcd 
  lcd.init();                       
  lcd.clear();
  lcd.backlight();

  // configure the trigger pin to output mode
  pinMode(TRIG_PIN, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);
  // configure the echo pin to input mode
  pinMode(LED_PIN, OUTPUT);


     for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
  
  }

  wifiMulti.addAP("GS10","ftel3849");
}
void loop() {  
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;


  Water_level = 10.8-distance_cm;
  if (Water_level<=2){
    digitalWrite(LED_PIN,HIGH);
  }
 
  else if (Water_level>=8){
    digitalWrite(LED_PIN,LOW);
  }

  lcd.setCursor(0,0);
  lcd.print("Water Level");
  lcd.setCursor(0,1);
  lcd.print(Water_level); 
  lcd.setCursor(7,1);
  lcd.print("cm");
  
  Serial.print("Water level: ");
  Serial.print(Water_level);
  Serial.println(" cm");

  if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        Serial.print("[HTTP] begin...\n");
        // configure traged server and url
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        http.begin("http://192.168.213.165/IoT/Project_uche.php?Water_level="+String(Water_level)); //HTTP
  
        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();
        //Serial.printf("[HTTP] GET... code: %d\n", httpCode);
        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                //Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }
  
  delay(1500);
}
