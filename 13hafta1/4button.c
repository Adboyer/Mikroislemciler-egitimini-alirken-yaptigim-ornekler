//her hangi bir buttona basildiginda ledlerin durumunu degistirin
#include<reg51.h>

sbit BUTTON0=P2^0;
sbit BUTTON1=P2^1;
sbit BUTTON2=P2^2;
sbit BUTTON3=P2^3;

unsigned char getNumButtons()
{
	unsigned char result=0;
	if(!BUTTON0)
		result++;
	if(!BUTTON1)
		result++;
	if(!BUTTON2)
		result++;
	if(!BUTTON3)
		result++;
	return result;
}
void main ()
{
	unsigned char lights=0xFF;
	P0=lights;
	while(1)
	{
		if(getNumButtons()>0)
		{
			while(getNumButtons() !=0);
			lights=~lights;
			P0=lights;
		}
	}
}