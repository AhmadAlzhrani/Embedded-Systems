#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

int main()
{   
    //TO CHANGE THE DRIECTION OF P0.16 OUTPUT
    LPC_GPIO0 -> FIODIR |= 1<<16;
    //MAKE THE PIN LOW 
    LPC_GPIO0 -> FIOCLR |= 1<<16;
    //MISO0
    LPC_PINCON-> PINSEL1 |= 1<<3;
    //MOSI0
    LPC_PINCON-> PINSEL1 |= 1<<5;
    //CLK (U FOR OVERFLOW) p0.15
    LPC_PINCON-> PINSEL0 |= 1U<<31;


    //CR0 CONFIG (sending 8 bits)
    LPC_SSP0 -> CR0 |= (1<<0)| (1<<1)| (1<<2)| (1<<6)| (1<<7);
    //CR1 CONFIG
    LPC_SSP0 -> CR1 |= (1<<1);

    // send: //

    // SEND TO ADDERSS 0X2D THE VALUE 0X08
    LPC_SSP0 -> DR = 0X2D;

    //checking if they are send or not (1 means busy, 0 idle)
    while(LPC_SSP0 -> SR & (1<<4)) {}

    // acces the reg to clear the unwanted data coming from the device to the DR 
    int d;
    d = LPC_SSP0 -> DR;

    // data to send to the device
    LPC_SSP0 -> DR = 0X08;

    //
    while(LPC_SSP0 -> SR & (1<<4)) {}
    d = LPC_SSP0 -> DR;

    //MAKE THE PIN HIGH
    LPC_GPIO0 -> FIOSET |= 1<<16;




    //receive //

    // x value  lest sig 8 bits 
    LPC_SSP0 -> DR = 0XB2;

    //checking if they are send or not (1 means busy, 0 idle)
    while(LPC_SSP0 -> SR & (1<<4)) {}

    // acces the reg to clear the unwanted data coming from the device to the DR 
    d = LPC_SSP0 -> DR;

    // send any data to recive the clean ones
    LPC_SSP0 -> DR = 0X00;

    d = LPC_SSP0 -> DR;

    int x1 = d;

    // x value  most significant 2 bits
    LPC_SSP0 -> DR = 0XB3;

    //checking if they are send or not (1 means busy, 0 idle)
    while(LPC_SSP0 -> SR & (1<<4)) {}

    // acces the reg to clear the unwanted data coming from the device to the DR 
    d = LPC_SSP0 -> DR;

    // send any data to recive the clean ones
    LPC_SSP0 -> DR = 0X00;

    d = LPC_SSP0 -> DR;

    int x2 = d;

    while (true) {
    //concainate both the 2 bits and 8 bits 
    x1 = x1 & 0xff;
    x2 = x2 & 0x300;
    int x = x1 | x2;
    printf("%d ",x);
    wait_us(500000);
    }
}
