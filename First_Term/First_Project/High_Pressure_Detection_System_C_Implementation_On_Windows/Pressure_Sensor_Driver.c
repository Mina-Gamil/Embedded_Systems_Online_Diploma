/**
 ************************************************************
 *@file      : Pressure_Sensor_Driver.c
 *@author    : Mina Gamil
 *@date      : Feb 04, 2025
 *@brief     : C program for Get pressure From Sensor States 
 ************************************************************
 */

/**** Include Module header ****/
#include "Pressure_Sensor_Driver.h"

/**** Declare and assign used variable ****/
vuint32 pVal;

/*** Pressure_Val_State_Id enum ***/
enum{
    Reading_Pressure_Val,
    Waiting_Pressure_Val
}Pressure_Val_State_Id;

/** Pressure_Sensor pointer to function **/
void (*Pressure_Sensor_ptr2Func)();

/* Pressure_Sensor Init API*/
void Pressure_Sensor_Init()
{
    Pressure_Sensor_ptr2Func = STATE(Waiting_Pressure_Val);               // Set Pressure_Sensor pointer to function equal to the address of waiting state
    printf("Pressure_Sensor Initialization\n");
}

/* Reading Pressure Value State*/
STATE_Define(Reading_Pressure_Val)
{
    Pressure_Val_State_Id = Reading_Pressure_Val;                         // set Pressure_Val_State_Id = Reading_Pressure_Val 
    pVal = getPressureVal();                                              // call getPressureVal function to get the pressure value and store it in pVal
    printf("Pressure Got from sensor = %d bar \n", pVal);
    Pressure_Sensor_ptr2Func = STATE(Waiting_Pressure_Val);               // Then set Pressure_Sensor Pointer to waiting state
}

/* Waiting Pressure Value State*/
STATE_Define(Waiting_Pressure_Val)
{
    Pressure_Val_State_Id = Waiting_Pressure_Val;                         // set Pressure_Val_State_Id = Waiting_Pressure_Val 
    Pressure_Sensor_ptr2Func = STATE(Reading_Pressure_Val);               // Set Pressure_Sensor pointer to Reading state 
    Pressure_Sensor_ptr2Func();                                           // Run pointed Function to get new pressure value 
}‎