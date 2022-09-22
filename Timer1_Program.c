/*
 * Timer1_Program.c
 *
 *  Created on: Aug 22, 2022
 *      Author: noure
 */
#include "STD_TYPES.h"
#include "Timer1_Private.h"
#include "Timer1_Interface.h"
#include "Bit_Math.h"

void Timer1_voidInit(u8 TimerMode){
	//Choosing mode
	switch(TimerMode){
		case FastPWMMode:
			TCCR1A_REG = ClearBit(TCCR1A_REG, WGM10_Pin);
			TCCR1A_REG = SetBit(TCCR1A_REG, WGM11_Pin);
			TCCR1B_REG = SetBit(TCCR1B_REG, WGM12_Pin);
			TCCR1B_REG = SetBit(TCCR1B_REG, WGM13_Pin);

			//Choose non inverting mode
			TCCR1A_REG = ClearBit(TCCR1A_REG, COM1A0_Pin);
			TCCR1A_REG = SetBit(TCCR1A_REG, COM1A1_Pin);
			break;
	}

	//Choosing pre-scaler = 8
	TCCR1B_REG = ClearBit(TCCR1B_REG, CS10_Pin);
	TCCR1B_REG = SetBit(TCCR1B_REG, CS11_Pin);
	TCCR1B_REG = ClearBit(TCCR1B_REG, CS12_Pin);

	//Loading ICR1
	ICR1_REG = 20000;
}

void Timer1_SetOCRA1A(u16 CopyOCR1A){
	OCR1A_REG = CopyOCR1A;
}
