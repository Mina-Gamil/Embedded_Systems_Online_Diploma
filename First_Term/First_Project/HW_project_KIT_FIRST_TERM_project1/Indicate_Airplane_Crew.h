/*
 * Indicate_Airplane_Crew.h
 *
 *  Created on: Feb 03, 2025
 *      Author: Mina Gamil
 */

#ifndef INDICATE_AIRPLANE_CREW_H_
#define INDICATE_AIRPLANE_CREW_H_

/**** Include state header ****/
#include "state.h"

/** Indicator pointer to function **/
extern void (*Indicator_ptr2Func)();

/** Indicate_Airplane_Crew API's **/
void Indicate_Airplane_Crew_Init(void);
STATE_Define(Indicate_crew_state);
STATE_Define(Waiting_state);

/* Other API's Used By this module form other files */
extern void Set_Buzzer_To_ON();
extern void Set_Buzzer_To_OFF();
extern void Set_Led_To_Red();
extern void Set_Led_To_Green();
extern void Set_Led_To_Yellow();

#endif /* INDICATE_AIRPLANE_CREW_H_ */