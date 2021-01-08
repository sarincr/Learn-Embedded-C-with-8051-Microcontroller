#include<reg52.h>
sbit button=P0^0;  
sbit led=P1^0;     

void main()
{
	P1=0x01; 
	while(1)
		{
		if(button==1)
		{
			led=1; 
		}
		else
		{
			led=0;
		}
		}
}