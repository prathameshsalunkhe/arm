#include <LPC21xx.H>
unsigned char a[30];
unsigned int i,flag,c;
void uart0_handler(void)__irq
{
	uart0_tx_string("Enter The String\r\n");
	while(1)
	{
		unsigned char temp;
		unsigned int r=U0IIR;
		r&=0x0E;
		if(r==4)
		{
			temp=U0RBR;
			U0THR=temp;
			a[i++]=temp;
		}
		if(a[i-1]==13)
		{
			a[i-1]='\0';
			flag=1;
			i=0;
			VICIntEnClr=1<<6;
			break;
		}
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
	int l,j;
	uart0_init(9600);
	lcd_init();
	config_vic_for_uart0();
	config_uart0();
	while(1)
	{
		c++;
		if(flag==1)
		{
			flag=0;
			lcd_string(a);
			lcd_cmd(0xc0);
			for(l=0;a[l];l++);
			for(j=0,l=l-1;j<l;j++,l--)
			{
				if(a[j]!=a[l])
				break;
			}
			if(a[j]==a[l])
			{
				//uart0_tx_string("\r\nString Is Palindrome");
				lcd_string("Palindrome");
				break;
			}
			else
			{
				//uart0_tx_string("\r\nString Is Not Palindrome");
				lcd_string("Not Palindrome");
				break;
			}
		}
	}
}
