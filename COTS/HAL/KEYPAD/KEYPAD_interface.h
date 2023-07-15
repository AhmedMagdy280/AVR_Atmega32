/*
 * KEYPAD.h
 *
 * Created: 3/13/2023 10:47:58 PM
 *  Author: ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
//include part
//#include "DELAY.h"

//initialize function  
void KEYPAD_init(void );
//read function  
u8 KEYPAD_GetPressedkey(void);

#define KPD_NO_PRESSED_KEY        0xFF


#endif /* KEYPAD_H_ */
