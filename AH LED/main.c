#include <LPC21xx.H>
#include"header.h"
main()
{
IODIR0=1;
while(1)
{
IOSET0=1;
delay_ms(200);
IOCLR0=1;
delay_ms(200);
}
}
