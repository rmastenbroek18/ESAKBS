#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600
#include <util/setbaud.h>
#include <Arduino.h>
#include <Wire.h>

//GAME SCREEN
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#include <Level.h>

Level level(20);

int main (void)
{
    tft.begin();
    //SETUP
    setup();
    //LOOP
    while(1) {
        loop();
    }
    //NEVER REACHED
    return(0);
}

void setup() {
    Wire.begin();
    tft.begin();
    level.createBackground(tft);
    level.createLevel(tft);
}

void loop() {
}
