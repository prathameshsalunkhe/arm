#include <LPC21xx.H>
#include"header.h"
main()
{
int i,n;
IODIR0=0xFF;
IOSET0=0xFF;
while(1)
{
for(i=7;i>=0;i--)
{
IOCLR0=1<<i;
delay_ms(200);
IOSET0=1<<i;
delay_ms(200);
}
}
}
