#include <LPC21xx.H>
#include"header.h"
main()
{
int i,n;
IODIR0=7;
IOSET0=7;
while(1)
{
for(i=0;i<3;i++)
{
IOCLR0=1<<i;
delay_ms(200);
IOSET0=1<<i;
delay_ms(200);
}
}
}

