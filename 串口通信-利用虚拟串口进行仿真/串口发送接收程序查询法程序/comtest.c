#include <reg52.h>
#include <intrins.h>
unsigned char tmp;
void send_char(unsigned char txd);
void main()
{
	TMOD = 0x20;			// 定时器1工作于8位自动重载模式, 用于产生波特率
	TH1=TL1=0xFD;				// 波特率9600
	SCON = 0x50;			// 设定串行口工作方式1 允许接收,相当于下面三句
	//SM0=0;
	//SM1=1;
	//REN=1;
	PCON =0x00;			// 波特率不倍增
	TR1 = 1;				// 启动定时器1
	while(1)
	{
	
		if(RI==1)						// 是否有数据到来
		{
			RI = 0;
			tmp = SBUF;				// 暂存接收到的数据
			P0 = tmp;				// 数据传送到P0口
			send_char(tmp);			// 回传接收到的数据
		}		
	}
}
void send_char(unsigned char txd)
// 传送一个字符
{
	SBUF = txd;
//	P0 = txd ;
	while(!TI);				// 等特数据传送
	TI = 0;					// 清除数据传送标志
}

