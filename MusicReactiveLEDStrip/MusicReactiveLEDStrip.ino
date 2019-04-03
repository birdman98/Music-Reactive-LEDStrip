#include "LEDDriver.h"

enum choices {standard = 49, regularRGB, blinking, volumeStrength, spectrum, reactiveOneColor, oneColorSoft, moving, deskLamp}; 

void setup() {

  setupLEDStrip();

  char key = getUsersChoice();
  
  switch(key){

    case standard: {
      
      standardMode();
      break;
    }
    case regularRGB: {

      normalMode();
      break;
    }
    case blinking: {

      blinkingLEDs();
      break;
    }
    case volumeStrength: {

      makeVolume();
      break;
    }
    case spectrum: {

      makeSpectrum();
      break;
      
    }
    case reactiveOneColor: {

      oneColor();  
      break;
    }
    case oneColorSoft: {

      oneColorEasy();
      break;
    }

    case moving: {

      movingEffect();
      break;
    }

    case deskLamp: {

      whiteLamp();
      break;
    }
  }
  
}

void loop() {}
