/**
 ***************************************************
 *@file      : Indicate_Airplane_Crew.c
 *@author    : Mina Gamil
 *@date      : Feb 03, 2025
 *@brief     : C program for Control pressure States 
 ***************************************************
 */

/**** Include Module header ****/
#include "Indicate_Airplane_Crew.h"
 
/**** Declare and assign used variable ****/
extern vuint32 pVal;
vuint32 PreviouspVal = 0;
vuint32 ThresholdpVal = 20;
vuint32 Alarm_Timer = 3600;

/*** Indicate_Airplane_Crew states enum ***/
enum{
	Indicate_crew_state,
	Waiting_state
}Indicator_state_id;

/** Indicator pointer to function **/
void (*Indicator_ptr2Func)();

/** Indicate_Airplane_Crew Init API **/
void Indicate_Airplane_Crew_Init(void)
{
	Indicator_ptr2Func = STATE(Indicate_crew_state);          // Set Indicator Pointer To Function equal to the Address of the Indicate_crew_state
	printf("Indicate_Airplane_Crew Initialization\n");
}

/** Indicate_crew_state State **/
STATE_Define(Indicate_crew_state)
{
	Indicator_state_id = Indicate_crew_state;                 // Indicator_state_id equal to Indicate_crew_state
	if (pVal != PreviouspVal)                                 // First Check if the pressure value changed 
	{                                                         // if yes proceed with the following 
		if (pVal > ThresholdpVal)                             // if pressure value is more than Threshold
		{                                                     // if yes proceed with the following 
			printf("Pressure Detected Higher than Threshold pressure\n");
			Set_Led_To_Red();                                 // Trun on Red LED and turn off all other LEDs 
			Set_Buzzer_To_ON();                               // Turn on Buzzer 
			Delay(Alarm_Timer);                               // Delay for alarm timer 
		}
		else if (pVal == ThresholdpVal)                       // if pressure value is equal to Threshold
		{                                                     // if yes proceed with the following 
			printf("Pressure Detected is Equal to Threshold pressure\n");
			Set_Led_To_Yellow();                              // Turn On Yellow LED and turn off all other LEDs 
			Set_Buzzer_To_OFF();                              // Turn off buzzer 
		}
		else                                                  // if not both previous conditions 
		{                                                     // proceed with the following
			printf("Pressure Detected lower than Threshold pressure\n");
			Set_Led_To_Green();                               // Turn on Green LED and turn off all other LEDs 
			Set_Buzzer_To_OFF();                              // Trun off Buzzer 
		}
		PreviouspVal = pVal;                                  // Assign pVal to PreviouspVal
	}
	else
	{       printf("\t---------------\n");
		printf("\tPressure Stable\n");
		printf("\t---------------\n");
	}
	Indicator_ptr2Func = STATE(Waiting_state);                // Set Indicator Pointer To Function equal to the Address of the Waiting_state
}


/** Waiting State **/
STATE_Define(Waiting_state)
{
	Indicator_state_id = Waiting_state;                       // Indicator_state_id equal to Waiting_state
	Indicator_ptr2Func = STATE(Indicate_crew_state);          // Set Indicator Pointer To Function equal to the Address of the Indicate_crew_state
	Indicator_ptr2Func();                                     // Run Pointed Function
}
