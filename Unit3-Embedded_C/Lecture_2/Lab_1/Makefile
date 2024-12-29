#Makefile for lab_1 Unit3-Embedded_C

# Declare Macros to make Generic Makefile
CC           = arm-none-eabi-
CFLAGS       = -g -mcpu=arm926ej-s
INCS         = -I .
LIBS         =
SRC          = $(wildcard *.c)
OBJ          = $(SRC:.c=.o)
AS           = $(wildcard *.s)
ASOBJ        = $(AS:.s=.o)
Project_Name = lab_1

all:$(Project_Name).bin
	@echo "*********** Build is Done ***********"

%.o:%.s
	$(CC)as $(CFLAGS) $< -o $@

%.o:%.c
	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf:$(ASOBJ) $(OBJ)
	$(CC)ld -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $(Project_Name).elf -M=$(Project_Name)_Map.map

$(Project_Name).bin:$(Project_Name).elf
	$(CC)objcopy -O binary $(Project_Name).elf $(Project_Name).bin


clean:
	rm *.bin *elf
	@echo "*** All .bin/.elf files deleted ***"

clean_all:
	rm *.o *.bin *.elf *.map 
	@echo "*** All built files deleted ***"
