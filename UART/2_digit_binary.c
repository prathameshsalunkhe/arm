#include <LPC21xx.H>
#include"header.h"
int main()
{
	unsigned int first_digit,second_digit,result=0;
	uart0_init(9600);
	while(1)
	{
		uart0_tx_string("\r\nEnter Single Digit Number: ");
		first_digit=uart0_rx();
		uart0_tx(first_digit);

		second_digit=uart0_rx();
		uart0_tx(second_digit);

		if(second_digit!=13)
		{
			result=(first_digit-48)*10+(second_digit-48);
		}
		else
			result=first_digit-48;
		uart0_tx_string("\r\n");
		uart0_binary(result);
	}
}
