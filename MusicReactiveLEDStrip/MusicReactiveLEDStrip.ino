#include "FastLED.h"
#include "Keypad.h"

#define NUM_LEDS 30
#define ROWS 4
#define COLUMNS 4

enum choices {musicReactive = 49, constRGB, blinking}; 

char keys[ROWS][COLUMNS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {3, 5, 7, 8};
byte columnPins[COLUMNS] = {9 ,10, 11, 12};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, ROWS, COLUMNS);

CRGB leds[NUM_LEDS];
CRGB lastLEDsState[NUM_LEDS];

int randNumberR = 0;
int randNumberG = 0;
int randNumberB = 0;
int microRead = 0;

char key = 0;

#define DATAPIN 4
#define MICROPHONEPIN 6

void setup() {

  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL, DATAPIN>(leds, NUM_LEDS);

  initializeLEDs(lastLEDsState);
  saveLastLEDsState(lastLEDsState);
  delay(1000);
  
  pinMode(MICROPHONEPIN, INPUT);

  do {
    
  key = keypad.getKey();
  
  } while(key == 0);

  switch(key){

    case musicReactive: {
      
      loop();
      break;
    }
    case constRGB: {

      standard();
      break;
    }
    case blinking: {

      blinkingLEDs();
      break;
    }
  }
}

void loop() {

 microRead = digitalRead(MICROPHONEPIN);
    
    
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

void standard() {

  for(; ;) {
  makeEffect(lastLEDsState);
  saveLastLEDsState(lastLEDsState);
  delay(150);
  }
  
}

void blinkingLEDs() {
 for(; ;) {
  makeEffect(lastLEDsState);
  saveLastLEDsState(lastLEDsState);

  delay(100);

  reset();

  delay(100);
 }
}
