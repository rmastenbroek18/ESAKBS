#ifndef Nunchuk_lib_h
#define Nunchuk_lib_h

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <Arduino.h>
#include <Wire.h>
//Wire should be above nunchuk.h
#include <Nunchuk.h>

    static void nunchuk_setup() {

    Wire.begin();

    //Change TWI speed for nunchuk, which uses Fast-TWI (400kHz)
    Wire.setClock(400000);

    //nunchuk_init_power(); //A1 and A2 is power supply
    nunchuk_init();
    }

    static uint8_t nunchuk_update() {
    if (nunchuk_read()) {
      return nunchuk_print();
        }
    }

#endif
