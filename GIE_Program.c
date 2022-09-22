/*
 * GIE_Program.c
 *
 *  Created on: Aug 21, 2022
 *      Author: noure
 */
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "GIE_Private.h"

void GIE_VoidInit(u8 CopyGIEState){
	//Enabling Global Interrupts
	if (CopyGIEState)
		SREG = SetBit(SREG, GIEBit);
	else
		SREG = ClearBit(SREG, GIEBit);
}
