#include <LPC21xx.H>
#include"header.h"
main()
{
int i,n;
IODIR0=0xFF;
IOSET0=0xFF;
while(1)
{
for(i=1,n=1;i<256 ;i+=n)
{
IOCLR0=i;
delay_ms(200);
IOSET0=i;
delay_ms(200);
n*=2;
}
}
}