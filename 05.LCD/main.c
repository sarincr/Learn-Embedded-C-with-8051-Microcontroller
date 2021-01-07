#include<reg52.h>							 
#include<lcd.h>

sbit RS = P0^0;                                                                   
sbit EN = P0^1;                            
sbit D4 = P2^4;
sbit D5 = P2^5;
sbit D6 = P2^6;
sbit D7 = P2^7;

void main()
{
	int i;
	Lcd4_init();
	Lcd4_Set_Cursor(1,1);
	Lcd4_Clear();
	Lcd4_Write_Char('S');
}




