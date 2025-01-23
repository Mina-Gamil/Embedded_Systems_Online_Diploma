/**
 *******************************************************
 *@file      : US_Sensor.c
 *@author    : Mina Gamil
 *@date      : Jan 20, 2025
 *@brief     : C program for UltraSonic sensor States
 *******************************************************
 */

/**** Include Module header ****/
#include "US_sensor.h"

/**** Declare and assign used variable ****/
unsigned int US_distance = 0;

/*** UltraSonic sensor states enum ***/
enum
{
	US_busy
}US_state_id;

/** UltraSonic sensor pointer to function **/
void (*US_state)();

/** UltraSonic sensor Init function **/ 
void US_init()
{
	US_state = STATE(US_busy);                                // Assign US_state pointer to busy function 
	printf("UltraSonic Sensor Init\n\n");                     // print Init Done
}

/** UltraSonic sensor busy state API **/
STATE_define(US_busy)
{
	US_state_id = US_busy;                                    // Assign US_state pointer to busy function 
	US_distance = generate_random_Num(45, 55, 1);             // Generate distance between 45 - 55  
	US_get_distance(US_distance);                             // send distance to Collision avoidance module
	US_state = STATE(US_busy);                                // Assign state pointer to busy function
}

/** UltraSonic sensor generate random num **/
int generate_random_Num(int s, int e, int Num)
{
	int i;
	for(i = 0; i < Num; i++)
		return ((rand() % (e - s + 1)) + s);
}
