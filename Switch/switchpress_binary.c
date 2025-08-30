#include <LPC21xx.H>
#include"header.h"
#define SW ((IOPIN0>>14)&1)
main()
{
	int c=0,i;
	IODIR0=7;
	IOSET0=7;
	while(1)
	{
		if(SW==0)
		{
			while(SW==0);
			c++;
			i=c;
			IOCLR0=i;
			delay_ms(200);
			IOSET0=i;
			delay_ms(200);
		}
		if(c==7)
		c=0;
	}
}
