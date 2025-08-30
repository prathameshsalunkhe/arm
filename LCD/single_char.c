#include <LPC21xx.H>
#include"header.h"
main()
{
//	IODIR0=0x7FF;
//	IOCLR0=0x7FF;
//	IOSET0='A';
//	IOSET0=1<<8;
//	IOCLR0=1<<9;
//	IOSET0=1<<10;
//	delay_ms(200);
//	IOCLR0=1<<10;
 lcd_init();
lcd_data('R');
}


