/*
 * ADC_Private.h
 *
 *  Created on: Aug 18, 2022
 *      Author: noure
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX_REG *((volatile u8*)0x27)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define ADLAR_Pin 5
#define REFS1_Pin 7
#define REFS0_Pin 6


#define ADCSRA_REG *((volatile u8*)0x26)
#define ADPS0_Pin 0
#define ADPS1_Pin 1
#define ADPS2_Pin 2
#define ADSC_Pin 6
#define ADEN_Pin 7

#define ADC_REG  *((volatile u16*) 0x24)

#define SFIOR_REG  *((volatile u8*) 0x50)
#define ADTS0_Pin 5
#define ADTS1_Pin 6
#define ADTS2_Pin 7

#endif /* ADC_PRIVATE_H_ */
