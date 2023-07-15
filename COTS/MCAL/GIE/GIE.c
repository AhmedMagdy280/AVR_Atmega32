/*
 * GIE.c
 *
 * Created: 3/5/2023 3:01:39 PM
 *  Author: ahmed
 */ 

//include part   
#include "GIE.h"

//function part 
void GIE_enable(void ){
	set_bit(SREG , SREG_GIE) ;
}

void GIE_disable(void ) {
     
	 clr_bit(SREG,SREG_GIE) ; 
 }

