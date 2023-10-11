#include "mbed.h"
int x; 
// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
 extern "C" {
    void EINT3_IRQHandler(){
        // clr
        LPC_GPIOINT-> IO2IntClr |= (1<<5);
        //
       
        LPC_GPIO1 -> FIOSET |= 1<<23;
        wait_us(500000);
        LPC_GPIO1 -> FIOCLR |= 1<<23;

        LPC_GPIO1 -> FIOSET |= 1<<21;
        wait_us(500000);
        LPC_GPIO1 -> FIOCLR |= 1<<21;

        LPC_GPIO1 -> FIOSET |= 1<<20;
        wait_us(500000);
        LPC_GPIO1 -> FIOCLR |= 1<<20;

        LPC_GPIO1 -> FIOSET |= 1<<18;
        wait_us(500000);
        LPC_GPIO1 -> FIOCLR |= 1<<18;

    }
}

int main()
{ 
    LPC_GPIO1 -> FIODIR |= 1<<23;
    LPC_GPIO1 -> FIODIR |= 1<<21;
    LPC_GPIO1 -> FIODIR |= 1<<20;
    LPC_GPIO1 -> FIODIR |= 1<<18;

        LPC_GPIOINT-> IO2IntEnR |= (1<<5);
        NVIC_EnableIRQ(EINT3_IRQn);

        while(true){
    }
}
