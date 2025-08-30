#include <LPC21xx.H>
#include "header.h"

int main(){

	unsigned char h,m,s;

	i2c_init();
//	uart0_init(9600);

	lcd_init();

//	lcd_cmd(0xc0);
//	lcd_data('Z');

	/*set rtc time to 11:59:55 PM*/

	i2c_write(0xD0, 0x2, 0x23);//set hrs

	i2c_write(0xD0, 0x1, 0x59);//set mins

	i2c_write(0xD0, 0x0, 0x55);//set secs

	

	/*read rtc time & dump it on the lcd screen*/

	while(1){

		h=i2c_read(0xD1,0x2);//read hrs

		m=i2c_read(0xD1,0x1);//read mins

		s=i2c_read(0xD1,0x0);//read secs

		

		lcd_cmd(0x80);

		lcd_data((h/0x10)+48);

		lcd_data((h%0x10)+48);

		lcd_data(':');

		lcd_data((m/0x10)+48);

		lcd_data((m%0x10)+48);

		lcd_data(':');

		lcd_data((s/0x10)+48);

		lcd_data((s%0x10)+48);	

	}

}


