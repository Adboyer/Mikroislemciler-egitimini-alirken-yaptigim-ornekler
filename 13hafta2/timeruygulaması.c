//timer uygulamasi

#include<reg52.h>
sbit portbit=P1^0;
void main()
{
	TMOD=0x02;
	TH0=-50;
	TL0=-50;
	TR0=1;
	IE=0X82;
	while(1);
	
}
void timeroISR() interrupt 1
{
portbit = !portbit;
}