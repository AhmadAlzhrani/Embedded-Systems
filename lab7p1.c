#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

extern "C"{
void TIMER0_IRQHandler() {
    // LPC_GPIOINT-> IO2IntClr;   //Clear at the beginning
    // to reset counter 
    LPC_TIM0 -> IR |= 1;
    // to put 1 in the led and keep turnig it on and off
    LPC_GPIO1 -> FIOPIN ^= (1<<23);

    }
}

int main()
{
    //task: creating an interupt in oreder to blink the led with timer 
    
    NVIC_EnableIRQ(TIMER0_IRQn);
    // LPC_GPIOINT-> IO2IntEnR;
    // to enble the counter 
    LPC_TIM0 -> TCR |= 01 ;
    // using match register 2
    LPC_TIM0 -> MR2 =20000000;
    // BY looking at table 430 you can see that MCR related to MR2 iscontroled by putting 1 in bit 6 and 7 
    //so if you want to use for instance MR0 you have to put 1 in bit 0 and 1 in MCR T control IT 
    LPC_TIM0 -> MCR =(1<<7) | (1<<6);
    //for direction
    LPC_GPIO1 -> FIODIR |= 1<<23;

    while (true) {
    }
}

