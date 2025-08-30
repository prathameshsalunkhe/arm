#include <LPC21xx.H>
#include"header.h"
#define DONE (ADDR>>31)&1
void adc_init(void)
{
	PINSEL1=0x15400000;
	ADCR=0x00200400;
}

unsigned int adc_read(unsigned char ch_num)
{
	unsigned int r;
	ADCR|=(1<<ch_num);
	ADCR|=(1<<24);
	while(DONE==0);
	ADCR^=(1<<24);
	ADCR^=(1<<ch_num);
	r=(ADDR>>6)&0x3ff;
	return r;
}

int main()
{
	unsigned int adc_val;
	float Vout;
	uart0_init(9600);
	adc_init();
	uart0_tx_string("Testing Inbuilt ADC\r\n");
	while(1)
	{
		adc_val=adc_read(1);
		Vout=((float)adc_val*3.3)/1023;
		uart0_integer(adc_val);
		uart0_tx_string("\r\n");
		uart0_float(Vout);
		uart0_tx_string("\r\n");
		delay_ms(100);
	}
}
				