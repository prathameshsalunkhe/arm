#include <LPC21xx.H>
#include"header.h"
#define LED 1
#define SW ((IOPIN0>>15)&1)
main()
{
	IODIR0=LED;
	while(1)
	{
	if(SW==0)
	IOCLR0=LED;
	else
	IOSET0=LED;
	}
}
