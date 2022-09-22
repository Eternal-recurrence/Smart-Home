/*
 * Interrputs_Private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: noure
 */

#ifndef EXTINTRPS_PRIVATE_H_
#define EXTINTRPS_PRIVATE_H_

#define SREG *((volatile u8*)0x5F)
#define GIEBit 7

#define MCUCR *((volatile u8*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define MCUSCR *((volatile u8*)0x54)
#define ISC2 6

#define GICR *((volatile u8*)0x5B)
#define Ext0_PIE 6
#define Ext1_PIE 7
#define Ext2_PIE 5

#endif /* EXTINTRPS_PRIVATE_H_ */
