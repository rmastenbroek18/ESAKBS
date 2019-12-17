#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600   // nodig voor twi_setFrequency
#include <util/setbaud.h>
#include <Arduino.h>
#include <Wire.h>

// including libraries
#include <Level.h>
#include <Nunchuk_lib.h>
#include <player.h>

//GAME SCREEN
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// initializing objects here
Nunchuk_lib nunchuk = Nunchuk_lib();
Player player1 = Player(1);
Player player2 = Player(2);
uint8_t nunchuk_value;

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
    nunchuk_value = nunchuk.nunchuk_update();
    if(nunchuk_value == LEFT || nunchuk_value == RIGHT || nunchuk_value == UP || nunchuk_value == DOWN){
        if(!level.check_collision(player1.getYPos(),player1.getXPos(),nunchuk_value)){
            level.createObject(player1.getYPos(),player1.getXPos(), EMPTY, tft);
            player1.move(nunchuk_value);
            level.createObject(player1.getYPos(),player1.getXPos(), PLAYER1, tft);

        }
    }
}
