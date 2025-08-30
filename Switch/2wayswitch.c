#include <LPC21xx.H>
#include"header.h"
#define LED 2
#define SW1 ((IOPIN0>>14)&1)
#define SW2 ((IOPIN0>>15)&1)
main()
{
	int i=0;
	IODIR0=2;
	while(1)
	{
	if(SW1==0)
	{
		while(SW1==0);
		i=!i;
	}
	if(SW2==0)
	{
		while(SW2==0);
		i=!i;
	}
	if(i==0)
		IOCLR0=LED;
	else
		IOSET0=LED;
	}
}


