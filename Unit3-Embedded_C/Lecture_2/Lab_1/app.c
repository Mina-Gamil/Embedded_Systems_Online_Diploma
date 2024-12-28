/**
 ***********************************************************
 * @file        : app.c
 * @author      : Mina Gamil
 * @date        : 27 Dec 2024
 * @brief       : First Embedded lab Send data To UART
 ***********************************************************
 */


/** INCLUDE USED HEADER FILES **/
#include "uart.h"

/***** Declare And Initialize String To Send *****/
uint8 string_buffer[100] = "Learn-In-Depth : Mina";

/** Main Body Program **/
void main(void)
{
	/** Call vUart0_Send_String to send data to UART **/
	vUart0_Send_String(string_buffer);
}