/**
 *******************************
 *@file       :  fifo.h
 *@author     :  Mina Gamil
 *@Created on :  Jan 11, 2025
 *******************************
 **/

#ifndef FIFO_H_
#define FIFO_H_

/* INCLUDE Needed Headers */
#include <stdio.h>

// define needed macros
#define Element_Type  unsigned char

/** Define Typedef struct FIFO buffer**/
typedef struct
{
	unsigned int length;              // Buffer Length got from user
	unsigned int count;               // items counter init. to Zero
	Element_Type* base;               // pointer indicate to base address and never change
	Element_Type* head;               // pointer indicate to head where the data enqueue
	Element_Type* tail;               // pointer indicate to tail where the data dequeue
}FIFO_Buf_t;

typedef enum
{
	FIFO_No_Error,                    // FIFO everything going well
	FIFO_Is_Full,                     // FIFO is full
	FIFO_Is_Null,                     // FIFO is not assigned to any pointer
	FIFO_Is_Empty                     // FIFO in empty there is no items
}Buffer_STATUS;

/**** FIFO APIS ****/
Buffer_STATUS FIFO_Init(FIFO_Buf_t* FIFO_Buf, Element_Type* Buf, unsigned int length);
Buffer_STATUS FIFO_Enqueue(FIFO_Buf_t* FIFO_Buf, Element_Type item);
Buffer_STATUS FIFO_Dequeue(FIFO_Buf_t* FIFO_Buf, Element_Type* item);
Buffer_STATUS Is_FIFO_Full(FIFO_Buf_t* FIFO_Buf);
void FIFO_Print(FIFO_Buf_t* FIFO_Buf);

#endif /* FIFO_H_ */
