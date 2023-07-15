/*
 * BUTTON.h
 *
 * Created: 3/4/2023 4:16:42 PM
 *  Author: ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
//INCLUDE PART 
#include "DIO.h"
//prototype PART 

//initialized function 

void BUTTON_init (u8 buttonport , u8 buttonpin ) ;

//read value from button function 

void BUTTON_read(u8 buttonport , u8 buttonpin , u8 *value);



#endif /* BUTTON_H_ */
