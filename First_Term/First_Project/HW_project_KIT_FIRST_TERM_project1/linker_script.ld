/* Learn-In-Depth
   First_Term --> First_Project --> High_Pressure_Detection_System project
   Cortex-M3 Linker
   Eng. Mina Gamil 
*/

MEMORY 
{
	flash(rx) : ORIGIN = 0x08000000 , LENGTH = 128k
	sram(rwx) : ORIGIN = 0x20000000 , LENGTH = 20k
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;             /* Symbol of End of Text in flash - Symbol of Start of data in flash */
	}> flash

	.data : {
		_S_data = .;            /* Symbol of Start of .data section in Sram*/
		*(.data)
		_E_data = .;            /* Symbol of End of .data Section in Sram */
	}> sram AT>flash 

	.bss : {
		_S_bss = .,            /* Symbol of Start of .bss section in Sram */
		*(.bss)
		. = ALIGN(4);
		_E_bss = .,            /* Symbol of End of .bss section in Sram */
		. = . + 0x1000;        /* Create Stack Area */
		_stack_top = .;        /* Assign last Address to stack pointer Address symbol */
	}> sram
}