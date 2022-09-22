/*
 * Interrputs_program.c
 *
 *  Created on: Aug 17, 2022
 *      Author: noure
 */

#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "ExtIntrps_Private.h"
#include "DIO_Interface.h"
#include "ExtIntrps_Interface.h"


void (*GlobPtrToFunc0) ();
void (*GlobPtrToFunc1) ();

void SetSnsCtrl(u8 ExIntId, u8 SnsCtrl){
	u8 ISC0, ISC1;
	if (ExIntId == Ext0){
		ISC0 = ISC00;
		ISC1 = ISC01;
	}
	else{
		ISC0 = ISC10;
		ISC1 = ISC11;
	}
	switch (SnsCtrl){
		case LowLevel:
			MCUCR = ClearBit(MCUCR, ISC0);
			MCUCR = ClearBit(MCUCR, ISC1);
			break;
		case AnyChange:
			MCUCR = SetBit(MCUCR, ISC0);
			MCUCR = ClearBit(MCUCR, ISC1);
			break;
		case FEdge:
			MCUCR = SetBit(MCUCR, ISC1);
			MCUCR = ClearBit(MCUCR, ISC0);
			break;
		case REdge:
			MCUCR = SetBit(MCUCR, ISC1);
			MCUCR = SetBit(MCUCR, ISC0);
			break;
	}
}

void Intrpt_Init(u8 ExIntId, u8 SnsCtrl){
	switch(ExIntId){
		case Ext0:
			GICR = SetBit(GICR,Ext0_PIE);
			SetSnsCtrl(ExIntId, SnsCtrl);
			break;
		case Ext1:
			GICR = SetBit(GICR,Ext1_PIE);
			SetSnsCtrl(ExIntId, SnsCtrl);
			break;
		case Ext2:
			GICR = SetBit(GICR,Ext2_PIE);
			switch(SnsCtrl){
				case REdge:
					MCUSCR = SetBit(MCUSCR,ISC2);
					break;
				case FEdge:
					MCUSCR = ClearBit(MCUSCR,ISC2);
			}
			break;
	}
}

void EXTI0_SetCallBack(void (*PtrToFunc)()){
	GlobPtrToFunc0 = PtrToFunc;
}

void EXTI1_SetCallBack(void (*PtrToFunc)()){
	GlobPtrToFunc1 = PtrToFunc;
}


void __vector_1()__attribute__((signal));

void __vector_1(){
	GlobPtrToFunc0();
	//DIO_VoidTogglePin(PortD_ID, PIN_ID7);
}

void __vector_2()__attribute__((signal));

void __vector_2(){
	//DIO_VoidTogglePin(PortD_ID, PIN_ID7);
	GlobPtrToFunc1();
}

void __vector_3()__attribute__((signal));

void __vector_3(){
	DIO_VoidTogglePin(PortD_ID, PIN_ID7);
}
