#ifndef Level_h
#define Level_h

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

typedef enum {
  EMPTY,    //0  //Empty grid
  WALL,    //1  //Indistructable
  PLAYER1, //2  //Player1
  PLAYER2, //3 //Player2
  BARREL,//4  //Destructable
  BOMB  //5  //BOMB
} Object;

class Level
{
    public:
        Level(int gridformaat);
        void createLevel(Adafruit_ILI9341 tft);
        void createBackground(Adafruit_ILI9341 tft);
        void createObject(int y, int x, Object ob, uint16_t color, Adafruit_ILI9341 tft);
        //Should be the same as _gridhoogte & _gridbreedte
        Object grid[12][16];
    private:
        uint8_t _gridformaat= 20;
        uint8_t _gridhoogte = 12;
        uint8_t _gridbreedte = 16;
};

#endif