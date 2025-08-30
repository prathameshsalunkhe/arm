#include <LPC21xx.H>
#include"header1.h"
//#define LED1 1<<17
extern unsigned int flag;
extern unsigned char a[20];
//void eint0_handler(void)__irq
//{
//	flag^=1;
//	if(flag)
//		IOSET0=LED1;
//	else
//		IOCLR0=LED1;
//	EXTINT=1;
// 	VICVectAddr=0;
//}

void eint0_handler(void)__irq
{
	unsigned char temp;
	unsigned int i=0;
	uart0_tx_string("Enter The String\r\n");
	while(1)
	{
		temp=uart0_rx();
		uart0_tx(temp);
		a[i++]=temp;
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

void config_vic_for_eint0(void)
{
	VICIntSelect=0;
	VICVectAddr0=(unsigned int)eint0_handler;
	VICVectCntl0=14|(1<<5);
	VICIntEnable=1<<14;
}

void config_eint0(void)
{
	//IODIR0=LED1;
	PINSEL1|=1;
	EXTMODE=1;
	EXTPOLAR=0;
} 
