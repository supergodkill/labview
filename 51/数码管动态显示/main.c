#include <reg52.h>
#include <intrins.h>
#include "delay.h"//延迟函数
#include "code_define.h"//位码段码数组定义
void main()
{
	
	
	for(count;count<9;count++)
	{
		
		delayxms(10);
		P2=0x00;
		P0=~seg_a_code[count];
		
	}
}
