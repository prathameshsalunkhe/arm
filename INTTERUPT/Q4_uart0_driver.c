#include <LPC21xx.H>
unsigned int flag,num1,num2,r,temp;
unsigned char op;
unsigned int a[3],result;
int i=0;
void uart0_handler(void)__irq
{
	
    result=U0IIR;
	result&=0x0E;
	if(result==4)
	{	
		temp=U0RBR;
		uart0_tx(temp);
		a[i++]=temp;
		flag++;	
	}

 	VICVectAddr=0;
}

void config_vic_for_uart0(void)
{
	VICIntSelect=0;
	VICVectAddr0=(unsigned int)uart0_handler;
	VICVectCntl0=6|(1<<5);
	VICIntEnable=1<<6;
}

void config_uart0(void)
{
	U0IER=3;
}

int main()
{
	uart0_init(9600);
	//lcd_init();
	config_vic_for_uart0();
	config_uart0();
	uart0_tx_string("\r\nEnter The Expression\n");
	while(1)
	{
	
		if(flag==3)
		{
			flag=0;
			num1=a[0]-48;
			num2=a[2]-48;

			switch(a[1])
			{
				case '+': r=num1+num2;
						  uart0_integer(r);
						  //uart0_tx(r/10+48);
						  //uart0_tx(r%10+48);
						  //uart0_tx_string("\r\n");
						  break;
				case '-': r=num1-num2;
				          uart0_integer(r);
						  //uart0_tx(r/10+48);
						  //uart0_tx(r%10+48);
						  //uart0_tx_string("\r\n");
						  break;
				case '*': r=num1*num2;
						  uart0_integer(r);
						  //uart0_tx(r/10+48);
						  //uart0_tx(r%10+48);
						  //uart0_tx_string("\r\n");
						  break;
				case '/': r=num1/num2;
						  uart0_integer(r);
						  //uart0_tx(r/10+48);
						  //uart0_tx(r%10+48);
						  //uart0_tx_string("\r\n");
						  break;
				default : uart0_tx_string("\r\nInvalid Option");
						  break;
			}
			i=0;
		}
	}
}