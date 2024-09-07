#include<reg51.h>
void lcd_init(void);

void writecmd(int);

void writedata(char);

void delay(int);

sbit RS=P1^0;

sbit E=P1^1;

sbit led=P1^2;

inti=0;
void main()
{
	P0=0x00; //kullanmadigimiz portlari kapattik
	P1=0x00;
	P2=0x00;
	P3=0x00;
	led=1;
	lcd_init();
	writedata('W');
	//delay(5000000);
	writedata('e');
	//delay(5000000);
	writedata('l');
	//delay(5000000);
	writedata('c');
	//delay(5000000);
	writedata('o');
	//delay(5000000);
	writedata('m');
	//delay(5000000);
	writedata('e');
	//delay(5000000);	
	
	delay(50000000000);
	writedata(' ');
	delay(5000000);
	writedata('T');
	delay(5000000);
	writedata('o');
	delay(5000000);
	writecmd(0x01); //ekrani temizle
	
	writedata('B');
	writedata('a');
	writedata('n');
	writedata('d');
	writedata('i');
	writedata('r');
	writedata('m');
	writedata('a');
	writecmd(0xc0);
	
	writedata('U');
	writedata('n');
	writedata('i');
	writedata('v');
	writedata('e');
	writedata('r');
	writedata('s');
	writedata('i');
	writedata('t');
	writedata('y');
	delay(5000000);
	delay(5000000);
	delay(5000000);
	delay(5000000);
	delay(5000000);
	delay(5000000);
	delay(5000000);
	delay(5000000);
	
}

void lcd_init(void)
{
	writecmd(0x38); //8 bit komutu
	writecmd(0x0C);//ekrani on-of
	writecmd(0x01);//ekrani temizle
	writecmd(0x80);//force cursor to beginnig of lst line
}
void writedata(char t) //data function 
{
	RS=1; // 1 ise veri -0 olsaydi komut olucakti
	P2=t; //data transfer
	E=1; //enable
	delay(150); //bekletme-gecikme
	E=0; //enable
	delay(150);
}

void writecmd(int z)
{
	RS=0; //0 oldugu için komut
	P2=z; //data transfer
	E=1; //enable
	delay(150); //bekletme-gecikme
	E=0; //enable
	delay(150);
}
void delay(int a)
{
	int i;
	for(i=0;i<a;i++); //bekletmek için
}


