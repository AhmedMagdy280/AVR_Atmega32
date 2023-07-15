/*
 * TIMER0_interface.h
 *
 *  Created on: Jun 17, 2023
 *      Author: ahmed
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


/*					prototypes Functions							*/
//initialize function
void TIMER1_init (void);
//TCNT start value
void TIMER1_start (void);
void TIMER1_stop(void);

void TIMER1_ICU_void_setTrigg(u8 sense_edge) ;
void TIMER1_ICU_setCallBack(void (*fptr)(void) ) ;

#define ICU_RISING_EDGE     1
#define ICU_FALLING_EDGE     1

#endif /* TIMER1_INTERFACE_H_ */
