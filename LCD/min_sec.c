#include <LPC21xx.H>
#include"header.h"
main()
{
	int min,sec;
	lcd_init();
	while(1)
	{
		for(min=0;min<60;min++)
		{
			for(sec=0;sec<60;sec++)
			{
				lcd_cmd(0x80);
				lcd_data(min/10+48);
				lcd_data(min%10+48);
				lcd_data(':');
				lcd_data(sec/10+48);
				lcd_data(sec%10+48);
				delay_ms(300);
				lcd_cmd(0x01);
			}
		}
	}
}
