/*
 * EXINT.h
 *
 * Created: 3/4/2023 9:55:43 PM
 *  Author: Ahmed
 */ 


#ifndef EXINT_H_
#define EXINT_H_
//include part 
#include "registers.h"
#include "GIE.h"
#include "DIO.h"
//function prototype  
//initialize function
 //interrupt 0 
 void EXINT0_init(u8 sensemode  ) ;
 //interrupt 1 
 void EXINT1_init(u8 sensemode  ) ;
 //interrupt 2 
 void EXINT2_init(u8 sensemode  ) ;
 
 //enable interrupt function 
 //interrupt 0
 void ETINT0_enable(void ) ;
 //interrupt 1
 void ETINT1_enable(void ) ;
 //interrupt 2 
 void ETINT2_enable(void ) ;
 //disable interrupt function 
 //interrupt 0
 void ETINT0_disable(void ) ;
 //interrupt 1
 void ETINT1_disable(void ) ;
 //interrupt 2
 void ETINT2_disable(void ) ;
  
 void setcallbackfunc(void (*ptrtofunc)(void),u8 NUMINT) ;
//sense mode define 
#define FALLING_EDGE		1
#define RISING_EDGE			2
#define ON_CHANGE		    3
#define LOW_LEVEL			4
//define sense mode bits 
#define MCUCR_ISC00  0   //INT0 sense control bit 0  
#define MCUCR_ISC01  1   //INT0 sense control bit 1
#define MCUCR_ISC10  2   //INT1 sense control bit 0
#define MCUCR_ISC11  3   //INT1 sense control bit 1
#define MCUCSR_ISC2   6   //INT2 sense control      
//INT NUMBER 
#define INT0  0 
#define INT1  1 
#define INT2  2 
//define peripheral interrupt  bits 
#define GICR_INT0  6     //INT0 PIE 
#define GICR_INT1  7     //INT1 PIE
#define GICR_INT2  5     //INT2 PIE 


/*					define macro for syntax of interrupts function					*/
 #define  EXT_INT0				__vector_1
 #define  EXT_INT1				__vector_2
 #define  EXT_INT2				__vector_3 
 #define  TIMER0_COMP_INT		__vector_10
 #define  TIMER0_OVF_INT        __vector_11
 
 #define INT(INT_vect)   void INT_vect(void) __attribute__((signal,used));\
          void INT_vect(void)   

#endif /* EXINT_H_ */
