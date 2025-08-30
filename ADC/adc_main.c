#include <LPC21xx.H>
#include"header.h"
int main()
{
	unsigned int adc_val;
	adc_init();
	uart0_init(9600);
	while(1)
	{
		adc_val=adc_read(1);
		uart0_integer(adc_val);
		uart0_tx_string("\r\n");
		delay_ms(200);
	}
}
