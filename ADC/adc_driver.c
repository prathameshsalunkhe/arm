#include <LPC21xx.H>
#include"header.h"
#define DONE ((ADDR>>31)&1)
void adc_init(void)
{
	PINSEL1=0x15400000;
	ADCR=0x00200400;
}

unsigned int adc_read(unsigned char ch_num)
{
	unsigned int temp=0;
	ADCR|=(1<<ch_num);
	ADCR|=(1<<24);
	while(DONE==0);
	ADCR^=(1<<24);
	ADCR^=(1<<ch_num);
	temp=(ADDR>>6)&0x3FF;
	return temp;
}
