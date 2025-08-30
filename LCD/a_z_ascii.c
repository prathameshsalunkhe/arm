#include <LPC21xx.H>
#include"header.h"
main()
{
	int i,num;
	lcd_init();
	while(1)
	{
		for(i=0;i<26;i++)
		{
			lcd_cmd(0x80);
			lcd_data('A'+i);
			num='A'+i;
			lcd_cmd(0xc0);
			lcd_data(num/10+48);
			lcd_data(num%10+48);
			delay_ms(500);
			lcd_cmd(0x01);
		}
	}
}
