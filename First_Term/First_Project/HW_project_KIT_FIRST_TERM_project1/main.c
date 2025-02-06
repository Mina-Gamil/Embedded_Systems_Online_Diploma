/**
 **********************************************
 *@file      : main.c
 *@author    : Mina Gamil
 *@date      : Feb 03, 2025
 *@brief     : C program for Pressure Detection 
 **********************************************
 */

/* Included Needed Libraries */
#include "driver.h"
#include "Pressure_Sensor_Driver.h"
#include "Indicate_Airplane_Crew.h"

/* Void setup for init or one time run code */
void setup(void)
{
	GPIO_INITIALIZATION();                           // GPIO Init 
	Pressure_Sensor_Init();                          // Sensor Init
	Buzzer_Init();                                   // Buzzer Init
	Light_Init();                                    // Light Init
	Indicate_Airplane_Crew_Init();                   // Indicator Init
}


/* Main Program */
int main(void)
{
	setup();
	while(1)                                         // Infinite loop 
	{
		Pressure_Sensor_ptr2Func();                  // Run Function pointed by Pressure_Sensor_ptr2Func
		Delay(10);                                   // Wait for 10 millisecond 
		Indicator_ptr2Func();                        // Run Function pointed by Indicator_ptr2Func
		Delay(10);                                   // Wait for 10 millisecond
	}
	return 0;
}