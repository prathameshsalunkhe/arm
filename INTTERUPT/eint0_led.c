#include <LPC21xx.H>
#include"header.h"
unsigned int count;
int main()
{
	unsigned char temp;
	config_eint0();
	config_vic_for_eint0();
	uart0_init(9600);
	uart0_tx_string("Testing Interrupts\r\n");
  while(1)
  {
		count++;
//		temp=uart0_rx();
//		uart0_tx(temp);
	}
}

	