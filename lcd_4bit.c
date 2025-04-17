#include<lpc21xx.h>
#include"header.h"

void lcd_data(unsigned char data)
{
unsigned int temp;
  IOCLR1=0XFE<<16;
//higher nibble
  temp=(data&0xF0)<<16;
  IOSET1=temp;
  IOSET1=1<<17;	 //rs
  IOCLR1=1<<18;	 //rw
  IOSET1=1<<19;	 //en
  delay_ms(2);
  IOCLR1=1<<19;

 //lower nibble
  IOCLR1=0XFE<<16;
  temp=(data&0x0f)<<20;
  IOSET1=temp;
  IOSET1=1<<17;
  IOCLR1=1<<18;
  IOSET1=1<<19;
  delay_ms(2);
  IOCLR1=1<<19;



}
void lcd_cmd(unsigned char cmd)
{ unsigned int temp;
  IOCLR1=0XFE<<16;
//Higher nibble
  temp=(cmd&0xf0)<<16;
  IOSET1=temp;
  IOCLR1=1<<17;
  IOCLR1=1<<18;
  IOSET1=1<<19;
  delay_ms(2);
  IOCLR1=1<<19;

  //lower nibble
  IOCLR1=0XFE<<16;
  temp=(cmd&0x0f)<<20;
  IOSET1=temp;
  IOCLR1=1<<17;
  IOCLR1=1<<18;
  IOSET1=1<<19;
  delay_ms(2);
  IOCLR1=1<<19;


}
void lcd_init()
{
  IODIR1=0XFE<<16;
  //IOCLR1=1<<19;
  lcd_cmd(0x02);
  lcd_cmd(0x03);
  lcd_cmd(0x28);
  lcd_cmd(0x0e);
  lcd_cmd(0x01);
}
void lcd_integer(int num)
{

int a[10],i=0;
 if(num==0)
 lcd_data('0');
 if(num<0)
 {
 num=-num;
 lcd_data('-');
 }
 while(num>0)
 {
  a[i]=num%10+48;
  num/=10;
  i++;

  }
  for(i=i-1;i>0;i--)
  lcd_data(a[i]);

}
