/*
 * BOTTUN.c
 *
 * Created: 3/4/2023 4:17:21 PM
 *  Author: ahmed
 */ 

//INCLUDE PART   

#include "BUTTON.h"

//initialized function

void BUTTON_init (u8 buttonport , u8 buttonpin ) {
	DIO_initpin(buttonport ,buttonpin , IN);
    DIO_writepin(buttonport,buttonpin ,HIGH);
}

//read value from button function

void BUTTON_read(u8 buttonport , u8 buttonpin , u8 *value){
   DIO_readpin(buttonport , buttonpin , value) ;
}

