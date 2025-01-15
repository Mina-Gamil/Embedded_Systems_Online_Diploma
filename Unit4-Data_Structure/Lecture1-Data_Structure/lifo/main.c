/**
 ***********************************
 *@file        : main.c
 *@author      : Mina Gamil
 *@Created on  : Jan 11, 2025
 *@brief       : Main Program Body
 ***********************************
 */

/*** Include Needed Header Files ***/
#include <stdlib.h>

#include "lifo.h"

// Declare lifo buffers used
LIFO_Buf_t Uart_Buf, I2c_Buf;
Element_Type temp, Buffer1[5];

// Declare some used variables
unsigned int i, length = 5;


void main(void)
{
	/*************** First LIFO Is Static Memory Allocated ***************/
	printf("   *********** Static ***********  \n");
	LIFO_Init(&Uart_Buf, Buffer1, length);                          // Initialize Uart_Buf
	printf("=========== LIFO Pushing ===========");

	/** Pushing elements to Stack **/
	for(i = 0; i < length; i++)
	{
		if(LIFO_Push_Item(&Uart_Buf, i) == LIFO_No_Error)           // Check if item pushed successfully
			printf("\n\t Urat_LIFO Push : %d",i);                   // if yes, print value pushed to stack
		else if(LIFO_Push_Item(&Uart_Buf, i) == LIFO_Is_Full)       // if not pushed , check if there is no space
			printf("\n\t Pushing Failed -- Stack Is Full");         // if yes , Print Stack is full
	}
	printf("\n====================================\n");
	LIFO_Print(&Uart_Buf);                                          // print Buffer to check everything is going well

	printf("=========== LIFO Popping ===========");

	/** Popping elements to Stack **/
	for(i = length / 2; i > 0; i--)
	{
		if(LIFO_Pop_Item(&Uart_Buf, &temp) == LIFO_No_Error)        // Check if item popped successfully
			printf("\n\t Urat_LIFO Pop : %d", temp);                // If yes, print value popped from stack
		else if(LIFO_Pop_Item(&Uart_Buf, &temp) == LIFO_Is_Empty)   // if Not popped , check if the buffer is empty
			printf("\n\t Popping Failed -- Stack Is Empty");        // if yes, print Stack is empty
	}
	printf("\n====================================\n");
	printf("========= LIFO Re-Pushing ==========");

	/** Re-Pushing elements to Stack **/
	for(i = 5; i < length / 2 + 5; i++)
	{
		if(LIFO_Push_Item(&Uart_Buf, i) == LIFO_No_Error)           // Check if item pushed successfully
			printf("\n\t Urat_LIFO Push : %d",i);                   // print value pushed to stack
		else if(LIFO_Push_Item(&Uart_Buf, i) == LIFO_Is_Full)       // if not pushed , check if there is no space
			printf("\n\t Pushing Failed -- Stack Is Full");         // if yes , Print Stack is full
	}
	printf("\n====================================\n");
	LIFO_Print(&Uart_Buf);                                          // print Buffer to check everything is going well

	/*************** First LIFO Is Dynamic Memory Allocated ***************/
	// Allocate dynamic memory in heap
	Element_Type* Buffer2 = (Element_Type*) malloc(length*sizeof(Element_Type));

	printf("   *********** Dynamic *********** \n");
	LIFO_Init(&I2c_Buf, Buffer2, length);                           // Initialize I2c_Buf
	printf("=========== LIFO Pushing ===========");

	/** Pushing elements to Dynamic allocation memory lifo in heap **/
	for(i = 5; i < length + 5; i++)
	{
		if(LIFO_Push_Item(&I2c_Buf, i) == LIFO_No_Error)            // Check if item pushed successfully
			printf("\n\t I2c_LIFO Push : %d",i);                    // if yes,  print value pushed to heap
		else if(LIFO_Push_Item(&I2c_Buf, i) == LIFO_Is_Full)        // if not pushed , check if there is no space
			printf("\n\t Pushing Failed -- Stack Is Full");         // if yes , Print Stack is full
	}
	printf("\n====================================\n");
	LIFO_Print(&I2c_Buf);                                           // print Buffer to check everything is going well

	printf("=========== LIFO Popping ===========");

	/** Popping elements to Dynamic allocation memory lifo in heap **/
	for(i = length / 2; i > 0; i--)
	{
		if(LIFO_Pop_Item(&I2c_Buf, &temp) == LIFO_No_Error)         // Check if item popped Successfully
			printf("\n\t I2c_LIFO Pop : %d", temp);                 // print value popped from heap
		else if(LIFO_Pop_Item(&Uart_Buf, &temp) == LIFO_Is_Empty)   // if Not popped , check if the buffer is empty
			printf("\n\t Popping Failed -- Stack Is Empty");        // if yes, print Stack is empty
	}
	printf("\n====================================\n");

	/**Re-Pushing elements to Dynamic allocation memory lifo in heap **/
	for(i = 10; i < length / 2 + 10; i++)
	{
		if(LIFO_Push_Item(&I2c_Buf, i) == LIFO_No_Error)            // Check if item pushed successfully
			printf("\n\t I2c_LIFO Push : %X",i);                    // if yes,  print value pushed to heap
		else if(LIFO_Push_Item(&I2c_Buf, i) == LIFO_Is_Full)        // if not pushed , check if there is no space
			printf("\n\t Pushing Failed -- Stack Is Full");         // if yes , Print Stack is full
	}
	printf("\n====================================\n");
	LIFO_Print(&I2c_Buf);                                           // print Buffer to check everything is going well


	free(Buffer2);                                                  // Free memory allocated

}
