#include <LPC21xx.H>
#include"header.h"
main()
{
lcd_init();
lcd_integer(12345);
lcd_cmd(0xc0);
lcd_integer(-54321);
}

