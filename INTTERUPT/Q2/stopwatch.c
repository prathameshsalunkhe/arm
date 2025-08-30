#include <LPC21xx.H>
#include"header.h"
unsigned int count;
int main()
{
	uart0_init(9600);
	uart0_tx_string("Stopwatch Testing\r\n");
	config_for_eint0();
	config_eint0();
	while(1)
	{
		count++;
	}
}
