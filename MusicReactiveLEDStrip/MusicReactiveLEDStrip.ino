#include "FastLED.h"

#define NUM_LEDS 30

CRGB leds[NUM_LEDS];
CRGB lastLEDsState[NUM_LEDS];

int randNumberR = 0;
int randNumberG = 0;
int randNumberB = 0;
int microRead = 0;

#define DATAPIN 4
#define MICROPHONEPIN 6

void setup() {

  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL, DATAPIN>(leds, NUM_LEDS);

  initializeLEDs(lastLEDsState);
  saveLastLEDsState(lastLEDsState);
  delay(1000);
  
  pinMode(MICROPHONEPIN, INPUT);
}

void loop() {

 microRead = digitalRead(MICROPHONEPIN);
 Serial.println(microRead);
 
 if(microRead == LOW){
  
    makeEffect(lastLEDsState);
    saveLastLEDsState(lastLEDsState);

   delay(25);
 }
 else {

 reset();
 delay(25);
 
 }

}

void makeEffect(CRGB lastLEDsState[]) {

  randomSeed(analogRead(0));

 for(int i = 0; i < NUM_LEDS; ++i) {

  leds[i] = lastLEDsState[i];
 }
 
 for(int j = NUM_LEDS - 1; j > 0; --j) {

    leds[j] = leds[j-1];
  }
  FastLED.show();
  
  randNumberR = random(20);
  randNumberG = random(20);
  randNumberB = random(20);

  leds[0] = CRGB(randNumberR, randNumberG, randNumberB);
  
  FastLED.show();
  
}

void reset() {

  for(int i = 0; i < NUM_LEDS; ++i) {

    leds[i] = CRGB(0, 0, 0);
  }

  FastLED.show();
}

void saveLastLEDsState(CRGB lastLEDsState[]){

  for(int i = 0; i < NUM_LEDS; ++i) {

    lastLEDsState[i] = leds[i];
  }
}

void initializeLEDs(CRGB lastLEDsState[]) {

  randomSeed(analogRead(0));

  for(int i = 0; i < NUM_LEDS; ++i) {

    randNumberR = random(20);
    randNumberG = random(20);
    randNumberB = random(20);

    leds[i] = CRGB(randNumberR, randNumberG, randNumberB);

     FastLED.show();
	 
	 delay(10);
  } 
  
}
