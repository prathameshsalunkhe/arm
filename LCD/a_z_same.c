#include <LPC21xx.H>
#include"header.h"
main()
{
	int i;
	lcd_init();
	while(1)
	{
		for(i=0;i<26;i++)
		{
			lcd_cmd(0x80);
			lcd_data('A'+i);
			delay_ms(300);
			lcd_cmd(0x01);
		}
	}
}
