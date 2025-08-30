#include <LPC21xx.H>
#include"header.h"
unsigned int flag;
unsigned int num;
 char a[20];

void  eint0_handler(void) __irq
{		static int i;
		unsigned char temp;
		uart0_tx_string("Enter The String\r\n");
		while(1)
		{
			temp=uart0_rx();
    		a[i++]=temp;
			uart0_tx(temp);
  		
  			if(a[i-1]==13)
  			{
    			a[i-1]='\0';
    			flag=1;
    			i=0;
				break;
  			}
		}
		EXTINT=1;
 		VICVectAddr=0;
}

void eint1_handler(void)__irq
{
      unsigned int l,i;
	  if(flag==1)
      {
	      flag=0;
		  uart0_tx_string("\r\n");
	      uart0_tx_string(a);
	      for(l=0;a[l];l++);
	      for(i=0,l=l-1;i<l;i++,l--)
	      {
	        if(a[i]!=a[l])
	        break;
	      }
	      if(a[i]==a[l])
	        uart0_tx_string("\r\nString Is Palindrome");
	      else
	        uart0_tx_string("\r\nString Is Not Palindrome");
	        uart0_tx_string("\r\n");
	  }
	  EXTINT=2;
	  VICVectAddr=0;
}

void config_vic_for_eint0(void)
{
	VICIntSelect=0;
	VICVectAddr0=(int)eint0_handler;
	VICVectCntl0=14|(1<<5);
	VICVectAddr1=(int)eint1_handler;
	VICVectCntl1=15|(1<<5);

	VICIntEnable=0xC000;
}

void config_eint0(void)
{
	PINSEL0|=0x20000000;
	PINSEL1|=1;
	EXTMODE=3;
	EXTPOLAR=0;
}
