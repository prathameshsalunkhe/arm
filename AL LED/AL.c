#include <LPC21xx.H>
#include"header.h"
main()
{
	IODIR0=2;
	while(1)
	{
		IOCLR0=2;
		delay_ms(200);
		IOSET0=2;
		delay_ms(200);
	}
}

