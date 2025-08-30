#include <LPC21xx.H>
//#include"header.h"
void eint0_handler(void)
{



 	VICVectAddr=0;
}

void eint0_handler1(void)
{



 	VICVectAddr=0;
}

void eint0_handler2(void)
{



 	VICVectAddr=0;
}

void eint0_handler3(void)
{



 	VICVectAddr=0;
}

void config_for_eint0(void)
{
	VICIntSelect=0;

	VICVectAddr0=(int)eint0_handler;
	VICVectCntl0=14|(1<<5);
	VICVectAddr1=(int)eint0_handler1;
	VICVectCntl1=15|(1<<5);
	VICVectAddr2=(int)eint0_handler2;
	VICVectCntl2=16|(1<<5);
	VICVectAddr3=(int)eint0_handler3;
	VICVectCntl3=17|(1<<5);

	VICIntEnable=15<<14;
}

//void config_for_eint1(void)
//{
//	VICIntSelect=0;
//	VICVectAddr1=(int)eint1_handler;
//	VICVectCntl1=15|(1<<5);
//	VICIntEnable|=1<<15;
//}
//
//void config_for_eint2(void)
//{
//	VICIntSelect=0;
//	VICVectAddr2=(int)eint2_handler;
//	VICVectCntl2=16|(1<<5);
//	VICIntEnable|=1<<16;
//}
//
//void config_for_eint3(void)
//{
//	VICIntSelect=0;
//	VICVectAddr3=(int)eint3_handler;
//	VICVectCntl3=17|(1<<5);
//	VICIntEnable|=1<<17;
//}

void config_eint0(void)
{
	PINSEL0|=0x600C0000; // p0.
	PINSEL1|=1;	

	}
	int main()
	{
		
		}