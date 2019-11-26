#include <Wire.h>
// Wire library should be above Nunchuk.h
#include "Nunchuk.h"
#include <util/delay.h>
#define BAUD 9600
#include <util/setbaud.h>
#include <usart.h>
#include <Arduino.h>
#include <string.h>

void setup();
void loop();

int main(void) {
    setup();
    while(1){
        loop();
    }
}

void setup () {
    Serial.begin(9600);

    USART_Init();

    Wire.begin();

    //Change TWI speed for nunchuk, which uses Fast-TWI (400kHz)
    Wire.setClock(400000);

    //nunchuk_init_power(); //A1 and A2 is power supply
    nunchuk_init();
}

void loop() {
    if (nunchuk_read()) {
      int control = nunchuk_print();
      switch(control)
      {
        case UP:
            USART_sendstring("UP");
            break;
        case DOWN:
            USART_sendstring("DOWN");
            break;
        case LEFT:
            USART_sendstring("LEFT");
            break;
        case RIGHT:
            USART_sendstring("RIGHT");
            break;
        case Z:
            USART_sendchar("Z");
            break;
        case C:
            USART_sendchar("C"):
            break;
      }
      USART_sendchar("\n");
    }
    delay(100);
}

void USART_sendchar(unsigned char data){
    //while the transmit buffer is not empty loop
    while(!(UCSR0A & (1<<UDRE0)));
    //when the buffer is empty write data
    UDR0=data;
}

void USART_sendstring(char data[]){
    int n = strlen(data);
    for(int i=0; i<n; i++){
        USART_sendchar(data[i]);
    }
}