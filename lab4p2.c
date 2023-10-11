#include "mbed.h"
int x; 
int y;
// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
 extern "C" {
    void EINT3_IRQHandler(){
        // clr
        LPC_GPIOINT-> IO2IntClr |= (1<<5);
        LPC_GPIOINT-> IO0IntClr |= (1<<11);
        //
        int stat;
        int stat2;
        stat = LPC_GPIOINT -> IO2IntStatR;
        stat2 =LPC_GPIOINT -> IO0IntStatR;
        if(stat){
        x = x>>5; 

        int aaa = x & 1;
               
        if(aaa == 0){
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


        else{
            LPC_GPIO1 -> FIOSET |= 1<<23;
            LPC_GPIO1 -> FIOSET |= 1<<21;
            LPC_GPIO1 -> FIOSET |= 1<<20;
            LPC_GPIO1 -> FIOSET |= 1<<18;

        }
        }else if(stat2){
            LPC_GPIO1 -> FIOSET |= 1<<23;
            LPC_GPIO1 -> FIOSET |= 1<<21;
            LPC_GPIO1 -> FIOSET |= 1<<20;
            LPC_GPIO1 -> FIOSET |= 1<<18;
        }

    }
}

int main()
{ 
    LPC_GPIO1 -> FIODIR |= 1<<23;
    LPC_GPIO1 -> FIODIR |= 1<<21;
    LPC_GPIO1 -> FIODIR |= 1<<20;
    LPC_GPIO1 -> FIODIR |= 1<<18;
        x =LPC_GPIO2 -> FIOPIN;
        y =LPC_GPIO2 -> FIOPIN;
        LPC_GPIOINT-> IO2IntEnR |= (1<<5);
        LPC_GPIOINT-> IO0IntEnR |= (1<<11);

        NVIC_EnableIRQ(EINT3_IRQn);
    
        while(true){

    }
}