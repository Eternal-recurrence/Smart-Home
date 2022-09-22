/*
 * ADC-Program.c
 *
 *  Created on: Aug 18, 2022
 *      Author: noure
 */

#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "ADC_Private.h"
#include "DIO_Interface.h"

void ADC_Init(){
	//Enabling ADC
	ADCSRA_REG = SetBit(ADSC_Pin, ADEN_Pin);

	//Reference selection
	ADMUX_REG = SetBit(ADMUX_REG, REFS0_Pin);
	ADMUX_REG = ClearBit(ADMUX_REG, REFS1_Pin);

	//Adjust right or Left
	ADMUX_REG = ClearBit(ADMUX_REG, ADLAR_Pin);	//Adjust left

	//Pre-scaler = 64
	ADCSRA_REG = ClearBit(ADCSRA_REG, ADPS0_Pin);
	ADCSRA_REG = SetBit(ADCSRA_REG, ADPS1_Pin);
	ADCSRA_REG = SetBit(ADCSRA_REG, ADPS2_Pin);

	//Choosing free running mode
	SFIOR_REG = ClearBit(SFIOR_REG, ADTS0_Pin);
	SFIOR_REG = ClearBit(SFIOR_REG, ADTS1_Pin);
	SFIOR_REG = ClearBit(SFIOR_REG, ADTS2_Pin);

	ADCSRA_REG = SetBit(ADCSRA_REG, ADSC_Pin);
}

void ADC_ChannelSelection(u8 CopyChannel){
	//Setting pin as input
	DIO_VoidSetPinDirection(PortA_ID, CopyChannel, Input);

	//Selecting channel
	ADMUX_REG = (ADMUX_REG & 0b11100000)|CopyChannel;

	ADCSRA_REG = SetBit(ADCSRA_REG, ADSC_Pin);
}

u16 ADC_Get(){
	ADCSRA_REG = SetBit(ADCSRA_REG, ADSC_Pin);
	return ADC_REG;
	return 0;
}
