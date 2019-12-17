#include <player.h>

Player::Player(uint8_t playerNO){
    if(playerNO == 1){
        xPos = 1;
        yPos = 1;
    }else if(playerNO == 2){
        xPos = 13;
        yPos = 9;
    }
}

void Player::move(direction direction1){ // moves player location based on input
    switch(direction1)
    {
        case UP:
            yPos++;
            facing = UP;
            break;
        case DOWN:
            yPos--;
            facing = DOWN;
            break;
        case LEFT:
            xPos--;
            facing = LEFT;
            break;
        case RIGHT:
            xPos++;
            facing = RIGHT;
            break;
    }
}

uint8_t Player::die(void){ // return 1 for game over, 0 for lives left == enough
    if(lives < 2){
        return 1;
    }else{
        lives--;
        return 0;
    }
}

direction Player::getFacing(void){
    return facing;
}

uint16_t Player::getYPos(void){ // return y
    return yPos;
}

uint16_t Player::getXpos(void){ // return x
    return xPos;
}

