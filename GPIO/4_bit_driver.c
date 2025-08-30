#include <LPC21xx.H>
#include"header.h"
#define RS 1<<17
#define RW 1<<18
#define EN 1<<19
void lcd_data(unsigned char data)
{
unsigned int temp;
// Higher Nibble

IOCLR1=0xFE<<16;
temp=(data&0xF0)<<16;
IOSET1=temp;
IOSET1=RS;
IOCLR1=RW;
IOSET1=EN;
delay_ms(2);
IOCLR1=EN;

//Lower Nibble

IOCLR1=0xFE<<16;
temp=(data&0x0F)<<20;
IOSET1=temp;
IOSET1=RS;
IOCLR1=RW;
IOSET1=EN;
delay_ms(2);
IOCLR1=EN;

}

void lcd_cmd(unsigned char cmd)
{
unsigned int temp;

// Higher Nibble

IOCLR1=0xFE<<16;
temp=(cmd&0xF0)<<16;
IOSET1=temp;
IOCLR1=RS;
IOCLR1=RW;
IOSET1=EN;
delay_ms(2);
IOCLR1=EN;

//Lower Nibble

IOCLR1=0xFE<<16;
temp=(cmd&0x0F)<<20;
IOSET1=temp;
IOCLR1=RS;
IOCLR1=RW;
IOSET1=EN;
delay_ms(2);
IOCLR1=EN;

}

void lcd_init()
{
IODIR1=0xFE<<16;
PINSEL2=0x0;
IOCLR1=1<<19;
lcd_cmd(0x03);
lcd_cmd(0x02);
lcd_cmd(0x28);
lcd_cmd(0x0e);
lcd_cmd(0x01);
}

void lcd_string(char *p)
{
while(*p!=0)
{
lcd_data(*p);
p++;
}
}
