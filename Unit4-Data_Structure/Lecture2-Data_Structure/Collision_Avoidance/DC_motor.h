/*
 * DC_motor.h
 *
 *  Created on: Jan 20, 2025
 *      Author: Mina Gamil
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/**** Include state header ****/
#include "states.h"

/** DC motor pointer to function **/
extern void (*DC_state)();

/** DC Motor API**/
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

#endif /* DC_MOTOR_H_ */
