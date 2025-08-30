#include <LPC21xx.H>
char s[30];
unsigned int flag=0;
void eint0_handler(void)__irq
{
	//unsigned int i=0;
	flag=1;
	uart0_tx_string("\r\nEnter The String\r\n");
//	while(1)
//	{
//		s[i++]=uart0_rx();
//		uart0_tx(s[i-1]);
//		if(s[i-1]==13)
//		{
//			s[i-1]='\0';
//			flag=1;
//			i=0;
//			break;
//		}
//	}
	EXTINT=1;
 	VICVectAddr=0;
}

void config_vic_for_eint0(void)
{
	VICIntSelect=0;
	VICVectAddr0=(unsigned int)eint0_handler;
	VICVectCntl0=14|(1<<5);
	VICIntEnable=1<<14;
}

void config_eint0(void)
{
	PINSEL1|=1;
	EXTMODE=1;
	EXTPOLAR=0;
}

int main()
{
	int i=0,j,l;
	
	config_vic_for_eint0();
	config_eint0();
	uart0_init(9600);
	while(1)
	{	
		while(1)
		{	
			if(flag==1)
			{	
				s[i++]=uart0_rx();
				uart0_tx(s[i-1]);
				if(s[i-1]==13)
				{
					s[i-1]='\0';
					flag=2;
					i=0;
					break;
				}
		    }
		 }
    	if(flag==2)
		{
			flag=0;
			for(l=0;s[l];l++);
			for(j=0,l=l-1;j<l;j++,l--)
			{
				if(s[j]!=s[l])
				break;
			}
			if(s[j]==s[l])
				uart0_tx_string("\r\nPalindrome");
			else
				uart0_tx_string("\r\nNot Palindrome");
		}	
	}
}
