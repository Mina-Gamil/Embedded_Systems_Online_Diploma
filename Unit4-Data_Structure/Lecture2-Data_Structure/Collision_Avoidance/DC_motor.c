/**
 ********************************************
 *@file      : DC_motor.c
 *@author    : Mina Gamil
 *@date      : Jan 20, 2025
 *@brief     : C program for DC_Motor States 
 ********************************************
 */

/**** Include Module header ****/
#include"DC_motor.h"

/**** Declare and assign used variable ****/
unsigned int DC_speed = 0;

/*** DC motor states enum ***/
enum
{
	DC_idle,
	DC_busy
}DC_state_id;


/** DC motor pointer to function **/
void (*DC_state)();


/** DC motor Init function **/
void DC_init(void)
{
	DC_state = STATE(DC_idle);                                           // Assign DC_state pointer to waiting function 
	printf("DC_motor init\n\n");                                         // print Init Done 
}

/** DC motor idle state API **/
STATE_define(DC_idle)
{
	DC_state_id = DC_idle;                                               // Assign DC state id to idle state "Current state"
	DC_state = STATE(DC_idle);                                           // Assign state to idle state
	printf("DC_idle_state : speed = %d \n\n\n", DC_speed);               // print Current state data 
}

/** DC motor busy state API **/
STATE_define(DC_busy)
{
	DC_state_id = DC_busy;                                               // Assign DC state id to busy state "Current state"
	DC_state = STATE(DC_idle);                                           // assign state to idle after modification of motor speed 
	printf("DC_busy_state : speed = %d \n\n\n", DC_speed);               // print Current state data 
}

/** DC motor set speed interface API **/
void DC_set_speed(int CA_speed)
{
	DC_speed = CA_speed;                                                 // Assign speed sent from CA module to DC motor speed
	DC_state = STATE(DC_busy);                                           // Assign state function pointer to busy state 
	printf("CA ---- Send to ----> DC\n");                                // Indicator for receiving data from CA module
}
