#include<reg51.h>
sbit a=P3^0;
sbit b=P3^1;
void display(unsigned int);
void delay();
unsigned int ds1,ds2;
unsigned char n[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0xE00,0x10};

void main()
{
unsigned int i;
	ds1=ds2=0;
	a=b=1;
	while(1)
	{
		for(i=0;i<20;i++)
		{
			display1(i);
		}
	}
}
void display1(unsigned int j)
{
	if(j<10)
	{
		P2=n[ds1];
		P0=n[ds2];
		delay();
		ds1++;
	}
	else
	{
		P2=n[ds2];
		P0=n[1];
		delay();
		ds2++;
		if(ds2>=10)
		{
			ds1=ds2=0;
		}
	}
}
void delay()
{
unsigned int k;
	for(k=0;k<45000;k++);
}