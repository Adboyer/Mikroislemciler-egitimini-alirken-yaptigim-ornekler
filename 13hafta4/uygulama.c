#include<reg52.h>
sbit BUTTON0=P1^0;

const unsigned int DEBOUNCE=6600;
bit getButton0()
{
	unsigned int i=0;
	if(!BUTTON0)
	{
		while(!BUTTON0)
		i++;
		if(i<DEBOUNCE)
		return 0;
		return 1;
			
	}
	return 0;
}
void main()
{
	unsigned char count =1;
	while(1)
		P0=~count;
	if(getButton0())
		count++;	
}