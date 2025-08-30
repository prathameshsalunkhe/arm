#include <LPC21xx.H>
#include"header.h"
main()
{
	lcd_init();
	lcd_cmd(0x80);
	lcd_data('A');
	delay_ms(200);
	lcd_cmd(0x80);
	lcd_data('B');
	delay_ms(200);
	lcd_cmd(0x80);
	lcd_data('C');
}
