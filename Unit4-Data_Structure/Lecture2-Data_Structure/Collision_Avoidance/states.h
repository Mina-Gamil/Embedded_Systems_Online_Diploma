/*
 * states.h
 *
 *  Created on: Jan 20, 2025
 *      Author: Mina Gamil
 */

#ifndef STATES_H_
#define STATES_H_

/** Include Needed STD library **/
#include <stdio.h>
#include <stdlib.h>

/** Define Needed Macros to create states automatically **/
#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

/** Interface API Between All Modules **/
void US_get_distance(int US_distance);
void DC_set_speed(int CA_speed);

#endif /* STATES_H_ */
