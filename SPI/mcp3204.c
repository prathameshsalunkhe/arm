#include <LPC21xx.H>
#include"header.h"
unsigned int mcp3204_read(unsigned char ch_num)
{

	unsigned int result=0;

	unsigned char byteL=0,byteH=0;

	ch_num<<=6;                    //set ch_num

	IOCLR0=(1<<7);                 //CS0=0

	spi0(0x06);

	byteH=spi0(ch_num);

	byteL=spi0(0x00);

	IOSET0=(1<<7);                 //CS0=1

	byteH&=0x0F;

	result=(byteH<<8)|byteL;

	return result;

}
