#include <Adafruit_NeoPixel.h>
#define LED_PIN 12
#define NUM_LEDS 5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int vccPin = 2;
int trigPin = 3;
int echoPin = 4;
int gndPin = 5;

void setup() {
  Serial.begin (9600);
  pinMode(12, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vccPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  digitalWrite(vccPin, HIGH);
  strip.setBrightness(32);
  strip.show();
}

void loop() {
  
  int duration, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 58;


  if (cm>=0){
    for (byte i = 0; i < 5; i++)
  {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
 
  cm = constrain(cm, 0, 50);
  
  Serial.println(cm);
  
  cm = map (cm, 0, 50, 0, 5);
  
  for (byte i = 0; i < cm; i++)
  {
    strip.setPixelColor(i, 0, 255, 0);
  }
  strip.show();
  }
  
  delay(100);
}

