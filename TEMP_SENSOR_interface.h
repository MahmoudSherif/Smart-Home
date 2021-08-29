/*
 * LDR_interface.h
 *
 *  Created on: 14 Feb 2019
 *      Author: Laptop Market
 */

#ifndef TEMP_SENSOR_INTERFACE_H_
#define TEMP_SENSOR_INTERFACE_H_


#define TEMP_u8CHANNEL_NUM (u8)0


/*
 * Init temp sensor function
 * Input: None
 * Output: None
 *
 */

void TEMP_vidInit();

/*
 * Temp sensor get value function
 * Input : Channel, Pointer to Value
 * Output: Error state
 */

u8 TEMP_u8GetValue(u8 COPY_u8Channel,u32* COPY_u8LevelValue);

/*
 * DISPLAY ON LCD function
 * Input void
 * Output void
 *
 */
void TEMP_vidDisplayOnLCD(void);

#endif /* TEMP_SENSOR_INTERFACE_H_ */
