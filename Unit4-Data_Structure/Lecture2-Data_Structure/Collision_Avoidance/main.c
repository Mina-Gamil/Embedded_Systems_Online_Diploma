/**
 ***************************************************
 *@file      : main.c
 *@author    : Mina Gamil
 *@date      : Jan 20, 2025
 *@brief     : main program for first State machine 
 ***************************************************
 */

/**** Include Modules headers ****/
#include"CA.h"
#include"DC_motor.h"
#include"US_sensor.h"

/***** Void setup to hold external init functions *****/
void setup(void)
{
	CA_init();                                   // Collision Avoidance module initialization 
	DC_init();                                   // DC motor module initialization 
	US_init();                                   // UltraSonic Sensor module initialization 
}

/** main function body **/
int main(void)
{
	int i ;                                      // declare int i to make delay
	setup();                                     // call setup function 

	while(1)                                     // enter inside infinite loop
	{
		US_state();                              // Call Ultrasonic module to read from sensor and send data to CA
		CA_state();                              // call Collision avoidance module to check sensor data and send data to motor
		DC_state();                              // call DC motor module to received data from CA and set the motor speed

		for(i = 0; i < 100000000; i++);          // Delay for time and then loop again
	}
	return 0;                                    // if we exit from while loop return 0
}
