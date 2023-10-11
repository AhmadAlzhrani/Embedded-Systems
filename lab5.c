#include "mbed.h"

//Experiment 4: Analog Input and Output 
int main()
{
    //POWER UP 
    LPC_SC -> PCONP |= (1 << 12);
    // pin number p20 
    LPC_PINCON -> PINSEL3 |= (1<<30) | (1<<31); //adc 0.5
    LPC_ADC->ADCR |= (1<<5) | (1<<21) | (1<<16)| (1<<8);
    int x;

    LPC_GPIO1 -> FIODIR |= (1<<23) | (1<<21)| (1<<20)| (1<<18);
    while (true) {
        x = (LPC_ADC->ADDR5 >>4)& 0xFFFF;
        if(x>3500){
            LPC_GPIO1 -> FIOPIN = (1<<23);
        }
        else if(x>3000){
            LPC_GPIO1 -> FIOPIN = (1<<21);
        }
        else if(x>2000){
            LPC_GPIO1 -> FIOPIN = (1<<20);
        }
        else {
            LPC_GPIO1 -> FIOPIN = (1<<18);
        }

    }
}
