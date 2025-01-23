/*
 * CA.h
 *
 *  Created on: Jan 20, 2025
 *      Author: Mina Gamil
 */

#ifndef CA_H_
#define CA_H_

/**** Include state header ****/
#include "states.h"

/** Collision Avoidance pointer to function **/
extern void(*CA_state)();

/** Collision Avoidance API's **/
void CA_init(void);
STATE_define(CA_waiting);
STATE_define(CA_driving);
int generate_random_Num(int s, int e, int Num);

#endif /* CA_H_ */
