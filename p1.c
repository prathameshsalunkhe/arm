#include<lpc21xx.h>
#include"header.h"
main()
{//	int i;
	lcd_init();
	lcd_cmd(0x80);
	lcd_integer(12345);
	while(1);

}
