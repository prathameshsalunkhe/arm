#include <LPC21xx.H>
#include"header.h"
main()
{
	int i;
	IODIR0=7;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			IOCLR0=1<<i;
			delay_ms(300);
			IOSET0=1<<i;
			delay_ms(300);
		}
	}
}
