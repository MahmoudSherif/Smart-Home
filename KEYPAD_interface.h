/*
 * KEYPAD_interfac.h
 *
 *  Created on: 30 Jan 2019
 *      Author: Laptop Market
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KPD_u8CONNECT_PORT DIO_enuPORTB



#define KPD_u8MAX_COL_PIN	8
#define KPD_u8MAX_ROW_PIN	4
#include"STD_TYPES.h"


/*
 * KEYPAD initialization function
 * input : void
 * output: void
 *
 */
void KPD_vidInit(void);


/*
 * KEYPRESSED function
 * input: pointer to u8 [value that indicates the pressed button]
 * output: void
 */

void KPD_vidGetKey(u8* COPY_pu8KeyPressed);



#endif /* KEYPAD_INTERFACE_H_ */
