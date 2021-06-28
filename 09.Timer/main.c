
#include <reg51.h> 
sbit LED = P1^0;			 

void Delay() 
{
	TH0 = 0x80;		 
	TL0 = 0x10;		
	TR0 = 1;			
	while(TF0 == 0);	
	TR0 = 0;	 
	TF0 = 0;		 
}
void main()
{
	TMOD = 0x00;	
	while(1)
	{
		LED = ~LED;		
		Delay();
	}
}