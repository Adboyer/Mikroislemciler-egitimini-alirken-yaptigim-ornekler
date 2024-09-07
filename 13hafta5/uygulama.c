#include<reg52.h>
sbit BUTTON0=P1^0;

void startTime0()
{
	TMOD =TMOD &252;
	TMOD++;
	TH0=219;
	TR0=1;
	ET0=1;
	EA=1;
}
void timer0ISR() interrupt 1
{
	TH0=219
}
void sleep()
{
	TH0=219;
	PCON=1;
}
bit getButton0()
{
	unsigned int i=0;
	if(!BUTTON0)
	{
		sleep();
		if(BUTTON0)
			return 0;
		while(!BUTTON0)
			PCON=1;
		return 1;
	}
	return 0;
}
	void main()
	{
		unsigned char count =1;
		startTimer0();
		while(1)
		{
			sleep();
			P0=~count;
			if(getButton0())
			count++;
		}
	}