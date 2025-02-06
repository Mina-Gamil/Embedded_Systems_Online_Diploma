/*
 * Pressure_Sensor_Driver.h
 *
 *  Created on: Feb 04, 2025
 *      Author: Mina Gamil
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

/**** Include state header ****/
#include "state.h"

/** Pressure_Sensor pointer to function **/
extern void (*Pressure_Sensor_ptr2Func)();

/* Pressure_Sensor_Driver API's */
void Pressure_Sensor_Init();
STATE_Define(Reading_Pressure_Val);
STATE_Define(Waiting_Pressure_Val);

#endif /* PRESSURE_SENSOR_DRIVER_H_ */