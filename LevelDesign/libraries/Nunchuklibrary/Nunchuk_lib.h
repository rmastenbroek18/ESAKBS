#ifndef Nunchuk_lib_h
#define Nunchuk_lib_h

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <Arduino.h>
#include <Wire.h>
#include <Nunchuk.h>
#include <Level.h>

class Nunchuk_lib
{
    public:
        Nunchuk_lib(void);
        void nunchuk_setup(void);
        uint8_t nunchuk_update(void);
};

#endif
