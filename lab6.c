#include "mbed.h"

//Experiment 5: digital to analog  Input and Output 
int main()
{
    // pin number p18 
    LPC_PINCON -> PINSEL1 |= (0<<20) | (1<<21); //DCA 0.5

// for timer next time
    // LPC_TIM0 -> TC = 1;

    while (true) {
        LPC_DAC->DACR |= (1000<<8);
        wait_us(1000);
    }
}
