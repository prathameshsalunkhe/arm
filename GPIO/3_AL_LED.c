#include <LPC21xx.H>
#include"header.h"
#define LED 7<<17
main()
{
IODIR0=LED;
IOSET0=LED;
while(1)
{
IOCLR0=LED;
delay_ms(500);
IOSET0=LED;
delay_ms(500);
}
}
