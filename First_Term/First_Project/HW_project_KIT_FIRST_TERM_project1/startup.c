/**
 ********************************************************
 * @file        : startup.c
 * @author      : Mina Gamil 
 * @date        : 3 Jan. 2025
 * @brief       : Startup file for Arm Cortex-m3 
 ********************************************************
 */

/******* INCLUDE PLATFORM TYPES ********/
#include "Platform_Types.h"

/*** Declare Extern From Linker File***/
extern int main(void);
extern uint32 _stack_top;
extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;
uint32 i;


/*** Prototype of Reset and Default Handler ***/
void Reset_Handler();
void Default_Handler();

/** Prototype of Interrupts Handler with weak and alias **/
void NMI_Handler()__attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler()__attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler()__attribute__((weak, alias("Default_Handler")));
void Bus_Fault()__attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler()__attribute__((weak, alias("Default_Handler")));

/** vector interrupts table start with stack pointer address **/
uint32 vectors[]__attribute__((section(".vectors"))) = 
{
	(uint32) &_stack_top,
	(uint32) &Reset_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &MM_Fault_Handler,
	(uint32) &Bus_Fault,
	(uint32) &Usage_Fault_Handler
};

/** Default_Handler function **/
void Default_Handler()
{
	Reset_Handler();
}

/*** Reset_Handler Function **/
void Reset_Handler()
{
	/** Get the Size of .data Section **/ 
	uint32 Data_Size = (uint8*)&_E_data - (uint8*)&_S_data;
	uint8* pSrc = (uint8*)&_E_text;   /* Assign Source pointer*/
	uint8* pDst = (uint8*)&_S_data;   /* Assign Destination pointer*/
	for (i = 0; i < Data_Size; i++)
	{
		/** Looping to Copy data from flash to Sram **/
		*((uint8*)pDst++) = *((uint8*)pSrc++);
	}

	/** Get the Size of .bss section **/
	uint32 Bss_Size = (uint8*)&_E_bss - (uint8*)&_S_bss;
	pDst = (uint8*)&_S_bss;           /* Re-assign Destination pointer*/
	for (i = 0; i < Bss_Size; i++)
	{
		/** Looping to keep bss storage and initialize it to Zero**/
		*((uint8*)pDst++) = (uint8) 0;
	}

	/** Jump To main() After finishing of startup steps**/
	main();
}

