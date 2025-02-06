/*
 * Light_Alarm_Driver.h
 *
 *  Created on: Feb 04, 2025
 *      Author: Mina Gamil
 */
#ifndef LIGHT_ALARM_DRIVER_H_
#define LIGHT_ALARM_DRIVER_H_

/**** Include state header ****/
#include "state.h"

/* Light_Alarm_Driver API's */
void Light_Init(void);
void Set_Led_To_Red();
void Set_Led_To_Green();
void Set_Led_To_Yellow();
STATE_Define(Red_On);
STATE_Define(Green_On);
STATE_Define(Yellow_On);

#endif /* LIGHT_ALARM_DRIVER_H_ */
