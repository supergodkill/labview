#include <intrins.h>
#include "delay.h"
void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}


void delayxms(Xms)
{
	while(Xms--)
	{
		Delay1ms();
	}
}