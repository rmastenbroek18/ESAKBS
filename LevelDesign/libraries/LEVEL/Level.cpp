#include <Level.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

Level::Level(uint32_t gridformaat)
{
    _gridformaat = gridformaat;
}

void Level::createBackground(Adafruit_ILI9341 tft)
{
      tft.fillScreen(ILI9341_BLACK);//Background
}

void Level::createLevel(Adafruit_ILI9341 tft)
{
  uint8_t valuei = 4;
  for (uint16_t y = 0; y < _gridhoogte; y++) {
    valuei = 4;
    for (uint16_t x = 0; x < _gridbreedte; x++) {   
      //Create Walls
      if (x == 0 || y == 0 || (x >= _gridbreedte - 2) || (y >= _gridhoogte - 2)) {
        createObject(y, x, WALL, ILI9341_DARKGREY, tft);
      }
      else if (x == valuei && (y + 1) % 2) {//Draw internal walls
        createObject(y,x, WALL, ILI9341_DARKGREY, tft);
        if(valuei < 10)
        {
          valuei += 2;
        }
      }
      else if ((y % 2) && (y >= 1) && (y <= 9)) {//Draw boxes
        if (x > 2 && x < 12 && x % 2) {
          createObject(y,x, BARREL, ILI9341_MAROON, tft);
        }
      }
      else {
        grid[y][x] = EMPTY;
      }
    }
  }
}

void Level::createObject(uint16_t y, uint16_t x, Object ob, Adafruit_ILI9341 tft){
  if(ob == EMPTY){
    createObject(y,x,ob,ILI9341_BLACK,tft);
  }else if(ob == PLAYER1){
    createObject(y,x,ob,ILI9341_BLUE,tft);
  }else if(ob == PLAYER2){
    createObject(y,x,ob,ILI9341_GREEN,tft);
  }else if(ob == BOMB){
    createObject(y,x,ob,ILI9341_RED,tft);
  }
}

void Level::createObject(uint16_t y, uint16_t x, Object ob, uint16_t color, Adafruit_ILI9341 tft){
  grid[x][y] = ob;
  uint16_t ypos = y * 20;
  uint16_t xpos = x * 20;
  tft.fillRect(ypos, xpos, 20, 20, color);
}

uint8_t Level::check_collision(uint16_t y, uint16_t x,uint8_t direction){
  if(direction == 0xC4){ // check for UP
    if(grid[x][y+1] == EMPTY){
      return 0;
    }else{
      return 1;
    }
  }else if(direction == 0xC8){ // check for DOWN
    if(grid[x][y-1] == EMPTY){
      return 0;
    }else{
      return 1;
    }
  }else if(direction == 0xD0){ // check for LEFT
    if(grid[x-1][y] == EMPTY){
      return 0;
    }else{
      return 1;
    }
  }else if(direction == 0xE0){ // check for RIGHT
    if(grid[x+1][y] == EMPTY){
      return 0;
    }else{
      return 1;
    }
  }else{
    return 1;
  }
}
