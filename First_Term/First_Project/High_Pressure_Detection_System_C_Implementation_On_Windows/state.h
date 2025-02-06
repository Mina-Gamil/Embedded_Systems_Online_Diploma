/*
 * state.h
 *
 *  Created on: Feb 03, 2025
 *      Author: Mina Gamil
 */

#ifndef STATE_H_
#define STATE_H_

/** Include Needed STD library **/
#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
#include "driver.h"

/** Define Needed Macros to create states automatically **/
#define STATE_Define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_


#endif /* STATE_H_ */