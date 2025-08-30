#include <LPC21xx.H>
#include"header.h"
main()
{
int i;
lcd_init();
while(1)
{
for(i=0;i<5;i++)
{
lcd_cmd(0x80);
lcd_string("RUSHI");
delay_ms(500);
lcd_cmd(0x01);
delay_ms(200);
}
lcd_cmd(0xc0);
lcd_string("KOLI");
delay_ms(500);
lcd_cmd(0x01);
}
}
