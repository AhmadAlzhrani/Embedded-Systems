#include "mbed.h"
// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
int main()
{

        while(true){
                int x =LPC_GPIO1 -> FIOPIN;
                x = x>>31; 
                int aaa = x & 1;
                if(aaa == 0){
                    LPC_GPIO1 -> FIODIR |= 1<<23;
                    LPC_GPIO1 -> FIOSET |= 1<<23;
                    // wait_us(1000000);
                    // LPC_GPIO1 -> FIOCLR |= 1<<23;
                    // wait_us(1000000);
        }
                else{
                    LPC_GPIO1 -> FIOCLR |= 1<<23;
                }
    }
}
