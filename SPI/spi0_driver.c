#include <LPC21xx.H>
#include"header.h"
void spi0_init()
{
	IODIR0=(1<<7);    //p0.7 o/p direction
	IOSET0=(1<<7);    //cso=1;
	PINSEL0|=0x1500;  // set P0.4->SCK0,P0.5->MISO0,P0.6->MOSI0
	S0SPCR=0X20;      // CPOL=CPHA=0, Master Mode
	S0SPCCR=15;       // spi freq is 1Mbps
}

// spi transfer function //

#define SPIF ((S0SPSR>>7)&1)
unsigned char spi0(unsigned char data)
{
	S0SPDR=data;     //data from M-->S
	while(SPIF==0);	 //waiting for spi transfer to complete
	return S0SPDR;	 //data from S-->M
}
