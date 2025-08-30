#include <LPC21xx.H>
#include"header.h"
#define LED 1<<17
#define SW 1<<14
main()
{
IODIR0=LED;
