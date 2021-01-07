#include<reg52.h>
#include<stdio.h>

void delay(int);

void main()
{
 do
 {
   P2=0x01; //0001
   delay(1000);
   P2=0x03; //0011
   delay(1000);
   P2=0x02; //0010
   delay(1000);
   P2=0x06; //0110
   delay(1000);
   P2=0x04; //0100
   delay(1000);
   P2=0x0C; //1100
   delay(1000);
   P2=0x08; //1000
   delay(1000);
   P2=0x09; //1001
   delay(1000);
 } while(1);
} 

void delay(int k)
{ 
int i,j; 
for(i=0;i<k;i++) 
 { 
  for(j=0;j<100;j++)
  {}
 } 
}