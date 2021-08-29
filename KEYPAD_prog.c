/*
 * KEYPAD_prog.c
 *
 *  Created on: 30 Jan 2019
 *      Author: Laptop Market
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
//#include"AVR_DIO_REG.h"
#include"DIO_interface.h"
#include"util/delay.h"
#include"KEYPAD_interface.h"
#include "LCD_interface.h"
/*
 * KEYPAD initialization function
 * input : void
 * output: void
 *
 */
void KPD_vidInit(void)
{
	//setting rows pins as input and pulled up
	DIO_u8SetPortDirection(KPD_u8CONNECT_PORT,0xF0);
	DIO_u8SetPortValue(KPD_u8CONNECT_PORT,0xFF);
return;
}


/*
 * KEYPRESSED function
 * input: pointer to u8 [value that indicates the pressed button]
 * output: void
 */

//u8 LOC_au8SwitchID[4][4] = {{1 , 5 , 9 , 13},
//                            {2 , 6 , 10 , 14},
//                            {3 , 7 , 11 , 15},
//                            {4 , 8 , 12 , 16}
//                           };

u8 LOC_au8SwitchID[4][4] = {{1 , 2 , 3 , 4},
                            {5 , 6 , 7 , 8},
                            {9 , 10 , 11 , 12},
                            {13 , 14 , 15 , 16}
                           };


//void KBD_vidGetKey(u8 *COPY_pu8PressKey)
//{
//    u8 LOC_u8Col ;
//    u8 LOC_u8Row ;
//    u8 LOC_u8SwitchState ;
//    u8 LOC_au8SwitchID[4][4] = {{1 , 5 , 9 , 13},
//                                {2 , 6 , 10 , 14},
//                                {3 , 7 , 11 , 15},
//                                {4 , 8 , 12 , 16}
//                               };
//    for(LOC_u8Col = 0 ; LOC_u8Col < 4 ; LOC_u8Col++)
//    {
//        /* activate column by setting it to LOW */
//       DIO_u8SetPinValue(KPD_u8CONNECT_PORT , LOC_u8Col , DIO_enuLow);
//        /* scan for all rows to determine which switch connected to that column is pressed */
//        for(LOC_u8Row = 0 ; LOC_u8Row < 4 ; LOC_u8Row++)
//        {
//            /* get value of the switch */
//            DIO_u8GetPinValue(KPD_u8CONNECT_PORT , LOC_u8Row+4 , &LOC_u8SwitchState);
//            if(LOC_u8SwitchState == 0)
//            {
//                 *COPY_pu8PressKey = LOC_au8SwitchID[LOC_u8Row][LOC_u8Col] ;
//            }
//            else
//            {
//
//            }
//            /* if you want to wait until the user is not pressing the button */
//            /*while(LOC_u8SwitchState == 0)
//            {
//
//            }
//            COPY_pu8PressKey = LOC_au8SwitchID[LOC_u8Row][LOC_u8Col] ; */
//
//        }
//        /* deactivate the current column and switch to the next one */
//        DIO_u8SetPinValue(KPD_u8CONNECT_PORT , LOC_u8Col , DIO_enuHigh);
//    }
//}


void KPD_vidGetKey(u8* COPY_pu8KeyPressed)
{
	*COPY_pu8KeyPressed=0;
	u8 LOC_pu8Value;
	DIO_u8SetPortValue(KPD_u8CONNECT_PORT,0xFF);

	for(u8 col=KPD_u8MAX_COL_PIN-4 ; col<KPD_u8MAX_COL_PIN ;col++)
	{
		DIO_u8SetPinValue(KPD_u8CONNECT_PORT,col,DIO_enuLow);
		_delay_ms(20);

		for(u8 row=KPD_u8MAX_ROW_PIN-4 ; row<KPD_u8MAX_ROW_PIN ;row++)
		{
			do{

			DIO_u8GetPinValue(KPD_u8CONNECT_PORT,row,&LOC_pu8Value);

			if(LOC_pu8Value == DIO_enuLow)
			{

				*COPY_pu8KeyPressed=LOC_au8SwitchID[row][col-4];

			}}while(LOC_pu8Value == DIO_enuLow);

		}
		DIO_u8SetPortValue(KPD_u8CONNECT_PORT,0xFF);

	}
	return;
}
