/**
 ********************************************************
 * @file           : main.c
 * @author         : Mina Gamil
 * @date           : 4 Jan. 2025
 * @brief          : Toggle Led On GPIO F3 on TM4C123
 ********************************************************
 */

/********* DIFINED USED ADDRESSES *********/
#define SYSCTL_RCGC2_R         0x400FE108
#define GPIO_POERTF_DIR_R      0x40025400
#define GPIO_POERTF_DEN_R      0x4002551C
#define GPIO_POERTF_DATA_R     0x400253FC



typedef union {
	volatile unsigned long All_Pins;
	struct
	{
		volatile unsigned long reserved:3;
		volatile unsigned long pin_3:1;
		volatile unsigned long pin_4:1;
		volatile unsigned long pin_5:1;
	}Pin;
}GPIOF_R_t;



volatile GPIOF_R_t* GPIOF_DIR = (volatile GPIOF_R_t*) GPIO_POERTF_DIR_R;
volatile GPIOF_R_t* GPIOF_DEN = (volatile GPIOF_R_t*) GPIO_POERTF_DEN_R;
volatile GPIOF_R_t* GPIOF_DATA = (volatile GPIOF_R_t*) GPIO_POERTF_DATA_R;
volatile GPIOF_R_t* SYSCTL_RCGC2 = (volatile GPIOF_R_t*) SYSCTL_RCGC2_R;

/*** Main Function Body ***/
int main()
{
	volatile unsigned long delay;
	SYSCTL_RCGC2->Pin.pin_5 = 1;
	for (delay = 0; delay < 200; delay++);
	GPIOF_DIR->Pin.pin_3 = 1;
	GPIOF_DEN->Pin.pin_3 = 1;

	while(1)
	{
		GPIOF_DATA->Pin.pin_3 = 1;
		for (delay = 0; delay < 200000; delay++);
		GPIOF_DATA->Pin.pin_3 = 0;
		for (delay = 0; delay < 200000; delay++);
	}
	return 0;
}