/*
 * GIE.h
 *
 * Created: 3/5/2023 3:01:24 PM
 *  Author: Ahmed
 */ 


#ifndef GIE_H_
#define GIE_H_
//include part 
#include "registers.h"
//prototype function  
//FUNCTION TO ENABLE GLOBLE INTERRUPT 
void GIE_enable(void ) ;
//function to disable globle interrupt  
void GIE_disable(void ) ;

//DEFINE GLOBLE INTERRUPT BIT
#define  SREG_GIE  7



#endif /* GIE_H_ */
