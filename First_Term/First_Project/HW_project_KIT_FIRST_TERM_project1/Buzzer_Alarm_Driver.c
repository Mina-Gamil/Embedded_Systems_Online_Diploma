/**
 ***************************************************
 *@file      : Buzzer_Alarm_Driver.c
 *@author    : Mina Gamil
 *@date      : Feb 04, 2025
 *@brief     : C program for Control Buzzer States 
 ***************************************************
 */

/**** Include Module header ****/
#include "Buzzer_Alarm_Driver.h"

/*** Buzzer states enum ***/
enum{
    Buzzer_idle,
    Buzzer_ON,
    Buzzer_OFF
}Buzzer_State_Id;

/** Buzzer pointer to function **/
void(*Buzzer_ptr2Func)();

/** Buzzer Init API **/ 
void Buzzer_Init(void)
{
    Buzzer_ptr2Func = STATE(Buzzer_OFF);            // Set Buzzer Pointer To Function equal to the Address of the idle state
	Buzzer_ptr2Func();                              // Run pointed Function to Turn Off the Buzzer
}

/** Set Buzzer To ON API **/ 
void Set_Buzzer_To_ON()
{
    Buzzer_ptr2Func = STATE(Buzzer_ON);              // Set Buzzer Pointer To Function equal to the Address of the ON state
    Buzzer_ptr2Func();                               // Run Pointed Function 
}

/** Set Buzzer To OFF API **/ 
void Set_Buzzer_To_OFF()
{
    Buzzer_ptr2Func = STATE(Buzzer_OFF);             // Set Buzzer Pointer To Function equal to the Address of the OFF state
    Buzzer_ptr2Func();                               // Run Pointed Function
}

/** Buzzer Idle State **/
STATE_Define(Buzzer_idle)
{
    Buzzer_State_Id = Buzzer_idle;                   // Set_State_Id equal to idle state  
    Buzzer_ptr2Func = STATE(Buzzer_idle);            // Set Buzzer Pointer To Function equal to the Address of the idle state
}

/** Buzzer ON State **/
STATE_Define(Buzzer_ON)
{
    Buzzer_State_Id = Buzzer_ON;                     // Set_State_Id equal to ON state
    Set_Buzzer_Alarm(1);                             // Call Function to set buzzer to ON
    Buzzer_ptr2Func = STATE(Buzzer_idle);            // Set Buzzer Pointer To Function equal to the Address of the idle state
}

/** Buzzer OFF State **/
STATE_Define(Buzzer_OFF)
{
    Buzzer_State_Id = Buzzer_OFF;                    // Set_State_Id equal to OFF state
    Set_Buzzer_Alarm(0);                             // Call Function to set buzzer to OFF
    Buzzer_ptr2Func = STATE(Buzzer_idle);            // Set Buzzer Pointer To Function equal to the Address of the idle state
}