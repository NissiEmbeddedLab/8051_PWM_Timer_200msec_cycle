#include<reg51.h>
sbit PWM = P1^0;
void T0M1Delay(unsigned int x);
void main(void)
{
	while(1) //loop to create 100msec ON time and 100msec OFF time
	{
		PWM = 1;
		T0M1Delay(5);  // for 50% dutycycle @ 200msec cycle use (10+10)*10msec for 25% (5+15) modify line no 9 T0M1Delay(5) and modify line no 11 as T0M1Delay(15);
		PWM = 0;
		T0M1Delay(15);   
	}
}
void T0M1Delay(unsigned int x) //function to create 10msec delay 
{
	unsigned int a;
	for(a=0;a<x;a++)
	{
	TMOD = 0x01;
	TH0 = 0xD8; 			//0XD8F0 FOR 10msec delay @12MHz Oscillator frquency
	TL0 = 0xF0;
	TR0 = 1;
	while(TF0 == 0);
	TR0 = 0;
	TF0 = 0;
	}
}