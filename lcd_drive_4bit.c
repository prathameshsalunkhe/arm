#include<lpc21xx.h>
#include"header.h"
void lcd_data(unsigned char data)
{
unsigned int temp;
//highee nibble
IOCLR1=0XFE<<16;
temp=(data&0XF0)<<16;
IOSET1=temp;
IOSET1=1<<17; //RS
IOCLR1=1<<18; //RW
IOSET1=1<<19; //EN
delay_ms(2);
IOCLR1=1<<19; //EN

//lower nibbel
IOCLR1=0XFE<<16;
temp=(data&0X0F)<<20;
IOSET1=temp;
IOSET1=1<<17; //RS
IOCLR1=1<<18; //RW
IOSET1=1<<19; //EN
delay_ms(2);
IOCLR1=1<<19; //EN
}
void lcd_cmd(unsigned char cmd)
{
unsigned int temp;
//higher nibble
IOCLR1=0XFE<<16;
temp=(cmd&0XF0)<<16;
IOSET1=temp;
IOCLR1=1<<17; //RS
IOCLR1=1<<18; //RW
IOSET1=1<<19; //EN
delay_ms(2);
IOCLR1=1<<19; //EN

//lower nibble
IOCLR1=0XFE<<16;
temp=(cmd&0X0F)<<20;
IOSET1=temp;
IOCLR1=1<<17; //RS
IOCLR1=1<<18; //RW
IOSET1=1<<19; //EN
delay_ms(2);
IOCLR1=1<<19; //EN
}
void lcd_init()
{
IODIR1=0XFE<<16;
//IOCLR1=1<<19;
lcd_cmd(0x02);
lcd_cmd(0x03);
lcd_cmd(0x028);
lcd_cmd(0x0e);
lcd_cmd(0x01);
}
void lcd_string(char *ptr)
{
	while(*ptr!=0)
	{
		lcd_data(*ptr);
		ptr++;
	}
}
