#include <LPC21xx.H>
#include"header.h"
#define SW ((IOPIN1>>26)&1)
main()
{
	int num;
	lcd_init();
	while(1)
	{
		for(num=0;num<60; )
		{
			if(SW==0)
			{
				while(SW==0);
				num++;
			}
			lcd_cmd(0x80);
			lcd_data(num/10+48);
			lcd_data(num%10+48);
			delay_ms(300);
			lcd_cmd(0x01);
		}
	}
}
