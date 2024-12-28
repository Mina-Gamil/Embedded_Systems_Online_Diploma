/**
 ******************************************************
 * @file        : uart.c
 * @author      : Mina Gamil
 * @date        : 27 Dec 2024
 * @brief       : Uart Program To Send String 
 ******************************************************
 */


/** INCLUDE USED HEADER FILES **/
#include "uart.h"

/*** Define UART0DR LOCATION ADDRESS ***/
#define UART0DR    *((vuint32* const)((uint32*)0x101f1000))

/** void vUart0_Send_String to send data to UART **/
void vUart0_Send_String(uint8* P_TX_String)
{	/* Loop while NULL */
	while(*P_TX_String != '\0')
	{
		UART0DR = (uint32)(*P_TX_String);        /* Send Byte for Uart */
		P_TX_String++;                         /* Increment Address */
	}
}