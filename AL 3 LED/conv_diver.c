#include <LPC21xx.H>
#include"header.h"
main()
{
	int i,j;
	IODIR0=0xFF;
	delay_ms(300);
	while(1)
	{
		for(i=0,j=7;i<8;i++,j--)
		{
			IOCLR0=1<<i | 1<<j;
			delay_ms(300);
			IOSET0=1<<i | 1<<j;
			delay_ms(300);
		}
	}
}
