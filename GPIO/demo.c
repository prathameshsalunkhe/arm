		#include <LPC21xx.H>
#include"header.h"
main()
{
	int i,j;
	IODIR0=0xFF;
	IOSET0=0xFF;
	while(1)
	{	

		for(i=1,j=128;i<j;i*=2,j/=2)
		{
			IOSET0=i ;
			IOSET0=j;
			delay_ms(400);
		}
		for(i=8,j=16;j<=128;i/=2,j*=2)
		{
			IOCLR0=i;
			IOCLR0=j;
			delay_ms(400);
		} 
	}
}
