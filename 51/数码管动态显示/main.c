#include <reg52.h>
#include <intrins.h>
#include "delay.h"//延迟函数
#include "code_define.h"//位码段码数组定义
void main()
{
	
	
	for(count;count<5;count++)
	{
		
		delayxms(10);
		P2=dig_code[count];
		P0=seg_c_code[count];
		
	}
}
