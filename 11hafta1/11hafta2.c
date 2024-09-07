#include<REGX51.H>

void cct_init(void);
void SerialInitilaze(void);
void uart_msg(unsigned char *c);
void uart_tx(unsigned char);
sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;



void main()
{
	cct_init();
	SerialInitilaze();
	EA=1;
	ES=1;
	uart_msg("Initializing Serial Communication");
	uart_tx(0x0d);
	uart_msg("1,2,3,4 girilince led ve a,b,c,dd kapanip açilicak");
	uart_tx(0x0d);
	uart_msg("ledi yakmak için karakter giriniz");
	uart_tx(0x0d);
	while(1);
}

void cct_init(void)
{
	P0=0x00; //portlari kapat
	P1=0x00;
	P2=0x00;
	P3=0x03;
}


void SerialInitilaze(void)
{
	TMOD=0x20; //mod 1 mi 2 mi 
	SCON=0x50; //serial mode 1 , 8-data
	TH1=0xFD; //boud rate 9600
	TR1=1; //timer baslat
}

void uart_msg(unsigned char *c)
{
		while (*c !=0){ uart_tx(*c++);}
//	while(*c !=0)
//	{
//	uart_tx(*c++);
//	}
}
	
void uart_tx(unsigned char serialdata)
{
	SBUF=serialdata;
	while(TI==0);
	TI=0;
}
void serial_ISR(void) interrupt 4
{
	char chr;
	if(RI==1)
	{
		chr=SBUF;
		RI=0;
	}
	P0=~P0;
	switch(chr)
	{		
		case '1': led1=1;uart_msg("1st on"); uart_tx(0x0d); break;
		case '2': led2=1;uart_msg("2nd on"); uart_tx(0x0d); break;
		case '3': led3=1;uart_msg("3rd on"); uart_tx(0x0d); break;
		case '4': led4=1;uart_msg("4th on"); uart_tx(0x0d); break;
		case 'a': led1=0;uart_msg("1st off"); uart_tx(0x0d); break;
		case 'b': led2=0;uart_msg("2nd off"); uart_tx(0x0d); break;
		case 'c': led3=0;uart_msg("3rd off"); uart_tx(0x0d); break;
		case 'd': led4=0;uart_msg("4th off"); uart_tx(0x0d); break;
	default: ; break;
	}
	RI=0;
}
