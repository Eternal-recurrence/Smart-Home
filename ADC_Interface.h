/*
 * ADC_Interface.h
 *
 *  Created on: Aug 18, 2022
 *      Author: noure
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

void ADC_Init();
void ADC_ChannelSelection(u8 CopyChannel);
u16 ADC_Get();

#endif /* ADC_INTERFACE_H_ */
