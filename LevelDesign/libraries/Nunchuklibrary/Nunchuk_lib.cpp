#include <Nunchuk_lib.h>

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
      return nunchuk_print();
    }
}
