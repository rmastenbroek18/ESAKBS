#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <Arduino.h>
#include <Wire.h>
//Wire should be above nunchuk.h
#include <Nunchuk_lib.h>
#include <Nunchuk.h>


Nunchuk_lib::Nunchuk_lib(){
  nunchuk_setup();
}

void Nunchuk_lib::nunchuk_setup () {

    Wire.begin();

    //Change TWI speed for nunchuk, which uses Fast-TWI (400kHz)
    Wire.setClock(400000);

    //nunchuk_init_power(); //A1 and A2 is power supply
    nunchuk_init();
}

uint8_t Nunchuk_lib::nunchuk_update() {
    if (nunchuk_read()) {
      uint16_t control = nunchuk_print();
      switch(control)
      {
        case UP:
        {
          return 0xC4;
        }
        break;
        case DOWN:
        {
          return 0xC8;
        }
        break;
        case LEFT:
        {
          return 0xD0;
        }
        break;
        case RIGHT:
        {
          return 0xE0;
        }
        break;
        case Z:
        {
          return 0xD6;
        }
         break;
        case C:
        {
          return 0xEA;
        }
        break;
      }
    }
}
