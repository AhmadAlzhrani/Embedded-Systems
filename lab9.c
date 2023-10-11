#include "mbed.h"
// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

int main()
{
    LPC_PINCON -> PINSEL3 |= (1<<5) | (0<<4); //PWM1.1
    LPC_PWM1->MR0 = 2000000;
    LPC_PWM1->MR1 = 1000000;

    LPC_PWM1->TCR |= (1<<3)|(1<<0) ;
    LPC_PWM1->PCR |= (1<<9) ;
    while (true) {
    }
}
