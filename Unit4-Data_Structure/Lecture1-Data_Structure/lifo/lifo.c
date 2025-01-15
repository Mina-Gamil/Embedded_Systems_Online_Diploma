/**
 *************************************************
 *@file        : lifo.c
 *@author      : Mina Gamil
 *@Created on  : Jan 11, 2025
 *@brief       : Last In First Out Data Structure
 *************************************************
 */

/*** Include Needed Header Files ***/
#include "lifo.h"


// LIFO initialization API
Buffer_STATUS LIFO_Init(LIFO_Buf_t* LIFO_Buf, Element_Type* Buf ,unsigned int length)
{
	if(!Buf)                                  // Check if buffer is available
		return LIFO_Is_Null;                  // return LIFO Is Null

	LIFO_Buf->base = Buf;                     // Assign Buf to buffer base
	LIFO_Buf->head = Buf;                     // Assign Buf to buffer head
	LIFO_Buf->length = length;                // Assign length to buffer length
	LIFO_Buf->count = 0;                      // Initialize buffer counter to Zero

	return LIFO_No_Error;                     // return that everything Well Done
}

// LIFO Push item API
Buffer_STATUS LIFO_Push_Item(LIFO_Buf_t* LIFO_Buf, Element_Type item)
{
	if(!LIFO_Buf->base || !LIFO_Buf->head)    // Check if buffer is available
		return LIFO_Is_Null;                  // return LIFO Is Null

	if(LIFO_Buf->count == LIFO_Buf->length)   // check if buffer is full
		return LIFO_Is_Full;                  // return LIFO Is Full

	*(LIFO_Buf->head) = item;                 // Assign item to pointer lifo head
	LIFO_Buf->head++;                         // increment buffer head
	LIFO_Buf->count++;                        // increment buffer count

	return LIFO_No_Error;                     // return that everything Well Done
}

// LIFO Pop item API
Buffer_STATUS LIFO_Pop_Item(LIFO_Buf_t* LIFO_Buf, Element_Type* item)
{
	if(!LIFO_Buf->base || !LIFO_Buf->head)    // Check if buffer is available
		return LIFO_Is_Null;                  // return LIFO Is Null

	if(LIFO_Buf->count == 0)                  // Check if buffer is empty
		return LIFO_Is_Empty;                 // return Is Empty

	LIFO_Buf->head--;                         // Decrement buffer head
	*item = *(LIFO_Buf->head);                // Assign buffer head to item
	LIFO_Buf->count--;                        // Decrement buffer counter

	return LIFO_No_Error;                     // return that everything Well Done
}

// LIFO Print item
void LIFO_Print(LIFO_Buf_t* LIFO_Buf)
{
	Element_Type* start = LIFO_Buf->base;     // Declare and assign base pointer to start pointer
	unsigned int i = 0;                       // Declare and initialize variable to zero for looping

	printf("     *** Printing Stack Buffer ***\n");
	printf("   **********************************\n");
	printf("   | No. |     Address      | Value |\n");
	printf("   **********************************\n");

	while(i != LIFO_Buf->length)               // Check if we not reached the last element of the buffer
	{
		printf("   |  %d  | %p |   %X   |\n", i + 1, start, *(start));
		i++;
		start++;
	}
	printf("   **********************************\n\n");
}
