#include <LPC21xx.H>
#include"header.h"
main()
{
	int i;
	lcd_init();
	while(1)
	{
		for(i=0;i<16;i++)
		{
			lcd_cmd(0x80+i);
			lcd_data('A');
			delay_ms(300);
			lcd_cmd(0x01);
		}
	}
}

