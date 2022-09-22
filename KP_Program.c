/*
 * KP_Program.c
 *
 *  Created on: Aug 15, 2022
 *      Author: noure
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "KP_Config.h"
#include "util/delay.h"
#include "KP_Private.h"


void KP_Init(){
	DIO_VoidSetPortDirection(KP_PRORT, 0xF0);
	DIO_VoidSetPortValue(KP_PRORT, 0xFF);
}

static u8 SelectedKey(u8 KeyPos){
	switch(KeyPos){
		case zero:
			return '0';
			break;
		case one:
			return '1';
			break;
		case two:
			return '2';
			break;
		case three:
			return '3';
			break;
		case four:
			return '4';
			break;
		case five:
			return '5';
			break;
		case six:
			return '6';
			break;
		case seven:
			return '7';
			break;
		case eight:
			return '8';
			break;
		case nine:
			return '9';
			break;
		case divide:
			return '/';
			break;
		case multiply:
			return '*';
			break;
		case subtract:
			return '-';
			break;
		case add:
			return '+';
			break;
		case equal:
			return '=';
	}
	//the last case is the clear button
	return 'c';
}

u8 KP_Switches (){
	u8 LocalKetstat = 0xff, KeyChk = 1, KeyPos = 0;

	for (int col = 0; col < 4; col++){
		DIO_VoidSetPinValue(KP_PRORT, col + 4, Low);

		for (int row = 0; row < 4; row++){
			KeyChk = DIO_U8GetPinValue(KP_PRORT, row);

			if (KeyChk == 0){
				KeyPos = row*4 + col + 1;
				while(DIO_U8GetPinValue(KP_PRORT, row) == 0);
				//_delay_ms(100);
				DIO_VoidSetPinValue(KP_PRORT, col + 4, High);
				return SelectedKey (KeyPos);
			}
		}
		DIO_VoidSetPinValue(KP_PRORT, col + 4, High);
	}
	return KeyPos;
}
