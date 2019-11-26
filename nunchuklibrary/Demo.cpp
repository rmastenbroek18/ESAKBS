#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600
#include <util/setbaud.h>
#include <usart.h>
#include <Arduino.h>
#include <Wire.h>
//Wire should be above nunchuk.h
#include "Nunchuk.h"
#include <string.h>
#include <avr/interrupt.h>

void setup();
void loop();
void USART_sendchar(unsigned char data);
void USART_sendstring(char data[]);

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
        {
            char up[] = "UP";
            USART_sendstring(up);
        }
        break;
        case DOWN:
        {
            char down[] = "DOWN";
            USART_sendstring(down);
        }
        break;
        case LEFT:
        {
            char left[] = "LEFT";
            USART_sendstring(left);
        }
        break;
        case RIGHT:
        {
            char right[] = "RIGHT";
            USART_sendstring(right);

        }
        break;
        case Z:
        {
            char z[] = "Z";
            USART_sendstring(z);
        }
         break;
        case C:
        {
            char c[] = "C";
            USART_sendstring(c);
            
        }
        break;
      }
      char enter[] = "\n";
      USART_sendstring(enter);
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