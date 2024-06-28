#include<LPC214x.h>
void delay()
{
	unsigned int i=0;
	while(i<200000)
	{
		i++;
	}
}
int main()
{
	IODIR0|=(0x01<<16);
	IODIR0|=(0x01<<17);
	IODIR0|=(0x01<<18);
	IODIR1&=~(0x01<<16);
	while(1)
	{
		if((IOPIN1&(1<<16))==0)
		{
			IOSET0|=(0x01<<16);
			IOSET0|=(0x01<<17);
			IOSET0|=(0x01<<18);
		}
		else
		{
			IOCLR0|=(0x01<<16);
			IOCLR0|=(0x01<<17);
			IOCLR0|=(0x01<<18);
		}
		delay();
	}
}
