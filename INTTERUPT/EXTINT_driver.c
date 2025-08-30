#include <LPC21xx.H>
#include"header.h"
#define LED1 1<<17
extern unsigned char a[20];
unsigned int num,i,flag;
//void eint0_handler(void)__irq
//{
//	static int flag;
//	flag^=1;
//	if(flag)
//	 	IOSET0=LED1;
//	else 
//		IOCLR0=LED1;
// 	EXTINT=1;
//	VICVectAddr=0;
//}

void eint0_handler(void)__irq
{
  num=U0IIR&0x0E;
  if(num==4)
  {
    a[i++]=U0RBR;
  }
  if(a[i-1]=='\r')
  {
    a[i-1]='\0';
    flag=1;
    i=0;
  }
  VICVectAddr=0;
}


void config_vic_for_eint0(void)
{
	VICIntSelect=0;
	VICVectAddr0=(int)eint0_handler;
	VICVectCntl0=6|(1<<5);
	VICIntEnable=1<<6;
}



//void config_eint0(void)
//{
//	IODIR0=LED1;
//	PINSEL1|=1;
//	EXTMODE=1;
//	EXTPOLAR=0;
//}

void config_eint0(void)
{
	U0IER=3;
}
