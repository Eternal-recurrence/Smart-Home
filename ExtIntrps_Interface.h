/*
 * Interrputs_Interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: noure
 */

#ifndef EXTINTRPS_INTERFACE_H_
#define EXTINTRPS_INTERFACE_H_

#define Ext0 0
#define Ext1 1
#define Ext2 2

#define LowLevel 0
#define AnyChange 1
#define FEdge 2
#define REdge 3



 void Intrpt_Init(u8 ExIntId, u8 SnsCtrl);

 void EXTI0_SetCallBack(void (*PtrToFunc)());

 void EXTI1_SetCallBack(void (*PtrToFunc)());

#endif /* EXTINTRPS_INTERFACE_H_ */
