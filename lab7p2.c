#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

int main()
{
    //ENBLE THE TIMER 2 BECOUSE ITS 0 BY DEFOUT 
    LPC_SC -> PCONP |= (1 << 22);

    LPC_PINCON -> PINSEL0 |= (1<<12) | (1<<13); //CONFIG TO mat2.0 (functioality is 11) (8.5.1)    // to enble the counter 

    LPC_TIM2 -> TCR |= 01 ;
    // using match register 2
    LPC_TIM2 -> MR0 =20000000;
    // BY looking at table 430 you can see that MCR related to MR2 iscontroled by putting 1 in bit 6 and 7 
    //so if you want to use for instance MR0 you have to put 1 in bit 0 and 1 in MCR T control IT 
    LPC_TIM2 -> MCR =3;
    //for direction

    //TO TOGGEL MAT2.0
    LPC_TIM2-> EMR |= (1<<5)|(1<<4);

    while (true) {
    }
}

