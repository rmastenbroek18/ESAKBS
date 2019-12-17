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

void Player::move(uint8_t nunchuk_data){ // moves player location based on input
    facing = nunchuk_data;
    switch(nunchuk_data)
    {
        case 0xC4:
            yPos++;
            break;
        case 0xC8:
            yPos--;
            break;
        case 0xD0:
            xPos--;
            break;
        case 0xE0:
            xPos++;
            break;
        default:
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

uint8_t Player::getFacing(void){
    return facing;
}

uint16_t Player::getYPos(){ // return y
    return yPos;
}

uint16_t Player::getXPos(){ // return x
    return xPos;
}

