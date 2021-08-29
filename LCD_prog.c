/*

 * LCD_prog.c
 *
 *  Created on: 25 Jan 2019
 *      Author: Laptop Market
 */



/*
 * Write Command function
 * Input: Command
 * Output: Void
 *
 */
#include"STD_TYPES.h"
#include"AVR_DIO_REG.h"
#include"DIO_interface.h"
#include"LCD_interface.h"
#include"util/delay.h"


/*
 * Initialization Function
 * Input:void
 *	Output : void
 */

/* lcd commands */




void LCD_vidInitialize(void)
{
	DIO_u8SetPortDirection(LCD_u8DATA_PORT,(u8)0xFF);
	DIO_u8SetPortDirection(LCD_u8CONTROL_PORT,(u8)0xFF);
	DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8EN_PIN,DIO_enuOutput);
	DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8RS_PIN,DIO_enuOutput);
	DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8RW_PIN,DIO_enuOutput);

	_delay_ms(35);
//	read the busy flag
	/*function set
	 *	data length 8 bits
	 *	2 lines
	 *	big font
	 */
	LCD_vidWriteCommand(0b00111100);

	_delay_ms(1);
	/*
	 *Display on/of
	 *	display on
	 *	no cursor
	 *	no blinking
	 */
	LCD_vidWriteCommand(0b00001100);

	_delay_ms(1);
	/*clear display
	 *
	 *
	 */
	LCD_vidWriteCommand(0b00000001);

	_delay_ms(2);
	/*entry mode:
	 * mover to right
	 * no shift
	 */
	LCD_vidWriteCommand(0b00000110);

	return;
}

void LCD_vidWriteCommand(u8 COPY_u8Command)
{

	//DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8EN_PIN,DIO_enuLow);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8RS_PIN,DIO_enuLow);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8RW_PIN,DIO_enuLow);

	DIO_u8SetPortValue(LCD_u8DATA_PORT,COPY_u8Command);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8EN_PIN,DIO_enuHigh);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8EN_PIN,DIO_enuLow);
	return;
}

/*
 * Write Data function
 * Input: Command
 * Output: Void
 *
 */

void LCD_vidWriteData(u8 COPY_u8Data)
{

	//DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8EN_PIN,DIO_enuLow);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8RS_PIN,DIO_enuHigh);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8RW_PIN,DIO_enuLow);
	DIO_u8SetPortValue(LCD_u8DATA_PORT,COPY_u8Data);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8EN_PIN,DIO_enuHigh);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8EN_PIN,DIO_enuLow);

	return;
}

/*
 * Write String function
 * Input: String
 * Output: Void
 *
 */


void LCD_vidWriteString(u8* COPY_au8String)
{
	u8 LOC_u8Counter=0;
	while(COPY_au8String[LOC_u8Counter]!='\0')
	{
		LCD_vidWriteData(COPY_au8String[LOC_u8Counter]);
		LOC_u8Counter++;
	}

	return;
}

void LCD_vidIntToString(u32 COPY_u8Integar , u8* COPY_pu8String)
{
	u32 LOC_u8Num=COPY_u8Integar;
	u8 LOC_u8Size=0;
	while(LOC_u8Num>0)
	{
		LOC_u8Size++;
		LOC_u8Num/=10;
	}
	for(u8 i=0;i<LOC_u8Size;i++)
	{
		COPY_pu8String[(LOC_u8Size-1)-i]=( COPY_u8Integar %10 ) +'0';
		COPY_u8Integar/=10;
	}
	COPY_pu8String[LOC_u8Size]='\0';

	return;
}

/*
 * Go to XY coordinates
 * input : row
 * colum
 * output: void
 */

void LCD_vidGoTo_XY(u8 COPY_u8Row , u8 COPY_u8Column )
{

u8 LOC_au8FirstCharAdd[]={0x80,0xC0};
LCD_vidWriteCommand(LOC_au8FirstCharAdd[COPY_u8Row-1] + COPY_u8Column-1);
_delay_us(100);
}


//LCD_init();

//	u8* LOC_Pu8String;
//	LCD_vidGoTo_XY(2,5);
//	LCD_vidIntToString(98725,LOC_Pu8String);
//	LCD_vidWriteString(LOC_Pu8S-tring);
