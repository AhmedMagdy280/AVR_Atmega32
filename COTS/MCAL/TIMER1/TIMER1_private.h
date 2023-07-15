/*
 * TIMER.h
 *
 * Created: 3/6/2023 3:21:39 PM
 *  Author: Ahmed
 */ 

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define  NORMAL_MODE_T1    1
#define  PPWM_MODE_T1      2
#define  CTC_MODE_T1       3
#define  FPWM_MODE_T1      4



#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1

#define TCCR1A_COM1A1    7
#define TCCR1A_COM1A0    6

#define TCCR1A_COM1B1    5
#define TCCR1A_COM1B0	 4


#define   	TCCR1B_ICNC1    7
#define  	TCCR1B_ICES1  	6
#define   	TCCR1B_WGM13    4
#define  	TCCR1B_WGM12  	3
#define   	TCCR1B_CS12    	2
#define  	TCCR1B_CS11  	1
#define  	TCCR1B_CS10  	0

#define  PRESCALER_T1_1				0b001
#define  PRESCALER_T1_8				0b010
#define  PRESCALER_T1_64			0b011
#define  PRESCALER_T1_256			0b100
#define  PRESCALER_T1_1024			0b101

#define  ICU_ENABLE			1
#define  ICU_DISABLE		2


#define TIMSK_TICIE1        5

#endif /* TIMER1_PRIVATE_H_ */
