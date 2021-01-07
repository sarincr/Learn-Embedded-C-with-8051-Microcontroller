//LCD Functions Developed by electroSome

//LCD Module Connections
extern bit RS;                                                                   
extern bit EN;                           
extern bit D0;
extern bit D1;
extern bit D2;
extern bit D3;
extern bit D4;
extern bit D5;
extern bit D6;
extern bit D7;
//End LCD Module Connections 


void Lcd_Delay(int a)
{
    int j;
    int i;
    for(i=0;i<a;i++)
    {
        for(j=0;j<100;j++)
        {
        }
    }
}

//LCD 8 Bit Interfacing Functions
void Lcd8_Port(char a)
{
	if(a & 1)
		D0 = 1;
	else 
		D0 = 0;
	
	if(a & 2)
		D1 = 1;
	else
		D1 = 0;
	
	if(a & 4)
		D2 = 1;
	else
		D2 = 0;
	
	if(a & 8)
		D3 = 1;
	else
		D3 = 0;
	
	if(a & 16)
		D4 = 1;
	else
		D4 = 0;

	if(a & 32)
		D5 = 1;
	else
		D5 = 0;
	
	if(a & 64)
		D6 = 1;
	else 
		D6 = 0;
	
	if(a & 128)
		D7 = 1;
	else
		D7 = 0;
}
void Lcd8_Cmd(char a)
{ 
  RS = 0;             // => RS = 0
  Lcd8_Port(a);             //Data transfer
  EN  = 1;             // => E = 1
  Lcd_Delay(5);
  EN  = 0;             // => E = 0
}

Lcd8_Clear()
{
	  Lcd8_Cmd(1);
}

void Lcd8_Set_Cursor(char a, char b)
{
	if(a == 1)
	  Lcd8_Cmd(0x80 + b);
	else if(a == 2)
		Lcd8_Cmd(0xC0 + b);
}

void Lcd8_Init()
{
	Lcd8_Port(0x00);
	RS = 0;
	Lcd_Delay(200);
	///////////// Reset process from datasheet /////////
  Lcd8_Cmd(0x30);
	Lcd_Delay(50);
  Lcd8_Cmd(0x30);
	Lcd_Delay(110);
  Lcd8_Cmd(0x30);
  /////////////////////////////////////////////////////
  Lcd8_Cmd(0x38);    //function set
  Lcd8_Cmd(0x0C);    //display on,cursor off,blink off
  Lcd8_Cmd(0x01);    //clear display
  Lcd8_Cmd(0x06);    //entry mode, set increment
}

void Lcd8_Write_Char(char a)
{
   RS = 1;             // => RS = 1
   Lcd8_Port(a);             //Data transfer
   EN  = 1;             // => E = 1
   Lcd_Delay(5);
   EN  = 0;             // => E = 04
}

void Lcd8_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 Lcd8_Write_Char(a[i]);
}

void Lcd8_Shift_Right()
{
	Lcd8_Cmd(0x1C);
}

void Lcd8_Shift_Left()
{
	Lcd8_Cmd(0x18);
}
//End LCD 8 Bit Interfacing Functions

//LCD 4 Bit Interfacing Functions

void Lcd4_Port(char a)
{
	if(a & 1)
		D4 = 1;
	else 
		D4 = 0;
	
	if(a & 2)
		D5 = 1;
	else
		D5 = 0;
	
	if(a & 4)
		D6 = 1;
	else
		D6 = 0;
	
	if(a & 8)
		D7 = 1;
	else
		D7 = 0;
}
void Lcd4_Cmd(char a)
{ 
	RS = 0;             // => RS = 0
	Lcd4_Port(a);
	EN  = 1;             // => E = 1
  Lcd_Delay(5);
  EN  = 0;             // => E = 0
}

Lcd4_Clear()
{
	Lcd4_Cmd(0);
	Lcd4_Cmd(1);
}

void Lcd4_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
	  temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		Lcd4_Cmd(z);
		Lcd4_Cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		Lcd4_Cmd(z);
		Lcd4_Cmd(y);
	}
}

void Lcd4_Init()
{
	Lcd4_Port(0x00);
	Lcd_Delay(200);
	///////////// Reset process from datasheet /////////
  Lcd4_Cmd(0x03);
	Lcd_Delay(50);
  Lcd4_Cmd(0x03);
	Lcd_Delay(110);
  Lcd4_Cmd(0x03);
  /////////////////////////////////////////////////////
  Lcd4_Cmd(0x02);    
	Lcd4_Cmd(0x02);
  Lcd4_Cmd(0x08); 	
	Lcd4_Cmd(0x00); 
	Lcd4_Cmd(0x0C);     
  Lcd4_Cmd(0x00);    
  Lcd4_Cmd(0x06);   
}

void Lcd4_Write_Char(char a)
{
   char temp,y;
   temp = a&0x0F; 
   y = a&0xF0;	
	 RS = 1;             // => RS = 1
   Lcd4_Port(y>>4);             //Data transfer
	 EN = 1;
	 Lcd_Delay(5);
	 EN = 0;
	 Lcd4_Port(temp);
	 EN = 1;
	 Lcd_Delay(5);
	 EN = 0;
}

void Lcd4_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 Lcd4_Write_Char(a[i]);
}

void Lcd4_Shift_Right()
{
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x0C);
}

void Lcd4_Shift_Left()
{
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x08);
}
//End LCD 4 Bit Interfacing Functions
