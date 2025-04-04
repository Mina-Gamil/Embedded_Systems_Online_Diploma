/*
 * LCD.h
 *
 * Created: 3/30/2025 1:47:47 PM
 *  Author: Mina
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "MemoryMap.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define Eight_Bit_Mode

/* Port Config */
#define LCD_Port            PORTA
#define LCD_Port_Pin        PINA
#define LCD_Port_Dir        DDRA
#define LCD_Ctrl            PORTB
#define LCD_Ctrl_Dir        DDRB
#define RS_Switch           1
#define RW_Switch           2
#define EN_Switch           3

#ifdef Eight_Bit_Mode
#define Data_Shift          0  // 0-> 8-bit Mode :: 4-> 4-bit Mode
#else
#define Data_Shift          4  // 0-> 8-bit Mode :: 4-> 4-bit Mode
#endif

/* Basic Commands */
#define LCD_ClearDisplay              0x01
#define LCD_ReturnHome                0x02
#define LCD_EntryModeSet              0x04
#define LCD_DisplayControl            0x08
#define LCD_CursorOrDisplayShift      0x10
#define LCD_FunctionSet               0x20
#define LCD_DDRAM_Address             0x80

/* Entry Mode Set Commands */
#define LCD_Right_Dec                 0x00
#define LCD_Right_Inc                 0x01
#define LCD_Left_Dec                  0x02
#define LCD_Left_Inc                  0x03

/* Display On/Off Control Commands */
#define LCD_Blink                     0x01
#define LCD_Cursor                    0x02
#define LCD_Display                   0x04

/* Function Set Commands */
#define LCD_4bit_Mode                 0x00
#define LCD_8bit_Mode                 0x10
#define LCD_1Line                     0x00
#define LCD_2Line                     0x08
#define LCD_5x8_Dot                   0x00
#define LCD_5x10_Dot                  0x04

/* DDRAM Address Cursor Options */
#define LCD_1st_Line                      0x00
#define LCD_2nd_Line                      0x40

/* API'S */

void LCD_Init(void);
void LCD_Kick(void);
void LCD_Is_Busy(void);
void LCD_Clear_Display(void);
void LCD_Send_Command(unsigned char Command);
void LCD_Send_Character(unsigned char Character);
void LCD_Send_String(char *String);
void LCD_Blink_On(void);
void LCD_Blink_Off(void);
void LCD_Cursor_On(void);
void LCD_Cursor_Off(void);
void LCD_Display_On(void);
void LCD_Display_Off(void);


#endif /* LCD_H_ */