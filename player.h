#ifndef player_h
#define player_h

// for player 1(x = 1,y = 1), for player 2(x = 13 ,y = 9)

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} direction;

class player
{
    public:
        void move(direction);
        uint16_t getXpos(void);
        uint16_t getYPos(void);
        uint8_t die(void);
        direction getFacing(void);

    private:
        uint16_t lives = 1;
        uint16_t xPos = 1;
        uint16_t yPos = 1;
        direction facing = UP;

}

#endif