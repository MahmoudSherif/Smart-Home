/*

 * LDR_prog.c
 *
 *  Created on: 14 Feb 2019
 *      Author: Laptop Market
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "AVR_ADC_REG.h"
#include "AVR_INTP_REG.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"


#include "LDR_interface.h"

extern u32 au32_ChannelValues[8];

/*
 * Init LDR function
 * Input: None
 * Output: None
 *
 */

void LDR_vidInit()
{
//	if(			)		;//setting Channel as Input

			DIO_u8SetPinDirection(DIO_enuPORTA,LDR_u8CHANNEL_NUM,DIO_enuInput);
//	{
		ADC_vidInit();		//Init ADC
//	}

	return;
}



/*
 * LDR Levels function
 * Input : Channel, Pointer to LevelValue (in scale 5)
 * Output: Error state
 */

u8 LDR_u8GetValue(u8 COPY_u8Channel,u32* COPY_u8LevelValue)
{
	u8 LOC_u8Err=0;
	LOC_u8Err=ADC_u8GetAdcReading(COPY_u8Channel,COPY_u8LevelValue);
	(*COPY_u8LevelValue) =(*COPY_u8LevelValue)*5/ADC_RES_NUM;
	(*COPY_u8LevelValue)+=1;
	return LOC_u8Err;
}

/*
 * DISPLAY ON LCD function
 * Input void
 * Output void
 *
 */
void LDR_vidDisplayOnLCD(void)
{
	u8 LOC_u8String[5];
//	LCD_vidWriteCommand(LCD_);
//	LCD_vidGoTo_XY(1,1);
	LDR_u8GetValue(LDR_u8CHANNEL_NUM,&au32_ChannelValues[LDR_u8CHANNEL_NUM]);
	LCD_vidIntToString(au32_ChannelValues[LDR_u8CHANNEL_NUM],LOC_u8String);
	LCD_vidWriteString(LOC_u8String);
	LCD_vidWriteData(' ');
	return;
}
