/*

 * SMARTHOME_prog.c
 *
 *  Created on: 12 Feb 2019
 *      Author: Laptop Market
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "AVR_INTP_REG.h"
#include "AVR_ADC_REG.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "INTERRUPT_interface.h"
#include "LCD_interface.h"




//		if(LOC_u8KeyPressed!=0)
//		{
//			if(LOC_u8KeyPressed==4)
//			{
//				INTP_vidIntp2Disable();
//				LCD_vidWriteCommand(LCD_u8CLEAR_DISPLAY);
//				LCD_vidGoTo_XY(1,1);
//				LCD_vidIntToString(LOC_u8KeyPressed,LOC_pu8String);
//				LCD_vidWriteString(LOC_pu8String);
//
//			}else if(LOC_u8KeyPressed==1)
//			{
//				INTP_vidIntp2Enable();
//			}else if(LOC_u8KeyPressed==13)
//			{
//				LCD_vidWriteCommand(LCD_u8CLEAR_DISPLAY);
//				LCD_vidGoTo_XY(1,1);
//				LCD_vidIntToString(LOC_u8KeyPressed,LOC_pu8String);
//				LCD_vidWriteString(LOC_pu8String);
//				DIO_u8SetPinValue(DIO_enuPORTA,DIO_enuPIN1,DIO_enuLow);
//			}
//		}
