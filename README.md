# Music-Reactive-LEDStrip

A simple example of using FastLED library to make cool music reactive LED strip with Arduino. 
In future project will be upgraded with OLED display and IR remote control. 

## Getting Started

To make your own music reactive LED strip you need:
 * **WS2812B Programmable LED Strip**
 * **Arduino board** - you can use for instance Arduino Nano or Arduino Uno
 * [FastLED Arduino Library](https://github.com/FastLED/FastLED) - great library to control programmable LEDs from FastLED team
 * [Keypad Arduino Library](https://github.com/Chris--A/Keypad) - cool library to handle input from additional keyboard
 * **Sound Sensor** - I'm using sound sensor with digital output, but I recommend to use sensor with both digital and analog output.
 
 **Important**! <br />
 If you are going to use LED Strip which power consumption is bigger than 500 mA you need to use additional power supply.
 
 ## Assembling
 
 In my project I'm currently using 1 meter WS2812B LED Strip with 5V 3A power supply. Moreover, I'm using small 16 - keys arduino keyboard to choose from a couple of light modes. All you need to do to start using my code on your arduino is to connect DATA_IN PIN from WS2812B LED Strip to Arduino's D4 pin through 300-500 Ohm resistor, VCC pin from strip to Arduino's VIN and GND from strip with Arduino's GND.
Moreover you have to connect your sound sensor - VCC to +5V, GND to GND and DOUT to Arduino's D6 pin.
 
 
 
 ## Author
 * [Piotr Matras](github.com/birdman98)
