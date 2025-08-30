#include <LPC21xx.H>
#define LED (7<<17)
unsigned char op;
unsigned flag;

void uart0_handler(void)__irq
{
	unsigned int r=U0IIR;
	r&=0x0E;
	if(r==4)
	{
		flag=1;
		op=U0RBR;
		U0THR=op;
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
	IODIR0=LED;
	U0IER=1;
}

int main()
{
	int i;
	uart0_init(9600);
	config_vic_for_uart0();
	config_uart0();
	uart0_tx_string("\r\nEnter The Option");
		uart0_tx_string("\r\na.LED Blinking Pattern");
		uart0_tx_string("\r\nb.LED Shifting Pattern");
		uart0_tx_string("\r\n");
		IOSET0=LED;
	while(1)
	{
		
		if(flag==1)
		{
		flag=0;
		switch(op)
		{
			case 'a': for(i=0;i<8;i++)
					  {
				          IOCLR0=LED;
						  delay_ms(100);
						  IOSET0=LED;
						  delay_ms(100);
					  }			
					  break;
			case 'b': 
	
						   for(i=17;i<20;i++)
						  {
						  	IOCLR0=1<<i;
							delay_ms(100);
							IOSET0=1<<i;
							delay_ms(100);
						  }
						  break;
			default : uart0_tx_string("\r\nInvalid Option");
					  break;
		}
		}
	}
}
