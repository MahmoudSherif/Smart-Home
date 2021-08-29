/*
 * BIT_MATH.h
 *
 *  Created on: 21 Jan 2019
 *      Author: Laptop Market
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,n) var|=(1<<n)
#define CLEAR_BIT(var,n) var &=(~(1<<n))
#define TOGGLE_BIT(var,n) var^=(1<<n)
#define GET_BIT(var,n) (var>>n)&1

#endif /* BIT_MATH_H_ */
