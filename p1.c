#include<lpc21xx.h>
#include"header.h"
main()
{
int i;
lcd_init();
	while(1)
	{
		//lcd_cmd(0x08);
	for(i=0;i<16;i++)
		{
		lcd_cmd(0x80+i);
		lcd_string("Prathamesh");
		lcd_cmd (0xc0+i);
		lcd_string("Salunkhe");
		lcd_cmd (0x01);

		}
	}
}
