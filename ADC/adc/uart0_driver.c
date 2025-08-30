#include <LPC21xx.H>
#include"header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR  (U0LSR&1)

void uart0_init(unsigned int baud)
{
	int a[5]={15,60,30,0,15};
	int pclk,result;
	pclk=a[VPBDIV]*1000000;
	result=pclk/(16*baud);
	PINSEL0|=0x5;
	U0LCR=0x83;
	U0DLL=result&0xFF;
	U0DLM=(result>>8);
	U0LCR=0x3;
}

void uart0_tx(unsigned char data)
{
	U0THR=data;
	while(THRE==0);
}

unsigned char uart0_rx(void)
{
	while(RDR==0);
	return U0RBR;
}

void uart0_tx_string(char *p)
{
	while(*p)
	{
		uart0_tx(*p);
		p++;
	}
}

void uart0_integer(int num)
{
	int a[10],i;
	if(num==0)
	uart0_tx('0');
	if(num<0)
	{
		uart0_tx('-');
		num=-num;
	}
	i=0;
	while(num>0)
	{
		a[i]=num%10+48;
		i++;
		num/=10;
	}
	for(i=i-1;i>=0;i--)
	uart0_tx(a[i]);
}

void uart0_float(float f)
{
	int num;
	if(f==0)
	uart0_tx('0');
	if(f<0)
	{
		uart0_tx('-');
		f=-f;
	}
	num=f;
	uart0_integer(num);
	uart0_tx('.');
	num=(f-num)*1000000;
	uart0_integer(num);
}

