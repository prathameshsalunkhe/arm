#include <LPC21xx.H>
#include"header.h"
int main()
{
	unsigned int adc_val;
	float vout;
	adc_init();
	uart0_init(9600);
	uart0_tx_string("ADC Testing");
	while(1)
	{
		adc_val=adc_read(2);
		vout=(adc_val*3.3)/1023;
		uart0_integer(adc_val);
		uart0_tx_string("\r\n");
	//	uart0_tx(" ");
		uart0_float(vout);
		uart0_tx_string("\r\n");
		delay_ms(100);
	}
}
