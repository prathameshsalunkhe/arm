#include <LPC21xx.H>
#include"header.h"
main()
{
	int i;
	IODIR0=0x07;
	while(1)
	{	
		for(i=1;i<8;i++)
		{
			IOCLR0=i;
			delay_ms(200);
			IOSET0=i;
			delay_ms(200);
		}
	}
}
