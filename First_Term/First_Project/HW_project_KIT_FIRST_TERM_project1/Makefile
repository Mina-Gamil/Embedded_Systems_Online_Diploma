#Makefile for High_Pressure_Detection_System

# Declare Macros to make Generic Makefile
CC           = arm-none-eabi-
CFLAGS       = -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS         = -I .
LIBS         =
SRC          = $(wildcard *.c)
OBJ          = $(SRC:.c=.o)
AS           = $(wildcard *.s)
ASOBJ        = $(AS:.s=.o)
Project_Name = main

all:$(Project_Name).hex
	@echo "*********** Build is Done ***********"

%.o:%.s
	$(CC)as $(CFLAGS) $< -o $@

%.o:%.c
	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf:$(ASOBJ) $(OBJ)
	$(CC)ld -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@ -M=Map_file.map

$(Project_Name).hex:$(Project_Name).elf
	$(CC)objcopy -O binary $< $@


clean:
	rm *.bin *elf *.hex
	@echo "*** All .bin/.elf files deleted ***"

clean_all:
	rm *.o *.bin *.elf *.map *.hex
	@echo "*** All built files deleted ***"
