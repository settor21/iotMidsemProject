#include <LiquidCrystal_I2C.h>

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

  // configure the trigger pin to output mode
  pinMode(TRIG_PIN, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);
  // configure the echo pin to input mode
  pinMode(LED_PIN, OUTPUT);

  lcd.init();                      // initialize the lcd 
  lcd.clear();
  lcd.backlight();
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

  
  
  delay(1500);
}
