/*
 * ADC_prog.c
 *
 *  Created on: 8 Feb 2019
 *      Author: Laptop Market
 */

#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"
#include "AVR_ADC_REG.h"
#include "ADC_interface.h"
#include "AVR_INTP_REG.h"

#define Null 0

extern u32 au32_ChannelValues[8];
extern u8 channel;
volatile u8 ADC_Flag=0;

#if ADC_INTP == ADC_INTP_ENABLE
void __vector_16(void) __attribute__((signal,used));

void __vector_16(void)
{
	static u8 channel;
#if ADC_RES == ADC_8BIT_RES
		//Save the value
	au32_ChannelValues[channel]=ADCH;
	channel++;
	if(channel>7)
		ADC_Flag=1;
	#elif ADC_RES == ADC_10BIT_RES
		au32_ChannelValues[channel] =ADCL | (((u16)ADCH)<<8);	//shifting left the ADCH to get the reading in one step
	#endif
//		SET_BIT(ADCSRA,ADCSRA_ADIF);

}

#endif

/*
 * Init function for adc
 * No input
 * No output
 *
 */
void ADC_vidInit()
{

	#if ADC_RES == ADC_8BIT_RES
		//Select Adj left
		SET_BIT(ADMUX,ADMUX_ADLAR);
	#elif ADC_RES==ADC_10BIT_RES
		//Select Adj right
		CLEAR_BIT(ADMUX,ADMUX_ADLAR);
	#endif

	#if ADC_REF == ADC_AREF
		//Select Ref AREF PIN
		CLEAR_BIT(ADMUX,ADMUX_REFS0);
		CLEAR_BIT(ADMUX,ADMUX_REFS1);
	#elif ADC_REF == ADC_AVCC
		//Select Ref AVCC
		SET_BIT(ADMUX,ADMUX_REFS0);
		CLEAR_BIT(ADMUX,ADMUX_REFS1);
	#elif	ADC_REF == ADC_HALF_INT_REF
		//Select Ref  Half AVCC
		SET_BIT(ADMUX,ADMUX_REFS0);
		SET_BIT(ADMUX,ADMUX_REFS1);
	#endif

	#if ADC_INTP == ADC_INTP_ENABLE
		SET_BIT(ADCSRA,ADCSRA_ADIE);
		SET_BIT(SREG,SREG_GIE);

	#elif ADC_INTP == ADC_INTP_DISABLE
		CLEAR_BIT(ADCSRA,ADCSRA_ADIE);
	#endif

	#if ADC_STATUS == ADC_ENABLE
		SET_BIT(ADCSRA,ADCSRA_ADEN);

		switch (ADC_PRESCALER) {
			case ADC_2PRESCALER:	//PS0,PS2=0
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
				break;
			case ADC_4PRESCALER:		//PS0,PS2=2
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
				SET_BIT(ADCSRA,ADCSRA_ADPS1);
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
				break;
			case ADC_8PRESCALER:		//PS0,PS2=3
				SET_BIT(ADCSRA,ADCSRA_ADPS0);
				SET_BIT(ADCSRA,ADCSRA_ADPS1);
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
				break;
			case ADC_16PRESCALER:			//PS0,PS2=4
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
				SET_BIT(ADCSRA,ADCSRA_ADPS2);
				break;
			case ADC_32PRESCALER:			//PS0,PS2=5
				SET_BIT(ADCSRA,ADCSRA_ADPS0);
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
				SET_BIT(ADCSRA,ADCSRA_ADPS2);
				break;
			case ADC_64PRESCALER:			//PS0,PS2=6
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
				SET_BIT(ADCSRA,ADCSRA_ADPS1);
				SET_BIT(ADCSRA,ADCSRA_ADPS2);
				break;
			case ADC_128PRESCALER:			//PS0,PS2=7
				SET_BIT(ADCSRA,ADCSRA_ADPS0);
				SET_BIT(ADCSRA,ADCSRA_ADPS1);
				SET_BIT(ADCSRA,ADCSRA_ADPS2);
				break;
			default:
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
				CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
				break;
		}
	#endif

	return;
}

/*
 * Convert function
 *	input: channel num
 *	output: error state
 */
u8 ADC_u8GetAdcReading(u8 COPY_u8Channel ,u32* COPY_pu8Value )
{
	u8 LOC_u8Err=0;

	if(COPY_pu8Value==Null)
	{
		LOC_u8Err=1;
	}else if(COPY_u8Channel>ADC_u8MAX_CH_NUM || COPY_u8Channel<0)
	{
		LOC_u8Err=1;
	}else
	{
//Clear prev setting
ADMUX &=(0b11100000);
//set the channel
ADMUX	|=	COPY_u8Channel;
//Start Conversion
SET_BIT(ADCSRA,ADCSRA_ADSC);
#if ADC_INTP == ADC_INTP_DISABLE
//Wait for flag
	while(!GET_BIT(ADCSRA,ADCSRA_ADIF));
	#if ADC_RES == ADC_8BIT_RES
		//Save the value
		*COPY_pu8Value=ADCH;
	#elif ADC_RES == ADC_10BIT_RES
		*COPY_pu8Value =ADCL | (((u16)ADCH)<<8);	//shifting left the ADCH to get the reading in one step
	#endif
	//Clear the flag
	SET_BIT(ADCSRA,ADCSRA_ADIF);

#elif ADC_INTP == ADC_INTP_ENABLE
{	if(GET_BIT(ADCSRA,ADCSRA_ADIF))
		*COPY_pu8Value=au32_ChannelValues[COPY_u8Channel];
}
#endif
	}
	return LOC_u8Err;
}
