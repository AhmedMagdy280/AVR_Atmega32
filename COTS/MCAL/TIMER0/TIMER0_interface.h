/*
 * TIMER0_interface.h
 *
 *  Created on: Jun 17, 2023
 *      Author: ahmed
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

//ID _set call back function  ;
#define TIMER0_COMP     0
#define TIMER0_OVF      1

//TYPE OF INT
#define ALL_INT      2

/*					prototypes Functions							*/
//initialize function
void TIMER0_init (void);
//TCNT start value
void TIMER0_GetCounts (u64 *OVF_number);
//OCR compare  value
void TIMER0_comparevalue(u8 ocrvalue  );
//function take prescaler and start timer
void TIMER0_start (void);
void TIMER0_stop(void);
void TIMER0_setDelayTimeMilliSec(u16 MilliSec_time);

void TIMER0_setFastPWM(u8 duty) ;
void TIMER0_setphaseCorrectPWM(u8 duty) ;
//function to enable INT (PIE)
void TIMER0_enableINT(u8 INTtype);
//function to disable INT (PIE)
void TIMER0_disableINT(u8 INTtype);
void TIMER0_setCallBack(void (*fptr)(void) , u8 ID);
#endif /* TIMER0_INTERFACE_H_ */
