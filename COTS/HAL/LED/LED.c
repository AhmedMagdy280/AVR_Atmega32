/*
 * LED.c
 *
 * Created: 3/3/2023 3:09:58 PM
 *  Author: ahmed
 */

//including part  
#include "LED.h"

 //initialize function

 void LED_init(u8 ledport  , u8 ledpin) {
	 DIO_initpin(ledport , ledpin, OUT) ;
 }

 //function to on led

 void LED_on (u8 ledport  , u8 ledpin ) {
	 DIO_writepin(ledport ,ledpin , HIGH) ;
	 
 }

 //function to led off

void LED_off (u8 ledport , u8 ledpin ) {
	DIO_writepin(ledport , ledpin ,LOW) ;
}

 //toggle led function

 void LED_togg (u8 ledport , u8 ledpin ){
	 DIO_togglepin(ledport ,ledpin ) ; 
 }
