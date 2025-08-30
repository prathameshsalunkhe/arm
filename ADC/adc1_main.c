#include <LPC21xx.H>
#include"header1.h"
int main()
{
	unsigned int adc_val;
	float Vout,TA;
	char a[30];
	uart1_init(9600);
	adc_init();
	uart1_tx_string("Testing Inbuilt ADC\r\n");
	while(1)
	{
		adc_val=adc_read(2);
		Vout=(adc_val*3.3)/1023;

		TA=(Vout-0.05)/0.01;
		sprintf(a,"ADC=%d vtg=%.2f temp=%.2f",adc_val,Vout,TA);

		uart1_tx_string(a);
		uart1_tx_string("\r\n");
		delay_ms(200);
	}
}
