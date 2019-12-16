/**
 * @license Nunchuk Arduino library v0.0.1 16/12/2016
 * http://www.xarg.org/2016/12/arduino-nunchuk-library/
 *
 * Copyright (c) 2016, Robert Eisele (robert@xarg.org)
 * Dual licensed under the MIT or GPL Version 2 licenses.
 **/

enum Buttons {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    Z,
    C,
    IDLE
};

// Calibration joystick values
#define NUNCHUK_JOYSTICK_X_ZERO 128
#define NUNCHUK_JOYSTICK_Y_ZERO 128
#define NUNCHUK_RADIUS 100

// The Nunchuk I2C address
#define NUNCHUK_ADDRESS 0x52

#define I2C_READ() Wire.read()
#define I2C_WRITE(x) Wire.write(x)

#define I2C_START(x) Wire.beginTransmission(x)
#define I2C_STOP() Wire.endTransmission(true)

uint8_t nunchuk_data[6];

/**
 * Initializes the Nunchuk communication by sending a sequence of bytes
 */
static void nunchuk_init() {
    I2C_START(NUNCHUK_ADDRESS);
    I2C_WRITE(0xF0);
    I2C_WRITE(0x55);
    I2C_STOP();

    I2C_START(NUNCHUK_ADDRESS);
    I2C_WRITE(0xFB);
    I2C_WRITE(0x00);
    I2C_STOP();
}

/**
 * Decodes a byte if encryption is used
 *
 * @param x The byte to be decoded
 */
static inline uint8_t nunchuk_decode_byte(uint8_t x) {
    return x;
}

/**
 * Central function to read a full chunk of data from Nunchuk
 *
 * @return A boolean if the data transfer was successful
 */
static uint8_t nunchuk_read() {

    uint8_t i;
    Wire.requestFrom(NUNCHUK_ADDRESS, 6);

    for (i = 0; i < 6 && Wire.available(); i++) {
        nunchuk_data[i] = nunchuk_decode_byte(I2C_READ());
    }
    I2C_START(NUNCHUK_ADDRESS);
    I2C_WRITE(0x00);

    I2C_STOP();
    return i == 6;
}

/**
 * Checks the current state of button Z
 */
static uint8_t nunchuk_buttonZ() {
    return (~nunchuk_data[5] >> 0) & 1;
}

/**
 * Checks the current state of button C
 */
static uint8_t nunchuk_buttonC() {
    return (~nunchuk_data[5] >> 1) & 1;
}

/**
 * Retrieves the calibrated X-value of the joystick
 */
static int16_t nunchuk_joystickX() {
    return (int16_t) nunchuk_data[0] - (int16_t) NUNCHUK_JOYSTICK_X_ZERO;
}

/**
 * Retrieves the calibrated Y-value of the joystick
 */
static int16_t nunchuk_joystickY() {
    return (int16_t) nunchuk_data[1] - (int16_t) NUNCHUK_JOYSTICK_Y_ZERO;
}

/**
 * A handy function to print either verbose information of the Nunchuk or a CSV stream for Processing
 */
enum Buttons nunchuk_print() {
    if(nunchuk_joystickX() < -NUNCHUK_RADIUS && nunchuk_joystickY() > -NUNCHUK_RADIUS && nunchuk_joystickY() < NUNCHUK_RADIUS){
        //Serial.print("LEFT \n");
        return LEFT;
    }
    else if(nunchuk_joystickY() < -NUNCHUK_RADIUS && nunchuk_joystickX() > -NUNCHUK_RADIUS && nunchuk_joystickX() < NUNCHUK_RADIUS){
        //Serial.print("DOWN \n");
        return DOWN;
    }
    else if(nunchuk_joystickX() > NUNCHUK_RADIUS && nunchuk_joystickY() > -NUNCHUK_RADIUS && nunchuk_joystickY() < NUNCHUK_RADIUS){
        //Serial.print("RIGHT \n");
        return RIGHT;
    }
    else if(nunchuk_joystickY() > NUNCHUK_RADIUS && nunchuk_joystickX() > -NUNCHUK_RADIUS && nunchuk_joystickX() < NUNCHUK_RADIUS){
        //Serial.print("UP \n");
        return UP;
    }
    else if(nunchuk_buttonC() == 1){
        //Serial.print("C \n");
        return C;
    }
    else if(nunchuk_buttonZ() == 1){
        //Serial.print("Z \n");
        return Z;
    }
    else {
        return IDLE;
    }
}
