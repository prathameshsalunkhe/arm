#include <LPC21xx.H>
#include"header.h"
main()
{
IODIR0=0xFF;
IOSET0=0xFF;
while(1)
{
int i,j;
for(i=0,j=7;i<j;i++,j--)
{
IOCLR0=1<<i | 1<<j;
delay_ms(200);
IOSET0=1<<i | 1<<j;
delay_ms(200);
}
for(i=2,j=5;j<8;i--,j++)
{
IOCLR0=1<<i | 1<<j;
delay_ms(200);
IOSET0=1<<i | 1<<j;
delay_ms(200);
}
}
}
