/*
 * Timer1_Interface.h
 *
 *  Created on: Aug 22, 2022
 *      Author: noure
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define NormalMode 0
#define PWMPhaseCorrect 1
#define CTCMode 2
#define FastPWMMode 3

void Timer1_voidInit(u8 TimerMode);

void Timer1_SetOCRA1A(u16 CopyOCR1A);

#endif /* TIMER1_INTERFACE_H_ */
