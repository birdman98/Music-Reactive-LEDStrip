#ifndef LEDDriver
#define LEDDriver

#include "FastLED.h"

const int NUM_LEDS = 30;
const int DATA_PIN =  4;
const int MICROPHONE_PIN = 6;

void setupLEDStrip();
char getUsersChoice();
void standardMode();
void normalMode();
void blinkingLEDs();
void makeVolume();
void makeSpectrum();
void oneColor();
void oneColorEasy();
void movingEffect();  

#endif
