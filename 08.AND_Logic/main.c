#include<reg51.h>
sbit Led  = P1^7; 
sbit SwitchA =P0^6;  
sbit SwitchB =P0^7; 
int main(void)
{
    P1  = 0x00; 
    P0 = 0xFF;  
    while(1)
    {
        if(SwitchA == 0 || SwitchB == 0)
        {
            Led =0;  
        }
				 if(SwitchA == 1 || SwitchB == 0)
        {
            Led =0;  
        }
				 if(SwitchA == 0 || SwitchB == 1)
        {
            Led =0;  
        }
         if(SwitchA == 1 || SwitchB == 1)
        {
            Led =1;  
        }
    }

}