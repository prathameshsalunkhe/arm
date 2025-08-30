#include <LPC21xx.H>
#include"header.h"
main()
{
	int i,j,n,m;
	IODIR0=0xFF;
	IOSET0=0xFF;
	while(1)
	{	

		for(i=1,j=128,n=1,m=128;i<16;i+=n,j+=m)
		{
			IOCLR0=i | j;
			delay_ms(200);
			IOSET0=i | j;
			delay_ms(200);
			n*=2;
			m/=2;
		}
		for(i=7,j=224,n=4,m=32;i>=0; )
		{
			IOCLR0=i | j;
			delay_ms(200);
			IOSET0=i | j;
			delay_ms(200);
			i-=n;
			n/=2;
			j-=m;
			m*=2;
		} 
	}
}
