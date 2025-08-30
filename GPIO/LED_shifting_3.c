#include <LPC21xx.H>
#include"header.h"
main()
{
int i,n;
IODIR0=7;
IOSET0=7;
while(1)
{
for(i=4,n=2;n>=0;)
{
IOCLR0=i;
delay_ms(200);
IOSET0=i;
delay_ms(200);
i+=n;
n--;
}
}
}
