#include <LPC21xx.H>
#define LED 1<<17
unsigned int c=0;
void eint0_handler(void)__irq
{
	c++;

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
	IODIR0=LED;
	PINSEL1|=1;
	EXTMODE=1;
	EXTPOLAR=0;
}

int main()
{
	config_vic_for_eint0();
	config_eint0();
	while(1)
	{
	//delay_sec(1);
	if(c==1)
	{
		IOCLR0=LED;
		c=0;
	}
	if(c==2)
	{
		IOSET0=LED;
		c=0;
	}

    }
}