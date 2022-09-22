/*
 * PassCheck_Program.c
 *
 *  Created on: Sep 7, 2022
 *      Author: noure
 */
#include "STD_TYPES.h"
#include "KP_Interface.h"
#include "LCD_Interface.h"



u8 checkPass(u8 pass[]){
	u8 key = 0;

	for(u8 i = 0; i < 4; i++){
		while(1){
			key = KP_Switches ();
			if (key != 0){
				LCD_VoidWriteData(key);
				if (key == pass[i]){
					break;
				}
				else{
					return 0;
				}
			}
		}
	}
	return 1;
}
