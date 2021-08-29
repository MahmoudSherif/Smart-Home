/*

 * SMARTHOME_APP.c
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
#include "util/delay.h"
#include "SMARTHOME_interface.h"
#include "TEMP_SENSOR_interface.h"
#include "LDR_interface.h"
#include "ADC_interface.h"
volatile u32 au32_ChannelValues[8]={0,0,0,0,0,0,0,0};

volatile u8 IntpCase=SHOME_START_STATE;
volatile u8 LOC_u8Trials=0;
volatile u8 FLAG=0;

volatile u8 channel=0;
extern u8 ADC_Flag;
void main(void)
{

	DIO_u8SetPinDirection(DIO_enuPORTA,DIO_enuPIN2,DIO_enuOutput);
	DIO_u8SetPinDirection(DIO_enuPORTA,DIO_enuPIN3,DIO_enuOutput);
	DIO_u8SetPinDirection(DIO_enuPORTB,DIO_enuPIN7,DIO_enuOutput);
	DIO_u8SetPinValue(DIO_enuPORTA,DIO_enuPIN2,DIO_enuLow);
//	DIO_u8SetPinValue(DIO_enuPORTB,DIO_enuPIN7,DIO_enuLow);


	u8 LOC_au8Password[4]={0};
	u8 LOC_au8RPAS[4]={1,2,3,4};
	u8 k=0;
	u8 flag=0;

	u8 LOC_u8KeyPressed;
	u8* LOC_pu8String;
	KPD_vidInit();
	INTP_vidInit();
	LCD_vidInitialize();
	LDR_vidInit();
	TEMP_vidInit();

while(1)
{

	DIO_u8SetPinValue(DIO_enuPORTB,DIO_enuPIN7,DIO_enuLow);
	while(FLAG)
	{
		if(LOC_u8Trials<3)
		{	KPD_vidGetKey(&LOC_u8KeyPressed);
			if(LOC_u8KeyPressed!=0)
			{
				LOC_au8Password[k]=LOC_u8KeyPressed;
				LCD_vidIntToString(LOC_au8Password[k],LOC_pu8String);
				LCD_vidWriteString(LOC_pu8String);
				k++;
				if(k==4)
				{
					for(u8 i=0;i<=3;i++)
					{
						if(LOC_au8Password[i]==LOC_au8RPAS[i])
							flag++;
					}
						if(flag==4)
							{
									LCD_vidWriteCommand(LCD_u8CLEAR_DISPLAY);
									DIO_u8SetPinValue(DIO_enuPORTA,DIO_enuPIN3,DIO_enuHigh);
									IntpCase=SHOME_NO_STATE;
									INTP_vidIntp2Enable();
									IntpCase=SHOME_OFF_STATE;
									DIO_u8SetPinValue(DIO_enuPORTB,DIO_enuPIN7,DIO_enuLow);
									k=0;
									flag=0;
									DIO_u8SetPinValue(DIO_enuPORTB,DIO_enuPIN7,DIO_enuLow);
									while(IntpCase==SHOME_OFF_STATE)
									{
										LCD_vidGoTo_XY(1,1);
										TEMP_vidDisplayOnLCD();
										LCD_vidWriteData(' ');
										LDR_vidDisplayOnLCD();

									}
							}else
							{
								LOC_u8Trials++;
								k=0;
								flag=0;
								LCD_vidWriteCommand(LCD_u8CLEAR_DISPLAY);
							}
				}

			}


		}else if (LOC_u8Trials>2)
		{
			IntpCase=SHOME_NO_STATE;
			INTP_vidIntp2Enable();
			IntpCase=SHOME_OFF_STATE;
			DIO_u8SetPinValue(DIO_enuPORTB,DIO_enuPIN7,DIO_enuLow);
			while(IntpCase==SHOME_OFF_STATE)
			{
				LCD_vidGoTo_XY(1,1);
				LCD_vidWriteString("System is locked");
			}
		}
	}

}
	return;
}

