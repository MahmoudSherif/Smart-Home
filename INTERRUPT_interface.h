/*
 * INTERRUPT_interface.h
 *
 *  Created on: 2 Feb 2019
 *      Author: Laptop Market
 */

#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_

// enabling and disabling interrupt
#define INTP_ENABLE 1
#define INTP_DISABLE 0

// event types of interrupt
#define INTP_FALLING_EGDE 0
#define INTP_RISING_EDGE 1
#define INTP_ON_CHANGE 2
#define INTP_LOW_LEVEL 3

#define INTP0_STATE INTP_DISABLE
#define INTP1_STATE INTP_DISABLE
#define INTP2_STATE INTP_ENABLE

#define INTP0_EVENT_TYPE  INTP_FALLING_EGDE
#define INTP1_EVENT_TYPE  INTP_FALLING_EGDE
#define INTP2_EVENT_TYPE  INTP_FALLING_EGDE

#define INTP_INT0 __vector_1    //can be written to be better in readability



/*
 * initialization for all interrupts
 *input : void
 *output : void
 */
void INTP_vidInit();


/*
 * Interrupt 0 enable
 * input :void
 * output : void
 */
void INTP_vidIntp0Enable();

/*
 * Interrupt 0 disable
 * input :void
 * output : void
 */

void INTP_vidIntp0Disable();

/*
 * Interrupt 1 enable
 * input :void
 * output : void
 */

void INTP_vidIntp1Enable();
/*
 * Interrupt 1 disable
 * input :void
 * output : void
 */
void INTP_vidIntp1Disable();

/*
 * Interrupt 2 enable
 * input :void
 * output : void
 */

void INTP_vidIntp2Enable();
/*
 * Interrupt 2 disable
 * input :void
 * output : void
 */
void INTP_vidIntp2Disable();

/*
 * interrupt 0 event type
 * input : event type
 * output : void
 */
void INTP_vidIntp0EventType(u8 COPY_u8Event);

/*
 * interrupt 1 event type
 * input : event type
 * output : void
 */
void INTP_vidIntp1EventType(u8 COPY_u8EventType);
/*
 * interrupt 2 event type
 * input : event type
 * output : void
 */
void INTP_vidIntp2EventType(u8 COPY_u8EventType);

/*
 * Enable global interrupt
 *input : void
 *output : void
 */
void INTP_vidEnableGlobalInterrupt();

/*
 * disable global interrupt
 * input : void
 * output: void
 */
void INTP_vidDisbleGlobalInterrupt();


#endif /* INTERRUPT_INTERFACE_H_ */
