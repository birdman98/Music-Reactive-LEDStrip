# Music-Reactive-LEDStrip

A simple example of using FastLED library to make music reactive LED strip with Arduino. 
In future project will be upgraded with better sound sensor. 

## Getting Started

To make your own music reactive LED strip you need:
 * **WS2812B Programmable LED Strip**
 * **Arduino board** - you can use for instance Arduino Nano or Arduino Uno
 * [FastLED Arduino Library](https://github.com/FastLED/FastLED) - great library to control programmable LEDs from FastLED team
 * **Sound Sensor** - I'm using sound sensor with digital output, but I recommend to use sensor with both digital and analog output.
 
 **Important**! <br />
 If you are going to use LED Strip which power consumption is bigger than 500 mA you need to use additional power supply.
 
 ## Assembling
 
 In my project I'm currently using 1 meter WS2812B LED Strip and not using it's maximum brightness, so It can be connected directly to
 my Arduino. In future strip will be powered by an additional 5V power supply. All you need to do to start using my code on your arduino is
 connect DATA_IN PIN from WS2812B LED Strip to Arduino's D4 pin, VCC pin from strip to Arduino's VIN and GND from strip with Arduino's GND.
 Moreover you have to connect your sound sensor - VCC to +5V, GND to GND and DOUT to Arduino's D6 pin.
 
 
 
 ## Author
 * [Piotr Matras](github.com/birdman98)
