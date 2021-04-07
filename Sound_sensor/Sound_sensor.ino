#include <Adafruit_NeoPixel.h>
#define LED_PIN 12
#define NUM_LEDS 5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int buttonInt = 0;

int outPin = 2;
int gndPin = 3;
int vccPin = 4;

void setup() {
 Serial.begin (9600);
  pinMode(12, OUTPUT);
  pinMode(outPin, INPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(vccPin, OUTPUT);
  digitalWrite(gndPin, LOW);
  digitalWrite(vccPin, HIGH);
  strip.setBrightness(32);
  strip.show();
  attachInterrupt(buttonInt, swap, RISING);
}

void swap(){
  if (digitalRead(outPin)){

  Serial.println("outPin=1");
  for (byte i = 0; i < 5; i++)
  {
    strip.setPixelColor(i, 255, 0, 0);
  }
  strip.show();
  }
}

void loop() {
   for (byte i = 0; i < 5; i++)
  {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
      delay(200);
}
