#include <LPC21xx.H>
#include"header.h"
#define LED 1<<3
#define SW ((IOPIN0>>15)&1)
main()
{
	int c=0;
	IODIR0=LED;
	while(1)
	{
		if(SW==0)
		{
			while(SW==0);
			c++;
		}
		if(c>=59)
		c=0;
	}
}
