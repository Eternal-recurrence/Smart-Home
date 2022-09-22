/*
 * main.c

 *
 *  Created on: Aug 13, 2022
 *      Author: noure
 */
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include <avr/io.h>		/* Include AVR std. library file */
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "ExtIntrps_Interface.h"
#include "ADC_Interface.h"
#include "Timer1_Interface.h"
#include "LCD_Interface.h"
#include "KP_Interface.h"
#include "PassCheck_Interface.h"
#include "util/delay.h"



u8 pass[] = {1,2,3,4};

u16 Temp_Degital ;
void EXT_INT0_ISR(void);
//void Timer1_Fast_PWM_Init(unsigned short duty_cycle);

int main(){


			 short x ,f=0;

				//DDRA &= 0xF8; /* make pins A  as input */
				DIO_VoidSetPinDirection(PortA_ID,PIN_ID5,Input);	// EXT_INT0 PIN
				DIO_VoidSetPinDirection(PortA_ID,PIN_ID6,Input);	// EXT_INT0 PIN
				DIO_VoidSetPinDirection(PortA_ID,PIN_ID7,Input);	// EXT_INT0 PIN


				DDRD |= (1<<PD4);	/* Make PD5 pin as output */


	DIO_VoidSetPinDirection(PortD_ID,PIN_ID2,Input);	// EXT_INT0 PIN
	DIO_VoidSetPinValue(PortD_ID,PIN_ID2,High);			// Enable Pull_Up Res
	DIO_VoidSetPinDirection(PortD_ID,PIN_ID5,Output);	// Fan PIN
	ADC_Init();											// Enable ADC for Temp_Sensor Reading
	ADC_ChannelSelection(ADC0);							// selecting Channel
	LCD_VoidInit();										// Enable LCD
	GIE_VoidInit(On);									// Enable GIE
	Intrpt_Init(Ext0,FEdge);							// Falling_Edge INT .. because of Pull_Up Res
	EXTI0_SetCallBack(EXT_INT0_ISR);					// ISR of INT0
	Timer1_voidInit(FastPWMMode);						// selecting TMR1 ON FastPWMMode with 50 Hz


	////////////////////////////////


	while(1){


		/* check if the first push button at PA2 is pressed/not */
		if(PINA & (1<<PA5))
		{
			if(f==0){
				Timer1_Fast_PWM_Init(523);	/* Set Servo shaft at 0� position by 1 ms pulse */
				_delay_ms(1500);
				Timer1_Fast_PWM_Init(273);/* Set Servo shaft at 90� position by 1.5 ms pulse */
				_delay_ms(1500);
				Timer1_Fast_PWM_Init(24);	/* Set Servo shaft at 180� position by 2 ms pulse */
				x=0;
			}
			else{
				Timer1_Fast_PWM_Init(x);
			}
			f=1;
		}
		/* check if the second  push button at PA2 is pressed/not */
		else if(PINA & (1<<PA6))
		{
			if(f==1){
				_delay_ms(1500);
				Timer1_Fast_PWM_Init(273);	/* Set Servo shaft at 90� position by 1.5 ms pulse */
				_delay_ms(1500);
				Timer1_Fast_PWM_Init(523);	/* Set Servo shaft at 0� position by 1 ms pulse */
				x=523;
				f=0;
			}
			else
			{
				Timer1_Fast_PWM_Init(523);	/* Set Servo shaft at 0� position by 1 ms pulse */
				_delay_ms(1500);
			}

		}

		/* check if the third push button at PA2 is pressed/not */
		else if(PINA & (1<<PA7))
		{
			Timer1_Fast_PWM_Init(x);	/* Set Servo shaft at position by pulse */
		}


	}




	return 0;
}





void EXT_INT0_ISR(void)
{
	LCD_VoidClrDisp();									// Clear LCD
	Temp_Degital=ADC_Get();								// GET value Of Temp_Sensor
	LCD_VoidDisplayNum(Temp_Degital/2);					// Display Real Temp ON LCD

	if(Temp_Degital>20 && Temp_Degital<52)
	{	// 10 c < temp < 25 c
		LCD_VoidDisplayStr("\tFan low");
		// 30 % duty cycle
		Timer1_SetOCRA1A(6000); //(30% of 20000)
	}
	else if(Temp_Degital>=52 && Temp_Degital<70)
	{	// 26 c < temp < 35 c
		LCD_VoidDisplayStr("\tFan mid");
		// 70 % duty cycle
		Timer1_SetOCRA1A(14000); //(70% of 20000)
	}
	else if(Temp_Degital>=70)
	{	// temp > 35 c
		LCD_VoidDisplayStr("\tFan High");
		// 100 % duty cycle
		Timer1_SetOCRA1A(20000); //(100% of 20000)
	}
	else
	{
		// Temp < 10 c ...... stop Fan
		LCD_VoidDisplayStr("\tFan Stopped");
		// 0 % duty cycle
		Timer1_SetOCRA1A(0); //(0% of 20000)
	}
}


//////////////////////////////////////////////



void Timer1_Fast_PWM_Init(unsigned short duty_cycle)
{
	TCNT0 = 0;		/* Set timer1 initial count to zero */
	ICR1 = 2499;	/* Set TOP count for timer1 in ICR1 register */

	OCR1B = duty_cycle; /* Set the compare value */

	TCCR1B = (1<<WGM11) | (1<<COM1B1);
	TCCR1A = (1<<WGM12) | (1<<WGM13) | (1<<CS10) | (1<<CS11);

	/* Configure timer control register TCCR1B */
}
