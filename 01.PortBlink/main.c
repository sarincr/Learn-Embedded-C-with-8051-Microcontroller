#include<reg52.h>           // special function register declarations
                            // for the intended 8051 derivative

sbit LED = P2^0;            // Defining LED pin

void Delay(void);           // Function prototype declaration

void main (void)
{
    while(1)                // infinite loop
    {
        LED = 0;            // LED ON
        Delay();
        LED = 1;            // LED OFF
        Delay();
    }
}

void Delay(void)
{
    int j;
    int i;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10000;j++)
        {
        }
    }
}