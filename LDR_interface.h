/*
 * LDR_interface.h
 *
 *  Created on: 14 Feb 2019
 *      Author: Laptop Market
 */

#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_


#define LDR_u8CHANNEL_NUM (u8)1


/*
 * Init LDR function
 * Input: None
 * Output: None
 *
 */
void LDR_vidInit();

/*
 * LDR Levels function
 * Input : Channel, Pointer to LevelValue (in scale 5)
 * Output: Error state
 */

u8 LDR_u8GetValue(u8 COPY_u8Channel,u32* COPY_u8LevelValue);

/*
 * DISPLAY ON LCD function
 * Input void
 * Output void
 *
 */
void LDR_vidDisplayOnLCD(void);

#endif /* LDR_INTERFACE_H_ */
