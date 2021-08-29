/*
 * ADC_interface.h
 *
 *  Created on: 8 Feb 2019
 *      Author: Laptop Market
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define LEFT_ADJ 0
#define RIGHT_ADJ 1


#define ADC_DISABLE 0
#define ADC_ENABLE 1

#define ADC_STATUS ADC_ENABLE

#define ADC_AVCC 0
#define ADC_AREF 1
#define ADC_HALF_INT_REF	2


#define ADC_PORT DIO_enuPORTA
//#define ADC_CHANNEL0 DIO_enuPIN



#define ADC_8BIT_RES 0
#define ADC_10BIT_RES 1

#define ADC_RES	ADC_8BIT_RES


#if ADC_RES == ADC_8BIT_RES
	#define ADC_RES_NUM 256;
#elif ADC_RES==ADC_10BIT_RES
	#define ADC_RES_NUM 1024;
#endif


#define ADC_PRESCALER	ADC_2PRESCALER

#define ADC_2PRESCALER	0
#define ADC_4PRESCALER	1
#define ADC_8PRESCALER	2
#define ADC_16PRESCALER	3
#define ADC_32PRESCALER	4
#define ADC_64PRESCALER	5
#define ADC_128PRESCALER 6

#define ADC_INTP_DISABLE 0
#define ADC_INTP_ENABLE	1

#define ADC_INTP   ADC_INTP_ENABLE


#define ADC_REF	ADC_EXT_REF

#define ADC_u8MAX_CH_NUM (u8)7




/*
 * Init function for adc
 * No input
 * No output
 *
 */
void ADC_vidInit();
/*
 * Convert function
 *	input: channel num
 *	output: error state
 */
u8 ADC_u8GetAdcReading(u8 COPY_u8Channel ,u32* COPY_pu8Value );

#endif /* ADC_INTERFACE_H_ */
