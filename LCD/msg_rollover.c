#include <LPC21xx.H>
#include"header.h"
main()
{
int i;
char s[]="RUSHI";
lcd_init();
while(1)
{
for(i=0;i<16;i++)
{
lcd_cmd(0x80+i);
lcd_string(s);
lcd_cmd(0x80);
lcd_string(s+16-i);
delay_ms(600);
lcd_cmd(0x01);
}
}
}