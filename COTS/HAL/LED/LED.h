/*
 * LED.h
 *
 * Created: 3/3/2023 3:09:34 PM
 *  Author: ahmed
 */ 

//guard of the file 

#ifndef LED_H_

#define LED_H_

//include part 

#include "DIO.h"

 // function prototype  

  //initialize function 

 void LED_init(u8 ledport  , u8 ledpin) ;

 //function to on led 

 void LED_on (u8 ledport  , u8 ledpin ) ;

 //function to led off 

 void LED_off (u8 ledport , u8 ledpin ) ;

 //toggle led function 

 void LED_togg (u8 ledport , u8 ledpin );

//end of the guard file 

#endif /* LED_H_ */
