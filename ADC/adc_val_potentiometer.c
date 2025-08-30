#include <LPC21xx.H>
#include"header.h"
int main()
{
	unsigned int adc_val;
	uart0_init(9600);
	adc_init();
	uart0_tx_string("\r\nTesting Inbuilt");
	while(1)
	{
		adc_val=adc_read(2);
		uart0_integer(adc_val);
		uart0_tx_string("\r\n");
		delay_ms(200);
	}
}
