/**
 *******************************************************
 *@file      : CA.c
 *@author    : Mina Gamil
 *@date      : Jan 20, 2025
 *@brief     : C program for Collision avoidance States
 *******************************************************
 */

/**** Include Module header ****/
#include "CA.h"

/**** Declare and assign used variable ****/
unsigned int CA_speed = 0;
unsigned int CA_distance = 0;
unsigned int CA_threshold = 50;

/*** Collision Avoidance states enum ***/
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

/** Collision Avoidance pointer to function **/
void (*CA_state)();

/** Collision Avoidance Init function **/ 
void CA_init(void)
{
	CA_state = STATE(CA_waiting);                                                                           // Assign CA_state pointer to waiting function 
	printf("Collision_Avoidance Init.\n\n");                                                                // print Init Done
}

/** Collision Avoidance waiting state API **/
STATE_define(CA_waiting)
{
	CA_state_id = CA_waiting;                                                                               // Assign state id to waiting 
	printf("waiting state : distance = %d, speed = %d \n", CA_distance, CA_speed);                          // print distance and speed in this moment 
	CA_speed = 0;                                                                                           // Assign CA_speed to Zero 
	DC_set_speed(CA_speed);                                                                                 // Set CA_speed to DC motor speed
}

/** Collision Avoidance driving state API **/
STATE_define(CA_driving)
{
	CA_state_id = CA_driving;                                                                               // Assign state id to driving 
	printf("driving state : distance = %d, speed = %d \n", CA_distance, CA_speed);                          // print distance and speed in this moment 
	CA_speed = 30;                                                                                          // Assign CA_speed to 30 
	DC_set_speed(CA_speed);                                                                                 // Set CA_speed to DC motor speed
}

/** US_get_Distance interface API to get distance from ultrasonic sensor **/
void US_get_distance(int US_distance)
{
	CA_distance = US_distance;                                                                              // Assign UltraSonic Measured distance to CA_distance
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));           // Check distance and assign the next state 
	printf("US_sensor ----- Send to -------> CA\n");                                                        // Indicator for sending data from US module to CA module 
}

