/*
 * 7-Segment.h
 *
 *  Created on: Sep 9, 2025
 *      Author: Mina
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"

/* Define Seven Segment Port */
#define Seven_Segmant_Port			GPIOB

/* Define Numbers */
#define Zero						0x01
#define One							0x79
#define Two							0x24
#define Three						0x30
#define Four						0x58
#define Five						0x12
#define Six							0x02
#define Seven						0x19
#define Eight						0x00
#define Nine						0x10


/* Seven Segment API's */
void HAL_Seven_Segment_Init(void);
void HAL_Seven_Segment_Send(uint8_t Number);

#endif /* INC_7_SEGMENT_H_ */
