#include<reg52.h>  
int i;
sbit LED = P0^0;
void main (void) 
{
    while(1)              
    {
			LED = 0;
			for(i=0;i<30000;i++)
			{
			}
			LED = 1; 
			for(i=0;i<30000;i++)
			{
			}
    }
}

