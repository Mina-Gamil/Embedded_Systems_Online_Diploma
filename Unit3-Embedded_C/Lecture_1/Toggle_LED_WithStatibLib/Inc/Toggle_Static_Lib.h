#ifndef TOGGLE_LED_H
#define TOGGLE_LED_H

#include "Platform_Types.h"


/******** ODR REG DECLARATION **********/
typedef union {
	vuint32 All_Pins;
	struct {
		vuint32 reserved:13;
		vuint32 GPIOA_13:1;
	}Pin;
}R_GPIOA_ODR_t;

/*********** Void Toggle Function Prototype Take Void Pointer Address *********/
void vToggle_Led(void* GPIO);


#endif
