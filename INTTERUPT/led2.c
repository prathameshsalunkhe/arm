#include <LPC21xx.H>
#include"header.h"

int main()
{
	unsigned int count=0;
 	config_vic_for_eint0();
	config_eint0();
	while(1)
	{
		count++;
	}
}
