#include <player.h>

player(uint8_t playerNO){
    if(playerNO == 1){
        xPos = 1;
        yPos = 1;
    }else if(playerNO == 2){
        xPos = 13;
        yPos = 9;
    }
}

void move(direction){ // moves player location based on input
        switch(direction)
        {
        case UP:
            yPos++;
            facing = UP;
            break;
        case DOWN:
            yPos--;
            break;
        case LEFT:
            xPos--;
            break;
        case RIGHT:
            xPos++;
            break;
        }
}

uint8_t die(void){ // return 1 for game over, 0 for lives left == enough
    if(lives < 2){
        return 1;
    }else{
        lives--;
        return 0;
    }
}

direction getFacing(void){
    return facing;
}

uint16_t getYPos(void){ // return y
    return yPos;
}

uint16_t getXpos(void){ // return x
    return xPos;
}

