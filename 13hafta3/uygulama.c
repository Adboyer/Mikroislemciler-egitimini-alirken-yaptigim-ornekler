//p1 in tiklanmasini p0 da sayma
#include<reg52.h>
sbit BUTTON0=P1^0;
sbit BUTTON1=P1^1;
sbit BUTTON2=P1^2;
sbit BUTTON3=P1^3;

bit getButton0()
{
	if(!BUTTON0)
	{
		while(!BUTTON0);
		return 1;
	}
	return 0;
}
void main()
{
	unsigned char count =1;
	while(1)
	{
		P0=~count;
		if(getButton0())
			count++;
	}
}