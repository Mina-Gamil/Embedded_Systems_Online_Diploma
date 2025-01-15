/**
 *************************************************
 *@file       :  main.c
 *@author     :  Mina Gamil
 *@Created on :  Jan 11, 2025
 *@brief      :  Main program body testing fifo.h
 *************************************************
 **/

/* INCLUDE Needed Headers */
#include "fifo.h"
#include <stdlib.h>

/** Declare System Fifo **/
FIFO_Buf_t Uart_fifo, I2c_fifo;

/**** Declare needed Variables ***/
unsigned int i, length = 5;
Element_Type temp, Buffer1[5];

/***** Main Program Body *****/
void main(void)
{
	/** Init Uart fifo with Static Memory Allocation **/
	if(FIFO_Init(&Uart_fifo, Buffer1, length) == FIFO_No_Error)                           // Check if Buffer initialized successfully
		printf("---> Static Allocate Queue -- Initialized Done \n\n");                    // print the initialization done

	/** Looping for Enqueue **/
	for(i = 0; i <= length; i++)
	{
		printf("--> FIFO Enqueue (%x) :\n",i);                                            // start Enqueue items in queue
		if(FIFO_Enqueue(&Uart_fifo, i) == FIFO_No_Error)                                  // Check if Enqueue done Successfully
			printf("\t -> FIFO Enqueue (%x) -- Done Successfully\n",i);                   // print that Enqueue done
		else if(FIFO_Enqueue(&Uart_fifo, i) == FIFO_Is_Full)                              // if not done , check if the API return is full
			printf("\t -> FIFO Enqueue (%x) -- Failed -> Full Queue \n",i);               // print that Enqueue failed because of full queue
	}
	FIFO_Print(&Uart_fifo);                                                               // print queue with addresses and values to check everything is correct

	/** Looping for Dequeue **/
	for(i = 0; i <= length/2; i++)
	{
		printf("\n--> FIFO Dequeue :\n");                                                 // Start dequeue items from queue
		if(FIFO_Dequeue(&Uart_fifo, &temp) == FIFO_No_Error)                              // Check if Dequeue done Successfully
			printf("\t -> FIFO Dequeue (%d) -- Done Successfully\n", temp);               // print that Dequeue done
		else if(FIFO_Dequeue(&Uart_fifo, &temp) == FIFO_Is_Empty)                         // if not done, check if the API return Is Empty
			printf("\t -> FIFO Dequeue (-) -- Failed -> Empty Queue\n");                  // print that Dequeue failed because of Empty queue
	}
	FIFO_Print(&Uart_fifo);                                                               // print queue with addresses and values to check everything is correct

	/** Looping for Re-Enqueue **/
	for(i = 5; i <= 7; i++)
	{
		printf("--> FIFO Enqueue (%x) :\n",i);                                            // Start Enqueue Again
		if(FIFO_Enqueue(&Uart_fifo, i) == FIFO_No_Error)                                  // Check if Enqueue done Successfully
			printf("\t -> FIFO Enqueue (%x) -- Done Successfully\n",i);                   // print that Enqueue done
		else if(FIFO_Enqueue(&Uart_fifo, i) == FIFO_Is_Full)                              // if not done , check if the API return is full
			printf("\t -> FIFO Enqueue (%x) -- Failed -> Full Queue \n",i);               // print that Enqueue failed because of full queue
	}
	FIFO_Print(&Uart_fifo);                                                               // print queue with addresses and values to check everything is correct

	/** Use Dynamic Memory Allocation to make Buffer2**/
	Element_Type* Buffer2 = (Element_Type*) malloc(length * sizeof(Element_Type));

	/** Init I2c fifo with Dynamic Memory Allocation in Heap **/
	if(FIFO_Init(&I2c_fifo, Buffer2, length) == FIFO_No_Error)                            // Check if Buffer initialized successfully
		printf("\n---> Dynamic Allocate Queue -- Initialized Done\n\n");                  // print the initialization done

	/** Looping for Enqueue **/
	for(i = 5; i <= length + 5; i++)
	{
		printf("--> FIFO Enqueue (%x) :\n",i);                                            // start Enqueue items in queue
		if(FIFO_Enqueue(&I2c_fifo, i) == FIFO_No_Error)                                   // Check if Enqueue done Successfully
			printf("\t -> FIFO Enqueue (%x) -- Done Successfully\n",i);                   // print that Enqueue done
		else if(FIFO_Enqueue(&I2c_fifo, i) == FIFO_Is_Full)                               // if not done , check if the API return is full
			printf("\t -> FIFO Enqueue (%x) -- Failed -> Full Queue \n",i);               // print that Enqueue failed because of full queue
	}
	FIFO_Print(&I2c_fifo);                                                                // print queue with addresses and values to check everything is correct

	/** Looping for Dequeue **/
	for(i = 0; i <= length/2; i++)
	{
		printf("\n--> FIFO Dequeue :\n");                                                 // Start dequeue items from queue
		if(FIFO_Dequeue(&I2c_fifo, &temp) == FIFO_No_Error)                               // Check if Dequeue done Successfully
			printf("\t -> FIFO Dequeue (%d) -- Done Successfully\n", temp);               // print that Dequeue done
		else if(FIFO_Dequeue(&I2c_fifo, &temp) == FIFO_Is_Empty)                          // if not done, check if the API return Is Empty
			printf("\t -> FIFO Dequeue (-) -- Failed -> Empty Queue\n");                  // print that Dequeue failed because of Empty queue
	}
	FIFO_Print(&I2c_fifo);                                                                // print queue with addresses and values to check everything is correct

	/** Looping for Re-Enqueue **/
	for(i = 10; i <= 10 + length / 2; i++)
	{
		printf("--> FIFO Enqueue (%x) :\n",i);                                            // Start Enqueue Again
		if(FIFO_Enqueue(&I2c_fifo, i) == FIFO_No_Error)                                   // Check if Enqueue done Successfully
			printf("\t -> FIFO Enqueue (%x) -- Done Successfully\n",i);                   // print that Enqueue done
		else if(FIFO_Enqueue(&I2c_fifo, i) == FIFO_Is_Full)                               // if not done , check if the API return is full
			printf("\t -> FIFO Enqueue (%x) -- Failed -> Full Queue \n",i);               // print that Enqueue failed because of full queue
	}
	FIFO_Print(&I2c_fifo);                                                                // print queue with addresses and values to check everything is correct

	free(Buffer2);                                                                        // free Allocated buffer2
}
