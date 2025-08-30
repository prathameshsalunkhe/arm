#include <LPC21xx.H>
#include"header.h"
main()
{
	int i=0;
	IODIR0=0xFF;
	while(1)
	{
		for(i;i<8;i+=2)
		{
			IOCLR0=1<<i;
			delay_ms(200);
			IOSET0=1<<i;
			delay_ms(200);
		}
		if(i%2==0)
		i=1;
		else
		i=0;
	}
}
