/*
 * DIO_interface.h
 *
 *  Created on: 21 Jan 2019
 *      Author:  Mahmoud Sherif
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include"AVR_DIO_REG.h"
#include"BIT_MATH.h"
#include"STD_TYPES.h"



typedef enum{DIO_enuInput,DIO_enuOutput}DIO_tenuDirection;
typedef enum{DIO_enuLow,DIO_enuHigh}DIO_tenuValue;

typedef enum {
	DIO_enuPORTA,
	DIO_enuPORTB,
	DIO_enuPORTC,
	DIO_enuPORTD
}DIO_tenuPORTID;


typedef enum {

	DIO_enuPIN0,
	DIO_enuPIN1,
	DIO_enuPIN2,
	DIO_enuPIN3,
	DIO_enuPIN4,
	DIO_enuPIN5,
	DIO_enuPIN6,
	DIO_enuPIN7,
}DIO_tenuPINID;

/*
 * SET PIN DIRECTION
 * INPUT: PORT NUMBER
 * PIN NUMBER
 * DIRECTION
 * OUTPUT: ERROR STATE
 */

u8 DIO_u8SetPinDirection(DIO_tenuPORTID COPY_enuPORTID,
		DIO_tenuPINID COPY_enuPINID, DIO_tenuDirection COPY_enuDirection);

/*
 * SET PIN VALUE
 * INPUT : PORT NUMBER
 * PIN NUMBER
 * OUTPUT : ERROT STATE
 */
u8 DIO_u8SetPinValue(DIO_tenuPORTID COPY_enuPORTID,
		DIO_tenuPINID COPY_enuPINID,DIO_tenuValue COPY_enuValue);

/*
 * GET PIN VALUE
 * INPUT : PORT NUMBER
 * PIN NUMBER
 * POINTER TO THE VALUE
 * OUTPUT : ERROR STATE
 */

u8 DIO_u8GetPinValue(DIO_tenuPORTID COPY_enuPortID,
		DIO_tenuPINID COPY_enuPinID,DIO_tenuValue* COPY_penuPinValue);
/*
 * SET PORT DIRECTION
 * INPUT: PORT NUMBER
 * DIRECTION
 * OUTPUT: ERROR STATE
 *
 */
u8 DIO_u8SetPortDirection(DIO_tenuPORTID COPY_enuPortID,DIO_tenuDirection COPY_enuDirection);


/*
 * SET PORT VALUE
 * INPUT : PORT NUMBER
 * PORT VALUE
 * OUTPUT: ERROR STATE
 *
 *
 */

u8 DIO_u8SetPortValue(DIO_tenuPORTID COPY_enuPortID,u8 COPY_u8Value);

/*
 * GET PORT VALUE
 * INPUT: PORT NUMBER
 *	POINTER TO PORT VALUE
 * 	OUTPUT: ERROR STATE
 *
 */
u8 DIO_u8GetPortValue(DIO_tenuPORTID COPY_enuPortID,DIO_tenuValue* COPY_penuPortValue);
#endif /* DIO_INTERFACE_H_ */
