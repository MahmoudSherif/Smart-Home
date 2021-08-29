/*
 * AVR_INTP_REG.h
 *
 *  Created on: 2 Feb 2019
 *      Author: Laptop Market
 */

#ifndef AVR_INTP_REG_H_
#define AVR_INTP_REG_H_

#define SREG (*(u8*)(0x5F))		//Global Interrupt Register
#define GICR (*(u8*)(0x5B))		//(General Interrupt Control)Peripheral Interrupt Enables
#define GIFR (*(u8*)(0x5A))		// Register Peripheral Interrupt Flags
#define MCUCR (*(u8*)(0x55))	//MCU Control Register to control interrupt zero and one (INT0, INT1)
#define MCUCSR (*(u8*)(0x54))	//MCU Control and Status Register to control interrupt two (INT2)
//
//#define SREG *((volatile u8*)0x5F) // Control one pit in GIE global interrupt enable
//#define MCUCR *((volatile u8*)0x55)//control event at rising edge OR falling edge or any other edge for interrupt 0& 1
//#define MCUCSR *((volatile u8*)0x54) // for interrupt 2
//#define GIFR *((volatile u8*)0x5A) // flag read from it when interrupt happen  from hardware
//#define GICR *((volatile u8*)0x5B) // prepheral interrupt enable




//#define MCUCR_ISC00 0 //The low level of INT1 generates an interrupt request
//#define MCUCR_ISC01 1 //Any logical change on INT1 generates an interrupt request
//#define MCUCR_ISC10 2
//#define MCUCR_ISC11 3
//
//
//#define MCUCsR_ISC2 6 /*   If ISC2 is written to zero, a
//falling edge on INT2 activates the interrupt. If ISC2 is written to one, a rising edge on
//INT2 activates the interrupt. */
//
//
//#define GICR_INT2 5
//#define GICR_INT0 6
//#define GICR_INT1 7
//
//
//#define GIFR_INTF2 5
//#define GIFR_INTF0 6
//#define GIFR_INTF1 7

//in port (MCUCSR)
#define MCUCSR_ISC2 (u8)6   //interrupt sense control for interrupt 2(INT2)

//in port (MCUCR)
#define MCUCR_ISC00 (u8)0		//interrupt sense control for interrupt 0 bit zero
#define MCUCR_ISC01  (u8)1	//interrupt sense control for interrupt 0 bit 1

//in port (MCUCR)
#define	MCUCR_ISC10	(u8)2  //interrupt sense control for interrupt 1 bit 0
#define MCUCR_ISC11 (u8)3    //interrupt sense control for interrupt 1 bit 1

//in port (GICR)
#define GICR_INT2 (u8)5		//(External Interrupt Request 2 Enable) enable for interrupt 2
#define GICR_INT0 (u8)6      //(External Interrupt Request 0 Enable) enable for interrupt 0
#define GICR_INT1 (u8)7		//(External Interrupt Request 1 Enable) enable for interrupt 1

//in port (GIFR)
#define GIFR_INTF2 (u8)5		//External Interrupt Flag 2
#define GIFR_INTF0 (u8)6		//External Interrupt Flag 0
#define	GIFR_INTF1 (u8)7		//External Interrupt Flag 1

//in port (SREG)
#define SREG_GIE	(u8)7	//Global Interrupt Enable


#endif /* AVR_INTP_REG_H_ */
