/**
 ***************************************************
 *@file      : Light_Alarm_Driver.c
 *@author    : Mina Gamil
 *@date      : Feb 04, 2025
 *@brief     : C program for Control Light States 
 ***************************************************
 */

/**** Include Module header ****/
#include "Light_Alarm_Driver.h"

/*** Light State Id enum ***/
enum{
    Red_On,
    Green_On,
    Yellow_On
}Light_state_Id;

/** Light pointer to function **/
void(*Light_ptr2Func)();

/** Light Init API **/
void Light_Init(void)
{
    Light_ptr2Func = STATE(Green_On);               // Set Light Pointer To Function equal to the Address of Green_On state
    printf("Light_Alarm Initialization\n");
    Light_ptr2Func();                               // Run pointed Function to Turn on Green LED and Turn OFF others 
}

/* Red LED Alarm API */
void Set_Led_To_Red()
{
    Light_ptr2Func = STATE(Red_On);                 // Set Light Pointer To Function equal to the Address of Red_On state
    Light_ptr2Func();                               // Run pointed Function to Turn on Red LED and Turn OFF others 
}

/* Green LED Alarm API */
void Set_Led_To_Green()
{
    Light_ptr2Func = STATE(Green_On);               // Set Light Pointer To Function equal to the Address of Green_On state
    Light_ptr2Func();                               // Run pointed Function to Turn on Green LED and Turn OFF others
}

/* Yellow LED Alarm API */
void Set_Led_To_Yellow()
{
    Light_ptr2Func = STATE(Yellow_On);              // Set Light Pointer To Function equal to the Address of Yellow_On state
    Light_ptr2Func();                               // Run pointed Function to Turn on Yellow LED and Turn OFF others
}

/* Red_On state */
STATE_Define(Red_On)
{
    Light_state_Id = Red_On;                        // Set Light_state_Id to Red_On 
    Set_Light_Alarm(1, 0, 0);                       // Call set light api and set it to (r, G, Y) = (1, 0, 0)
}

/* Green_On state */
STATE_Define(Green_On)
{
    Light_state_Id = Green_On;                      // Set Light_state_Id to Green_On 
    Set_Light_Alarm(0, 1, 0);                       // Call set light api and set it to (r, G, Y) = (0, 1, 0)
}

/* Yellow_On state */
STATE_Define(Yellow_On)
{
    Light_state_Id = Yellow_On;                     // Set Light_state_Id to Yellow_On
    Set_Light_Alarm(0, 0, 1);                       // Call set light api and set it to (r, G, Y) = (0, 0, 1)
}