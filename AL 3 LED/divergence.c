#include <LPC21xx.H>
#include"header.h"
main()
{
	int i,j;
	IODIR0=0xFF;
	while(1)
	{
		for(i=3,j=4;j<=7;i--,j++)
		{
			IOCLR0=1<<i | 1<<j;
			delay_ms(200);
			IOSET0=1<<i | 1<<j;
			delay_ms(200);
		}
	}
}
