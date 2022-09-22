/*
 * Timer1_Private.h
 *
 *  Created on: Aug 22, 2022
 *      Author: noure
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A_REG *((volatile u8*)0x4F)
#define WGM10_Pin 0
#define WGM11_Pin 1
#define COM1A0_Pin 6
#define COM1A1_Pin 7

#define TCCR1B_REG *((volatile u8*)0x4E)
#define WGM12_Pin 3
#define WGM13_Pin 4
#define CS10_Pin 0
#define CS11_Pin 1
#define CS12_Pin 2

#define OCR1A_REG *((volatile u16*)0x4A)

#define ICR1_REG *((volatile u16*)0x46)

#endif /* TIMER1_PRIVATE_H_ */
