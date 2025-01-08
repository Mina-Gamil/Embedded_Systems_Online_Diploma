/**
 ********************************************************
 * @file        : startup.c
 * @author      : Mina Gamil 
 * @date        : 4 Jan. 2025
 * @brief       : Startup file for Arm Cortex-m4 TM4C123
 ********************************************************
 */

/*** Declare Extern From Linker File***/
extern int main(void);
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
unsigned int i;


static unsigned long Stack_Top[256];

/*** Prototype of Reset and Default Handler ***/
void Reset_Handler();
void Default_Handler();

/** Prototype of Interrupts Handler with weak and alias **/
void NMI_Handler()__attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler()__attribute__((weak, alias("Default_Handler")));


/** vector interrupts table start with stack pointer address **/
void(* gP_fun_vectors[])()__attribute__((section(".vectors"))) = 
{
	(void(*)()) ((unsigned long)Stack_Top + sizeof(Stack_Top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler
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
	unsigned int Data_Size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* pSrc = (unsigned char*)&_E_text;   /* Assign Source pointer*/
	unsigned char* pDst = (unsigned char*)&_S_data;   /* Assign Destination pointer*/
	for (i = 0; i < Data_Size; i++)
	{
		/** Looping to Copy data from flash to Sram **/
		*((unsigned char*)pDst++) = *((unsigned char*)pSrc++);
	}

	/** Get the Size of .bss section **/
	unsigned int Bss_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	pDst = (unsigned char*)&_S_bss;           /* Re-assign Destination pointer*/
	for (i = 0; i < Bss_Size; i++)
	{
		/** Looping to keep bss storage and initialize it to Zero**/
		*((unsigned char*)pDst++) = (unsigned char) 0;
	}

	/** Jump To main() After finishing of startup steps**/
	main();
}

