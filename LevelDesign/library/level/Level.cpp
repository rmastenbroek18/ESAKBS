#include "Level.h"

#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "SPI.h"

Level::Level(int gridformaat)
{
    _gridformaat = gridformaat;
}

void Level::createBackground(Adafruit_ILI9341 tft)
{
      tft.fillScreen(ILI9341_BLACK);//Background
}

void Level::createLevel(Adafruit_ILI9341 tft)
{
  int valuei = 4;
  for (int y = 0; y < _gridhoogte; y++) {
    valuei = 4;
    for (int x = 0; x < _gridbreedte; x++) {   
      //Create Walls
      if (x == 0 || y == 0 || (x >= _gridbreedte - 2) || (y >= _gridhoogte - 2)) {
        createObject(y, x, WALL, ILI9341_DARKGREY, tft);
      }
      else if (x == valuei) {//Draw internal walls
        createObject(y,x, WALL, ILI9341_DARKGREY, tft);
        if(valuei < 8)
        {
          valuei += 2;
        }
      }
      // else if (x == valuei && (y + 1) % 2) {//Draw internal walls
      //   createObject(y,x, WALL, ILI9341_DARKGREY, tft);
      //   if(valuei < 10)
      //   {
      //     valuei += 2;
      //   }
      // }
      // else if ((y % 2) && (y >= 1) && (y <= 9)) {//Draw boxes
      //   if (x > 2 && x < 12 && x % 2) {
      //     createObject(y,x, BARREL, ILI9341_MAROON, tft);
      //   }
      // }
      else {
        grid[y][x] = EMPTY;
      }
    }
  }
}

void Level::createObject(int y, int x, Object ob, uint16_t color, Adafruit_ILI9341 tft){
  grid[x][y] = ob;
  int ypos = y * 20;
  int xpos = x * 20;
  tft.fillRect(ypos, xpos, 20, 20, color);
}
