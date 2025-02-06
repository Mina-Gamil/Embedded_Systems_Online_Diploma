#Makefile for High_Pressure_Detection_System

# Declare Macros to make Generic Makefile
CC           = 
CFLAGS       = 
INCS         = -I .
LIBS         =
SRC          = $(wildcard *.c)
OBJ          = $(SRC:.c=.o)
Project_Name = main


All:$(Project_Name).exe
	


$(Project_Name).exe:$(SRC)
	gcc $(SRC) -o $@ 



clean:
	rm *.bin *elf *.hex
	@echo "*** All .bin/.elf files deleted ***"

clean_all:
	rm *.o *.bin *.elf *.map *.hex
	@echo "*** All built files deleted ***"
