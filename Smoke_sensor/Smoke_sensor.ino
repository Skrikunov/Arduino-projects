#include <Adafruit_NeoPixel.h>
#define LED_PIN 12
#define NUM_LEDS 5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

#define smokePin A0    // определяем аналоговый выход к которому подключен датчик 
int sensorThres = 250; // пороговое значение АЦП, при котором считаем что газ есть 

void setup() { 
  Serial.begin(9600);   // Устанавливаем скорость порта 9600 бод 
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  strip.setBrightness(32);
  strip.show();
} 

void loop() { 
  int analogSensor = analogRead(smokePin);    // считываем значения АЦП с аналогового входа 
                                              // к которому подключен датчик  
  Serial.print (analogSensor);                // выводим в порт значение АЦП сигнала с датчика 
   
  // Проверяем, достигнуто ли пороговое значение 
  if (analogSensor > sensorThres) {  // если значение больше допустимого... 
    Serial.println(" Gaz!");         // выводим в порт надпись, что газ есть 

    for (byte i = 0; i < 5; i++)
  {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
  } 
  else {                             // иначе... 
   Serial.println(" normal");        // выводим в порт надпись, что газа нет 

     for (byte i = 0; i < 5; i++)
  {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
  } 
  
  delay(300);  // задержка в 300 миллисекунд. 
} 
