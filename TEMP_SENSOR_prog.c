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
#include "TEMP_SENSOR_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"


extern u32 au32_ChannelValues[8];

/*
 * Init temp sensor function
 * Input: None
 * Output: None
 *
 */

void TEMP_vidInit()
{
//	if(			)		;//setting Channel as Input

			DIO_u8SetPinDirection(ADC_PORT,TEMP_u8CHANNEL_NUM,DIO_enuInput);

//	{
		ADC_vidInit();		//Init ADC
//	}

	return;
}



/*
 * Temp sensor get value function
 * Input : Channel, Pointer to Value
 * Output: Error state
 */

u8 TEMP_u8GetValue(u8 COPY_u8Channel,u32* COPY_u8LevelValue)
{
	u8 LOC_u8Err=0;
	LOC_u8Err=ADC_u8GetAdcReading(COPY_u8Channel,COPY_u8LevelValue);
	(*COPY_u8LevelValue) =(*COPY_u8LevelValue)*500/ADC_RES_NUM;
	return LOC_u8Err;
}

/*
 * DISPLAY ON LCD function
 * Input void
 * Output void
 *
 */
void TEMP_vidDisplayOnLCD(void)
{
	u8 LOC_u8String[5];
//	u8 LOC_var;
//	LCD_vidWriteCommand(LCD_);
//	LCD_vidGoTo_XY(1,1);
	TEMP_u8GetValue(TEMP_u8CHANNEL_NUM,&au32_ChannelValues[TEMP_u8CHANNEL_NUM]);
	LCD_vidIntToString(au32_ChannelValues[TEMP_u8CHANNEL_NUM],LOC_u8String);
	LCD_vidWriteString(LOC_u8String);
	LCD_vidWriteData(' ');
	return;
}
