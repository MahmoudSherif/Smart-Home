/*
 * AVR_ADC_REG.h
 *
 *  Created on: 8 Feb 2019
 *      Author: Laptop Market
 */

#ifndef AVR_ADC_REG_H_
#define AVR_ADC_REG_H_

#define ADMUX (*(volatile u8*)(0x27))	//contains the multiplexer to choose which channel to use and the ADLAR to choose left or right adj and the 2 bits for choosing the ref.
#define ADCSRA (*(volatile u8*)(0x26))	//contains the prescaler bits and interrupt enable bit and flag,auto trigger and start conversion bit and enable bit for adc
#define ADCH (*(volatile u8*)(0x25))		// the second reg for saving part of the value of the adc
#define ADCL (*(volatile u8*)(0x24))		// the first reg for saving part of the value of the adc
#define SFIOR (*(volatile u8*)(0x50))	//contains the source of the trigger mode

//for ADMUX Register
#define ADMUX_MUX0 	(u8)0		//0,4mux bits to choose the channel
#define ADMUX_MUX1 	(u8)1
#define ADMUX_MUX2 	(u8)2
#define ADMUX_MUX3 	(u8)3
#define ADMUX_MUX4 	(u8)4
#define ADMUX_ADLAR (u8)5		//to choose the left adj or right adj
#define ADMUX_REFS0 (u8)6		//6,7to choose the ref source
#define ADMUX_REFS1 (u8)7


//for ADCSRA Register
#define ADCSRA_ADPS0 (u8)0		//0,2 prescaler pins
#define ADCSRA_ADPS1 (u8)1
#define ADCSRA_ADPS2 (u8)2
#define ADCSRA_ADIE (u8)3		//ADC_interrupt enable
#define ADCSRA_ADIF (u8)4		//ADC interrupt Flag
#define ADCSRA_ADATE (u8)5		//Auto trigger enable
#define ADCSRA_ADSC (u8)6		//start conversion bit
#define ADCSRA_ADEN (u8)7		//ADC enable bit

//for SFIOR Register

#define SFIOR_ADTS0	u8(5)		//5,7 trigger source
#define SFIOR_ADTS1	u8(6)
#define SFIOR_ADTS2	u8(7)


#endif /* AVR_ADC_REG_H_ */
