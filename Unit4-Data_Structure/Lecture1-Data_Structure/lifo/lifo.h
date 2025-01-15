/**
 ***********************************
 *@file        : lifo.h
 *@author      : Mina Gamil
 *@Created on  : Jan 11, 2025
 ***********************************
 */

#ifndef LIFO_H_
#define LIFO_H_

/** Include Needed Header Files **/
#include <stdio.h>
#include <stdint.h>

/*** Define needed macros ***/
#define Element_Type  unsigned char


typedef struct
{
	unsigned int length;       // Buffer Length
	unsigned int count;        // items Count
	Element_Type* base;        // base Pointer
	Element_Type* head;        // head Pointer
}LIFO_Buf_t;                   // Global variable typedef

//enum Buffer_STATUS used to know lifo buffer status
typedef enum
{
	LIFO_No_Error,             // LIFO everything going well
	LIFO_Is_Full,              // LIFO is full
	LIFO_Is_Null,              // LIFO is not assigned to any pointer
	LIFO_Is_Empty              // LIFO is empty there is no items
}Buffer_STATUS;                // Global Variable typedef

/***** LIFO APIS *****/
Buffer_STATUS LIFO_Init(LIFO_Buf_t* LIFO_Buf, Element_Type* Buf ,unsigned int length);
Buffer_STATUS LIFO_Push_Item(LIFO_Buf_t* LIFO_Buf, Element_Type item);
Buffer_STATUS LIFO_Pop_Item(LIFO_Buf_t* LIFO_Buf, Element_Type* item);
void LIFO_Print(LIFO_Buf_t* LIFO_Buf);

#endif /* LIFO_H_ */
