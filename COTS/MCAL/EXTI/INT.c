/*
 * EXINT.c
 *
 * Created: 3/4/2023 9:56:14 PM
 *  Author: ahmed
 */ 

//include part 
#include "INT.h" 

//global array of pointer to function  
//static because i do not need that var call in another files 
/*      static void (* gptrtofunc[3])(void) = {NULL} ;*/
//function part 

/*				initialize function					*/  

 void EXINT0_init(u8 sensemode  ){
	  DIO_initpin(PORTD ,PIN_2 , IN) ;
	 //set sense mode 
	  switch(sensemode){
	  case FALLING_EDGE:  
	 clr_bit(MCUCR,MCUCR_ISC00) ;
	 set_bit(MCUCR,MCUCR_ISC01) ; 
    break;
	
	case RISING_EDGE :  
	set_bit(MCUCR , MCUCR_ISC00) ;
	set_bit(MCUCR , MCUCR_ISC01) ;
	break; 
	
	case  LOW_LEVEL : 
	clr_bit(MCUCR , MCUCR_ISC00) ;
	clr_bit(MCUCR , MCUCR_ISC01) ;
	break; 
	
	case ON_CHANGE: 
	set_bit(MCUCR , MCUCR_ISC00) ;
	clr_bit(MCUCR , MCUCR_ISC01) ; 
	break;
	  }
 }
 
 void EXINT1_init(u8 sensemode  ){
	  DIO_initpin(PORTD ,PIN_3 , IN) ;
	 //set sense mode
	 switch(sensemode){
		 case FALLING_EDGE:
		 clr_bit(MCUCR,MCUCR_ISC10) ;
		 set_bit(MCUCR,MCUCR_ISC11) ;
		 break;
		 
		 case RISING_EDGE :
		 set_bit(MCUCR , MCUCR_ISC10) ;
		 set_bit(MCUCR , MCUCR_ISC11) ;
		 break;
		 
		 case  LOW_LEVEL :
		 clr_bit(MCUCR , MCUCR_ISC10) ;
		 clr_bit(MCUCR , MCUCR_ISC11) ;
		 break;
		 
		 case ON_CHANGE:
		 set_bit(MCUCR , MCUCR_ISC10) ;
		 clr_bit(MCUCR , MCUCR_ISC11) ;
		 break;
	 }
 }
 void EXINT2_init(u8 sensemode  ){
	  DIO_initpin(PORTB ,PIN_2 , IN) ;
	 //set sense mode
	 switch(sensemode){
		 case FALLING_EDGE:
		 clr_bit(MCUCSR,MCUCSR_ISC2) ;
		 break;
		 
		 case RISING_EDGE :
		 set_bit(MCUCSR , MCUCSR_ISC2) ;
		 break;
	 }
 }
 /*				enable interrupt function			*/
 //interrupt 0
 void ETINT0_enable(void ){
	 
	 set_bit(GICR , GICR_INT0)  ;
 }
 //interrupt 1
 void ETINT1_enable(void ) {
	 
	  set_bit(GICR , GICR_INT1)  ;
 }
 //interrupt 2
 void ETINT2_enable(void ) {
	 
	  set_bit(GICR , GICR_INT2)  ;
 }
 /*				disable interrupt function			*/
 //interrupt 0
 void ETINT0_disable(void )	{
	 
	  clr_bit(GICR , GICR_INT0)  ;
 }
 //interrupt 1
 void ETINT1_disable(void ) {
	 
	  clr_bit(GICR , GICR_INT1)  ;
 }
 //interrupt 2
 void ETINT2_disable(void ) {
	 
	 clr_bit(GICR , GICR_INT2)  ;
 } 
 /**********************************************************************************
//function to call the address of function i need do it when  interrupts is happen
 void setcallbackfunc(void (*ptrtofunc)(void), u8 NUMINT) {
	 
	 gptrtofunc[NUMINT] = ptrtofunc ;
 }

//command to tell compiler this call by software do not optimize it for int0
void __vector_1(void) __attribute__((signal,used)) ;
//ISR IMPLEMENTATION INT0  
void __vector_1(void) {
	if(gptrtofunc[INT0]!=NULL){
		//CALL THE address of function from app layer 
		gptrtofunc[INT0]() ;
	}else {} 
}

//command to tell compiler this call by software do not optimize it for int1
void __vector_2(void) __attribute__((signal,used)) ;

//ISR IMPLEMENTATION INT1

void __vector_2(void) {
	if(gptrtofunc[INT1]!=NULL){
		//CALL THE address of function from app layer
		gptrtofunc[INT1]() ;
	}else{}
}

//command to tell compiler this call by software do not optimize it for int2
void __vector_3(void) __attribute__((signal,used)) ;


//ISR IMPLEMENTATION INT2

void __vector_3(void) {
	if(gptrtofunc[INT2]!=NULL){
		//CALL THE address of function from app layer
		gptrtofunc[INT2]() ;
	}else {}
}
********************************************************************************/
