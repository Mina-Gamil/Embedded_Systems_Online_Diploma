/* Learn In Depth 
   Unit3_Lesson2_Lab1
   MAstering Learn In Depth Online Diploma */


ENTRY(reset)

MEMORY
{
	Mem (rwx): ORIGIN = 0x000000000, LENGTH = 64M        
}

SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}> Mem
	.text :
	{
		*(.text) *(.rodata)
	}> Mem
	.data :
	{
		*(.data)
	}> Mem
	.bss :
	{
		*(.bss) *(COMMON)
	}> Mem

	. = . + 0x1000;            /* Create Stack Section of 4KB */
	stack_top = . ;            /* ASSIGN Sympol stack_top to the top stack address*/
}