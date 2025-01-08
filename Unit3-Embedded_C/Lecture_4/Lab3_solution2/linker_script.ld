/* Learn-In-Depth
   Unit3-Lecture4_Lab3
   Cortex-M4 Linker
   Eng. Mina Gamil 
*/

MEMORY 
{
	flash(rx) : ORIGIN = 0x00000000 , LENGTH = 512M
	sram(rwx) : ORIGIN = 0x20000000 , LENGTH = 512M
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
		*(.stack)
		. = ALIGN(4);
		_E_bss = .,            /* Symbol of End of .bss section in Sram */

	}> sram
}