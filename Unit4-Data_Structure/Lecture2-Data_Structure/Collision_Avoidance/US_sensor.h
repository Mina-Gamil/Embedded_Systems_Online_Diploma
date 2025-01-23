/*
 * US_sensor.h
 *
 *  Created on: Jan 20, 2025
 *      Author: Mina Gamil
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

/**** Include state header ****/
#include "states.h"

/** UltraSonic sensor pointer to function **/
extern void(*US_state)();

/** UltraSonic sensor API **/
void US_init();
STATE_define(US_busy);
int generate_random_Num(int s, int e, int Num);

#endif /* US_SENSOR_H_ */
