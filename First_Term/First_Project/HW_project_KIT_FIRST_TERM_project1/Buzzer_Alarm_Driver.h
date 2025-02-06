/*
 * Buzzer_Alarm_Driver.h
 *
 *  Created on: Feb 04, 2025
 *      Author: Mina Gamil
 */

#ifndef BUZZER_ALARM_DRIVER_H_
#define BUZZER_ALARM_DRIVER_H_

/**** Include state header ****/
#include "state.h"

/** Buzzer API's **/
void Buzzer_Init(void);
void Set_Buzzer_To_ON();
void Set_Buzzer_To_OFF();
STATE_Define(Buzzer_idle);
STATE_Define(Buzzer_ON);
STATE_Define(Buzzer_OFF);

#endif /* BUZZER_ALARM_DRIVER_H_ */