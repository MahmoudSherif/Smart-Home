/*
 * LCD_interface.h
 *
 *  Created on: 25 Jan 2019
 *      Author: Laptop Market
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_u8DATA_PORT DIO_enuPORTC
#define LCD_u8CONTROL_PORT DIO_enuPORTD

#define LCD_u8EN_PIN DIO_enuPIN0
#define LCD_u8RS_PIN DIO_enuPIN1
#define LCD_u8RW_PIN DIO_enuPIN2

#define LCD_u8CLEAR_DISPLAY (u8)0x01
#define LCD_u8RETURN_HOME (u8)0x02
#define LCD_u8DECREMENT_CURSOR (u8)0x04
#define LCD_u8INCREMENT_CURSOR (u8)0x06
#define LCD_u8SHIFT_DISPLAY_RIGHT (u8)0x05
#define LCD_u8SHIFT_DISPLAY_LEFT (u8)0x07
#define LCD_u8DISPLAY_OFF (u8)0x08
#define LCD_u8CURSOR_OFF (u8)0x0C
#define LCD_u8CURSOR_BLINKING (u8)0x0E
#define LCD_u8SHIFT_CURSOR_LEFT (u8)0x10
#define LCD_u8SHIFT_CURSOR_RIGHT (u8)0x14
#define LCD_u8FORCE_FIRST_LINE (u8)0x80
#define LCD_u8FORCE_SECOND_LINE (u8)0xC0
#define LCD_u8FOUR_BIT_MODE (u8)0x28
#define LCD_u8EIGHT_BIT_MODE (u8)0x38
#define LCD_u8SET_CGRAM_ADDRESS (u8)0x40

/*
 * Initialization Function
 * Input:void
 *	Output : void
 */

void LCD_vidInitialize(void);
/*
 * Write Command function
 * Input: Command
 * Output: Void
 *
 */

void LCD_vidWriteCommand(u8 COPY_u8Data);


/*
 * Write Data function
 * Input: Command
 * Output: Void
 *
 */

void LCD_vidWriteData(u8 COPY_u8Data);

/*
 * Write String function
 * Input: String
 * Output: Void
 *
 */

void LCD_vidWriteString(u8* COPY_au8String);


/*
 *	Send integar and display characters
 * input : integar number
 * 	pointer to char
 * 	output: void
 */

void LCD_vidIntToString(u32 COPY_u8Integer , u8* COPY_pu8Str);

/*
 * Go to XY coordinates
 * input : row
 * colum
 * output: void
 */
void LCD_vidGoTo_XY(u8 COPY_u8Row , u8 COPY_u8Column );

#endif /* LCD_INTERFACE_H_ */
