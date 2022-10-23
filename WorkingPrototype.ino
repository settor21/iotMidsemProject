#define TRIG_PIN 23 // ESP32 pin GIOP23 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 22 // ESP32 pin GIOP22 connected to Ultrasonic Sensor's ECHO pin
#define LED_PIN  18 // LED pin set on/off based on water level
#define SDA_PIN 32 // SDA pin for LCD
#define SCL_PIN 33 // SCL pin for LCD

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
  // print the value to Serial Monitor
  Serial.print("Water level: ");
  Serial.print(Water_level);
  Serial.println(" cm");

  
  delay(1500);
}
