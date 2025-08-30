#include <LPC21xx.H>
#include"header.h"
int main(){

	unsigned int temp;

	uart0_init(9600);

	spi0_init();

	uart0_tx_string("mcp3204\r\n");

	while(1){

		temp=mcp3204_read(2);
		  //temp=15;
		uart0_integer(temp);

		//uart0_integer(12);

		uart0_tx_string("\r\n");//new line
		delay_sec(1);

	}

}
