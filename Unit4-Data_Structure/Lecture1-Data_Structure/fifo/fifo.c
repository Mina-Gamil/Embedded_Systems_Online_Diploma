/**
 **************************************************
 *@file       :  fifo.c
 *@author     :  Mina Gamil
 *@Created on :  Jan 11, 2025
 *@brief      :  Circular First In First Out Buffer
 **************************************************
 **/

/* INCLUDE Needed Headers */
#include "fifo.h"

// Define Needed Macros - Buffer top
#define buffer_top  (FIFO_Buf->base + ((FIFO_Buf->length - 1) * sizeof(Element_Type)))

/** FIFO Initialization API **/
Buffer_STATUS FIFO_Init(FIFO_Buf_t* FIFO_Buf, Element_Type* Buf, unsigned int length)
{
	if(!Buf)                                                          // Check if buffer is available
		return FIFO_Is_Null;                                          // Return FIFO Is Null

	FIFO_Buf->length = length;                                        // Assign length to buffer length
	FIFO_Buf->count  = 0;                                             // Assign Count to Zero
	FIFO_Buf->base   = Buf;                                           // Assign Buf pointer to base pointer
	FIFO_Buf->tail   = Buf;                                           // Assign Buf pointer to tail pointer
	FIFO_Buf->head   = Buf;                                           // Assign Buf pointer to head pointer

	return FIFO_No_Error;                                             // Return that everything going  Well
}

/** FIFO Enqueue API **/
Buffer_STATUS FIFO_Enqueue(FIFO_Buf_t* FIFO_Buf, Element_Type item)
{
	if(!FIFO_Buf->head || !FIFO_Buf->base || !FIFO_Buf->tail)         // Check if buffer is available
		return FIFO_Is_Null;                                          // Return Fifo Null if buffer not available

	if(Is_FIFO_Full(FIFO_Buf) == FIFO_Is_Full)                        // Check if buffer if full
		return FIFO_Is_Full;                                          // Return Fifo Full if is full

	*(FIFO_Buf->head) = item;                                         // Assign entered data to head pointer location
	FIFO_Buf->count++;                                                // Count increment

	if(FIFO_Buf->head == buffer_top)                                  // Check if head reach the top of the queue
		FIFO_Buf->head = FIFO_Buf->base;                              // If top reached return head to base address to over right after Dequeue
	else
		FIFO_Buf->head++;                                             // If not reached increment head to point to the next element

	return FIFO_No_Error;                                             // Return That Everything is going well
}

/** FIFO Dequeue API **/
Buffer_STATUS FIFO_Dequeue(FIFO_Buf_t* FIFO_Buf, Element_Type* item)
{
	if(!FIFO_Buf->head || !FIFO_Buf->base || !FIFO_Buf->tail)         // Check if buffer is available
		return FIFO_Is_Null;                                          // Return FIFO Null in buffer not available

	if(FIFO_Buf->count == 0)                                          // Check if buffer is empty
		return FIFO_Is_Empty;                                         // Return Fifo empty if there is no elements

	*item = *(FIFO_Buf->tail);                                        // Assign value pointed by tail pointer to value pointer by item pointer
	FIFO_Buf->count--;                                                // Count Decrement

	if(FIFO_Buf->tail == buffer_top)                                  // Check if tail reach the top of the queue
		FIFO_Buf->tail = FIFO_Buf->base;                              // if top reached return tail pointer to base address to dequeue for again
	else
		FIFO_Buf->tail++;                                             // if not reached increment tail pointer to pointer to the next dequeued element

	return FIFO_No_Error;                                             // Return That Everything is going well
}

/** Check Is Fifo Full API **/
Buffer_STATUS Is_FIFO_Full(FIFO_Buf_t* FIFO_Buf)
{
	if(!FIFO_Buf->head || !FIFO_Buf->base || !FIFO_Buf->tail)         // Check if buffer is available
		return FIFO_Is_Null;                                          // Return FIFO Null in buffer not available

	if(FIFO_Buf->count == FIFO_Buf->length)                           // Check if the count reach the length
		return FIFO_Is_Full;                                          // if yes , Return FIFO if full

	return FIFO_No_Error;                                             // Return That Everything is going well
}

/** FIFO print API **/
void FIFO_Print(FIFO_Buf_t* FIFO_Buf)
{
	Element_Type* temp;                                               // Create temp pointer to use it to loop and keep the original pointers
	unsigned int i;                                                   // declare unsigned int to loop

	if(FIFO_Buf->count == 0)                                          // Check if the buffer is Empty
	{
		printf("\n\t****** Cannot Print ******\n");
		printf("\t***** Queue Is Empty *****\n");
	}else
	{
		temp = FIFO_Buf->tail;                                        // Assign tail pointer to temp pointer
		printf("\n\t********* Printing Queue *********\n");
		printf("\t|        Address       |  value  |\n" );
		printf("\t**********************************\n");
		for(i = 0; i < FIFO_Buf->count; i++)                          // looping to print all element with addresses
		{
			printf("\t|   %p   |    %x    |\n", temp, *temp);
			if(temp == buffer_top)                                    // Check if temp reach the top of the queue
				temp = FIFO_Buf->base;                                // if top reached return temp pointer to base address to dequeue for again
			else
				temp++;                                               // if not reached increment temp pointer to pointer to the next dequeued element
		}
		printf("\t**********************************\n");
	}

}
