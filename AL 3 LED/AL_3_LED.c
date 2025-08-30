#include <LPC21xx.H>
#include"header.h"
#define LED 7<<5
main()
{
	IODIR0=LED;
	while(1)
	{
		IOCLR0=LED;
		delay_ms(200);
		IOSET0=LED;
		delay_ms(200);
	}
}
