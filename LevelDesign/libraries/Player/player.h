#ifndef Player_h
#define Player_h
#include <stdint.h>

// for player 1(x = 1,y = 1), for player 2(x = 13 ,y = 9)

class Player
{
    public:
        Player(uint8_t playerNO);
        void move(uint8_t nunchuk_data);
        uint16_t getXPos();
        uint16_t getYPos();
        uint8_t die(void);
        uint8_t getFacing(void);

    private:
        uint16_t lives = 1;
        uint16_t xPos = 1;
        uint16_t yPos = 1;
        uint8_t facing = 0xC4;

};

#endif