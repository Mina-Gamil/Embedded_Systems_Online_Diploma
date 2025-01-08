/**
 ********************************************************
 * @file           : main.c
 * @author         : Mina Gamil
 * @date           : 4 Jan. 2025
 * @brief          : Toggle Led On GPIO F3 on TM4C123
 ********************************************************
 */

/********* DIFINED USED ADDRESSES *********/
#define SYSCTL_RCGC2_R         *((volatile unsigned long*)(0x400FE108))
#define GPIO_POERTF_DIR_R      *((volatile unsigned long*)(0x40025400))
#define GPIO_POERTF_DEN_R      *((volatile unsigned long*)(0x4002551C))
#define GPIO_POERTF_DATA_R     *((volatile unsigned long*)(0x400253FC))

/*** Main Function Body ***/
int main()
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R = 0x00000020;
	for (delay = 0; delay < 200; delay++);
	GPIO_POERTF_DIR_R |= 1<<3;
	GPIO_POERTF_DEN_R |= 1<<3;

	while(1)
	{
		GPIO_POERTF_DATA_R |= 1<<3;
		for (delay = 0; delay < 20000; delay++);
		GPIO_POERTF_DATA_R &= ~(1<<3);
		for (delay = 0; delay < 20000; delay++);
	}
	return 0;
}