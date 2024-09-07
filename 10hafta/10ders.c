
//#include<reg51.h>

//void main()
//{
//	SCON=0X50; //start the serial communication 
//	TMOD=0X20; //selected the timer mode
//	TH1=3; //load the baud rate
//	TR1=1; //timer on
//	P0=SBUF; //send the data from sbuf to port0
//	while(RI==0); //check the interrupt register 
//	RI=0;
//	TR1=0; //of the timer 
//	while(1);//stop the program when character is received
//		
//	
//}



//-----------------------------------------
//seri haberlesme 
//'S' karakterini seri pencereye iletin baud hizi olarak 9600 kullanin
//void main()
//{
//	SCON=0x50;
//	TMOD=0X20;
//	TH1=3;
//	TR1=1;
//	SBUF='A';
//	while(TI==0);
//	TI=0;
//	TR1=0;
//	while(1);
//	
//}









//-----------------------------------------------------------//
//void main()
//{
//	unsigned char i; //
//	TMOD=0X20; //SET THE TIMER mode
//	for(i=0;i<2;i++) //double the time delay
//	{
//		TL1=0X19; //set the time delay
//		TH1=0X00;
//		TR1=1; //timer on
//		while(TF1==0); //check the flag bit
//		TF1=0;
//	
//	}
//	TR1=0; //timer of
//}




//------------------------------------------------------------------------------------------
////7-segment uygulamasi diger uygulama ile birlestirme

//sbit a=P3^0;
//sbit b=P3^1;
//sbit c=P3^2;
//sbit d=P3^3;
//void main()
//{

//unsigned char n[10]={0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x010};
//unsigned int i,j;
//a=b=c=d=1;
//while(1)
//{
//	for(i=0;i<10;i++)
//	{
//		P=2=n[i];
//		for(j=0;j<60000;j++);
//	}
//}
//}







//------------------------------------------------
//kayan led uygulamasi
void main()
{
	unsigned i,j,b;
	while(1)
	{
		P0=0x01;
		b=P0;
		for(j=0;j<10000;j++);
		for(i=0;i<8;i++)
		{
			b=b<<1;
			P0=b;
			for(j=0;j<10000;j++);
		}
	}
}







//----------------------------------------------------
////BEKLETMELI LED YAKMA 
//void main()
//{
//unsigned int i;
//	while (1)
//	{
//		P0=0x55;
//		for(i=0;i<300;i++)
//			{
//			}
//			P0=0xAA;
//		for(i=0;i<300;i++)
//			{
//			}
//	}
//}