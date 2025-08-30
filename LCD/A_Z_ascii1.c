#include <LPC21xx.H>
#include"header.h"
main()
{
	int i,num,n;
	lcd_init();
	while(1)
	{
		for(i=0;i<26;i++)
		{
			lcd_cmd(0x80);
			lcd_data('a'+i);
			num='a'+i;
			n=num%100;
			lcd_cmd(0xc0);
			lcd_data(num/100+48);
			lcd_data(n/10+48);
			lcd_data(n%10+48);
			delay_ms(500);
			lcd_cmd(0x01);
		}
	}
}
