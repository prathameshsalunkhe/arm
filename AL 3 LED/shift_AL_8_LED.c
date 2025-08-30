#include <LPC21xx.H>
#include"header.h"
main()
{
	int i;
	IODIR0=0xFF;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			IOCLR0=1<<i;
			delay_ms(200);
			IOSET0=1<<i;
			delay_ms(200);
		}
		i=0;
	}
}
