/*
 * LCD.h
 *
 * Created: 7/15/2025 1:47:47 PM
 *  Author: Mina
 */ 
#ifndef LCD_H_
#define LCD_H_


/* Including Used Headers*/
#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"

#define F_CPU 1000000UL
#define Eight_Bit_Mode

/* Port Config */
#define LCD_Port            GPIOA
#define LCD_Ctrl            GPIOA
#define RS_Switch           GPIO_PIN_8
#define RW_Switch           GPIO_PIN_9
#define EN_Switch           GPIO_PIN_10

/* Bit Config */
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

/* Cursor or Display shift */
#define LCD_Display_Shift			  0x08
#define LCD_Cursor_Move				  0x00
#define LCD_Shift_Right				  0x04
#define LCD_Shift_Left				  0x00

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
void HAL_LCD_Init(void);
void HAL_LCD_Kick(void);
void HAL_LCD_Is_Busy(void);
void HAL_LCD_Clear_Display(void);
void HAL_LCD_Send_Command(unsigned char Command);
void HAL_LCD_Write_Character(unsigned char Character);
void HAL_LCD_Write_String(char *String);
void HAL_LCD_GoTo_XY(int Line, int Position);
void HAL_LCD_Blink_On(void);
void HAL_LCD_Blink_Off(void);
void HAL_LCD_Cursor_On(void);
void HAL_LCD_Cursor_Off(void);
void HAL_LCD_Display_On(void);
void HAL_LCD_Display_Off(void);


#endif /* LCD_H_ */
