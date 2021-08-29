/*
 * DIO.c
 *
 *  Created on: 21 Jan 2019
 *      Author: Mahmoud Sherif
 */



#include"DIO_interface.h"
#define u8MAX_PIN_NB (u8)7
#define Null (u8)0

u8 DIO_u8SetPinDirection(DIO_tenuPORTID COPY_enuPortID,
		DIO_tenuPINID COPY_enuPinID, DIO_tenuDirection COPY_enuDirection)
{
	u8 LOC_u8Err=0;

	switch (COPY_enuPortID) {
	case DIO_enuPORTA:
		if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
			{
				LOC_u8Err=1;
			}else
			{
				if(COPY_enuDirection ==DIO_enuInput)
				{
					CLEAR_BIT(DDRA,COPY_enuPinID);
				}else if(COPY_enuDirection==DIO_enuOutput)
				{
					SET_BIT(DDRA,COPY_enuPinID);
				}else
				{
					LOC_u8Err=1;
				}
			}

		break;
	case DIO_enuPORTB:
		if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
			{
				LOC_u8Err=1;
			}else
			{
				if(COPY_enuDirection ==DIO_enuInput)
				{
					CLEAR_BIT(DDRB,COPY_enuPinID);
				}else if(COPY_enuDirection==DIO_enuOutput)
				{
					SET_BIT(DDRB,COPY_enuPinID);
				}else
				{
					LOC_u8Err=1;
				}
			}

		break;
		case DIO_enuPORTC:
			if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
				{
					LOC_u8Err=1;
				}else
				{
					if(COPY_enuDirection ==DIO_enuInput)
					{
						CLEAR_BIT(DDRC,COPY_enuPinID);
					}else if(COPY_enuDirection==DIO_enuOutput)
					{
						SET_BIT(DDRC,COPY_enuPinID);
					}else
					{
						LOC_u8Err=1;
					}
				}

			break;
		case DIO_enuPORTD:
			if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
				{
					LOC_u8Err=1;
				}else
				{
					if(COPY_enuDirection ==DIO_enuInput)
					{
						CLEAR_BIT(DDRD,COPY_enuPinID);
					}else if(COPY_enuDirection==DIO_enuOutput)
					{
						SET_BIT(DDRD,COPY_enuPinID);
					}else
					{
						LOC_u8Err=1;
					}
				}

			break;
		default:
			LOC_u8Err=1;
			break;
	}

	return LOC_u8Err;
}

/*
 * SET PIN VALUE
 * INPUT : PORT NUMBER
 * PIN NUMBER
 * OUTPUT : ERROT STATE
 */

u8 DIO_u8SetPinValue(DIO_tenuPORTID COPY_enuPortID,
		DIO_tenuPINID COPY_enuPinID,DIO_tenuValue COPY_enuValue)
{
	u8 LOC_u8Err=0;
	switch (COPY_enuPortID) {
		case DIO_enuPORTA:
			if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
			{
				LOC_u8Err=1;
			}else
			{
				if(COPY_enuValue==DIO_enuHigh)
				{
					SET_BIT(PORTA,COPY_enuPinID);
				}else if (COPY_enuValue==DIO_enuLow)
				{
					CLEAR_BIT(PORTA,COPY_enuPinID);
				}
				else
				{
					LOC_u8Err=1;
				}
			}
			break;
		case DIO_enuPORTB:
			if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
			{
				LOC_u8Err=1;
			}else
			{
				if(COPY_enuValue==DIO_enuHigh)
				{
					SET_BIT(PORTB,COPY_enuPinID);
				}else if (COPY_enuValue==DIO_enuLow)
				{
					CLEAR_BIT(PORTB,COPY_enuPinID);
				}
				else
				{
					LOC_u8Err=1;
				}
			}
			break;
		case DIO_enuPORTC:
			if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
			{
				LOC_u8Err=1;
			}else
			{
				if(COPY_enuValue==DIO_enuHigh)
				{
					SET_BIT(PORTC,COPY_enuPinID);
				}else if (COPY_enuValue==DIO_enuLow)
				{
					CLEAR_BIT(PORTC,COPY_enuPinID);
				}
				else
				{
					LOC_u8Err=1;
				}
			}
			break;
		case DIO_enuPORTD:
			if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
			{
				LOC_u8Err=1;
			}else
			{
				if(COPY_enuValue==DIO_enuHigh)
				{
					SET_BIT(PORTD,COPY_enuPinID);
				}else if (COPY_enuValue==DIO_enuLow)
				{
					CLEAR_BIT(PORTD,COPY_enuPinID);
				}
				else
				{
					LOC_u8Err=1;
				}
			}
			break;
		default:
			LOC_u8Err=1;
			break;
	}
	return LOC_u8Err;
	}


/*
 * GET PIN VALUE
 * INPUT : PORT NUMBER
 * PIN NUMBER
 * POINTER TO THE VALUE
 * OUTPUT : ERROR STATE
 */

u8 DIO_u8GetPinValue(DIO_tenuPORTID COPY_enuPortID,
		DIO_tenuPINID COPY_enuPinID,DIO_tenuValue* COPY_penuPinValue)
{
	u8 LOC_u8Err=0;
	if(COPY_penuPinValue==Null)
	{
		LOC_u8Err=1;
	}else
	{
		switch (COPY_enuPortID) {
			case DIO_enuPORTA:
				if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
				{
					LOC_u8Err=1;
				}else
				{
					*COPY_penuPinValue=GET_BIT(PINA,COPY_enuPinID);
				}
				break;
			case DIO_enuPORTB:
				if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
				{
					LOC_u8Err=1;
				}else
				{
					*COPY_penuPinValue=GET_BIT(PINB,COPY_enuPinID);
				}
				break;
			case DIO_enuPORTC:
				if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
				{
					LOC_u8Err=1;
				}else
				{
					*COPY_penuPinValue=GET_BIT(PINC,COPY_enuPinID);
				}
				break;
			case DIO_enuPORTD:
				if(COPY_enuPinID>u8MAX_PIN_NB || COPY_enuPinID<0)
				{
					LOC_u8Err=1;
				}else
				{
					*COPY_penuPinValue=GET_BIT(PIND,COPY_enuPinID);
				}
				break;
			default:
				LOC_u8Err=1;
				break;
		}
	}


	return LOC_u8Err;
}



/*
 * SET PORT DIRECTION
 * INPUT: PORT NUMBER
 * DIRECTION
 * OUTPUT: ERROR STATE
 *
 */
u8 DIO_u8SetPortDirection(DIO_tenuPORTID COPY_enuPortID,u8 COPY_enuDirection)
{
	u8 LOC_u8Err=0;
	switch (COPY_enuPortID) {
		case DIO_enuPORTA:
			DDRA=COPY_enuDirection;
			break;
		case DIO_enuPORTB:
			DDRB=COPY_enuDirection;
			break;
		case DIO_enuPORTC:
			DDRC=COPY_enuDirection;
			break;
		case DIO_enuPORTD:
			DDRD=COPY_enuDirection;
			break;
		default:
			LOC_u8Err=1;
			break;
	}
	return LOC_u8Err;
}

/*
 * SET PORT VALUE
 * INPUT : PORT NUMBER
 * PORT VALUE
 * OUTPUT: ERROR STATE
 *
 *
 */

u8 DIO_u8SetPortValue(DIO_tenuPORTID COPY_enuPortID,u8 COPY_u8Value)
{
	u8 LOC_u8Err=0;
	switch (COPY_enuPortID) {
		case DIO_enuPORTA:
			PORTA=COPY_u8Value;
			break;
		case DIO_enuPORTB:
			PORTB=COPY_u8Value;
			break;
		case DIO_enuPORTC:
			PORTC=COPY_u8Value;
			break;
		case DIO_enuPORTD:
			PORTD=COPY_u8Value;
			break;
		default:
			LOC_u8Err=1;
			break;
	}
	return LOC_u8Err;
}

/*
 * GET PORT VALUE
 * INPUT: PORT NUMBER
 *	POINTER TO PORT VALUE
 * 	OUTPUT: ERROR STATE
 *
 */
u8 DIO_u8GetPortValue(DIO_tenuPORTID COPY_enuPortID,DIO_tenuValue* COPY_penuPortValue)
{
	u8 LOC_u8Err=0;

	switch (COPY_enuPortID) {
		case DIO_enuPORTA:
			if(COPY_penuPortValue==Null)
			{
				LOC_u8Err=1;
			}else
			{
				*COPY_penuPortValue=PINA;
			}
			break;
		case DIO_enuPORTB:
			if(COPY_penuPortValue==Null)
			{
				LOC_u8Err=1;
			}else
			{
				*COPY_penuPortValue=PINB;
			}
			break;
		case DIO_enuPORTC:
			if(COPY_penuPortValue==Null)
			{
				LOC_u8Err=1;
			}else
			{
				*COPY_penuPortValue=PINC;
			}
			break;
		case DIO_enuPORTD:
			if(COPY_penuPortValue==Null)
			{
				LOC_u8Err=1;
			}else
			{
				*COPY_penuPortValue=PIND;
			}
			break;
		default:
			LOC_u8Err=1;
			break;
	}



	return LOC_u8Err;
}
