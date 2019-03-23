#include "LEDDriver.h"
#include "Keypad.h"

CRGB leds[NUM_LEDS];
CRGB lastLEDsState[NUM_LEDS];

int R = 0; 
int G = 0;
int B = 0;

int microphoneRead = 0;

void initializeLEDs(CRGB []);
void saveLastLEDsState(CRGB []);

void setupLEDStrip() {

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  

  initializeLEDs(lastLEDsState);
  saveLastLEDsState(lastLEDsState);
  delay(1000);
  
  pinMode(MICROPHONE_PIN, INPUT);
}

void initializeLEDs(CRGB lastLEDsState[]) {

  randomSeed(analogRead(0));

  for(int i = 0; i < NUM_LEDS; ++i) {

    R = random(255);
    G = random(255);
    B = random(255);

    leds[i] = CRGB(R, G, B);

    FastLED.show();
   
   delay(10);
  }   
}

void saveLastLEDsState(CRGB lastLEDsState[]){

  for(int i = 0; i < NUM_LEDS; ++i) {

    lastLEDsState[i] = leds[i];
  }
}

char getUsersChoice() {

  const int ROWS = 4;
  const int COLUMNS = 4;

  char keys[ROWS][COLUMNS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
  };

  byte rowPins[ROWS] = {3, 5, 7, 8};
  byte columnPins[COLUMNS] = {9 ,10, 11, 12};
  Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, ROWS, COLUMNS);

  char usersChoice = 0;

  do {
    
  usersChoice = keypad.getKey();
  
  } while(usersChoice == 0);

  return usersChoice;  
}

void makeEffect(CRGB []);
void reset();

void standardMode() {

  for( ; ;) {

    microphoneRead = digitalRead(MICROPHONE_PIN);    
 
    if(microphoneRead == LOW){

      makeEffect(lastLEDsState);
      saveLastLEDsState(lastLEDsState);

      delay(10);
 }
 else {

  reset();     
 }
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
  
  R = random(255);
  G = random(255);
  B = random(255);

  leds[0] = CRGB(R, G, B);
  
  FastLED.show();
  
}

void reset() {

  for(int i = 0; i < NUM_LEDS; ++i) {

    leds[i] = CRGB(0, 0, 0);
  }

  FastLED.show();
}

void normalMode() {

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

void volumeStrengthEffect();

void makeVolume() {

  while(true) {

    microphoneRead = digitalRead(MICROPHONE_PIN);    
    if(microphoneRead == LOW){
  
    volumeStrengthEffect();
    delay(25); 
   
   } else {

    reset();
    delay(25);     
  }
  }
  
 }
 
void volumeStrengthEffect() {

  randomSeed(analogRead(0));
  int randomVolume = random(15);  

  for(int i = NUM_LEDS/2; i < NUM_LEDS/2 + randomVolume; ++i) {

  randomSeed(analogRead(0));
  
  R = random(255);
  G = random(255);
  B = random(255);

  leds[i] = CRGB(R, G, B);
  leds[NUM_LEDS/2 - (i - NUM_LEDS/2)] = leds[i];

  }

  FastLED.show();
}

void spectrumMove();

void makeSpectrum() {

  for(int i = 0; i < NUM_LEDS / 5; ++i) {

    leds[i] = CRGB(255, 0, 0);    
  }
  
  for(int i = NUM_LEDS / 5; i < NUM_LEDS * 0.4; ++i) {

    leds[i] = CRGB(0, 255, 0);    
  }
  
  for(int i = NUM_LEDS * 0.4; i < NUM_LEDS * 0.6; ++i) {

    leds[i] = CRGB(0, 0, 255);    
  }
  
  for(int i = NUM_LEDS * 0.6; i < NUM_LEDS * 0.8; ++i) {

    leds[i] = CRGB(255, 255, 255);    
  }
  
  for(int i = NUM_LEDS * 0.8; i < NUM_LEDS; ++i) {

    leds[i] = CRGB(255, 255, 0);
  }

  FastLED.show();

  for( ; ;) {

    delay(5000);
    spectrumMove();
  }
}

void spectrumMove() {

  CRGB lastColor[6];
  int j = 0;

  for(int i = NUM_LEDS * 0.8; i < NUM_LEDS; ++i){

     lastColor[j++] = leds[i];
  }
  for(int i = NUM_LEDS - 1; i >= NUM_LEDS / 5; --i) {

    leds[i] = leds[i - 6];
    
  }

  for(int i = 0; i < NUM_LEDS / 5; ++i) {

    leds[i] = lastColor[i];
  }

  FastLED.show();
}

void makeOneColor();

void oneColor() {

  for ( ; ;) {

    microphoneRead = digitalRead(MICROPHONE_PIN);    
    
    if(microphoneRead == LOW){

      makeOneColor();
      delay(25);
    }
    else {

      reset();
      delay(25);
     
  } 
  }  
}

void makeOneColor() {

  randomSeed(analogRead(0));

  R = random(255);
  G = random(255);
  B = random(255);

  for(int i = 0; i < NUM_LEDS; ++i) {

    randomSeed(analogRead(0));

    leds[i] = CRGB(R, G, B);
  }

  FastLED.show();
}

void oneColorEasy() {

  for( ; ;) {

    microphoneRead = digitalRead(MICROPHONE_PIN);    
    
    if(microphoneRead == LOW){

      makeOneColor();
      delay(50);
 }
  }
}

void getNewPixelAndMove();

void movingEffect() {

    for( ; ;) {

      microphoneRead = digitalRead(MICROPHONE_PIN);    
    
      if(microphoneRead == LOW){

        getNewPixelAndMove();      
      }
    }
}

void getNewPixelAndMove() {

    randomSeed(analogRead(0));
    
    R = random(255);
    G = random(255);
    B = random(255);

    for (int i = NUM_LEDS - 1; i > 0; --i) {

      leds[i] = leds[i - 1];
    }

    leds[0] = CRGB(R, G, B);

    FastLED.show();
	
  }
