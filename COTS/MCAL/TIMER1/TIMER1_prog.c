/*
 * TIMER.c
 *
 * Created: 3/6/2023 3:22:06 PM
 *  Author: Ahmed
 */ 
//include part 
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "registers.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"


#define FCPU     16UL

/*				Function implementations						*/

static void (* gptrtofunc)(void) = NULL;

//initialize function
void TIMER1_init (void){
	#if TIMER1_MODE == NORMAL_MODE_T1
		clr_bit(TCCR1A ,TCCR1A_COM1A0) ;
		clr_bit(TCCR1A ,TCCR1A_COM1A1) ;
	#endif
	#if  ICU_MODE  == ICU_ENABLE
		set_bit(TCCR1B , TCCR1B_ICES1) ;
		set_bit(TIMSK ,TIMSK_TICIE1) ;
	#elif ICU_MODE  == ICU_DISABLE
		clr_bit(TCCR1B , TCCR1B_ICES1) ;
		clr_bit(TIMSK ,TIMSK_TICIE1) ;
	#endif

	}

	

//function take prescaler and start timer
void TIMER1_start (void){
#if(PRESCALER_x >= 0 && PRESCALER_x <= 7)
	TCCR1B = TCCR1B & 0xF8 ;
	TCCR1B = TCCR1B | PRESCALER_T1_x;

	#else
	#error "Wrong PRESCALER_x "

	#endif
}

void TIMER1_stop(void){
	TCCR1A = TCCR1A &0xf8;
}



void TIMER1_ICU_void_setTrigg(u8 sense_edge)
{
  if(sense_edge == ICU_RISING_EDGE){

	 set_bit(TCCR1B , TCCR1B_ICES1) ;

  }else if(sense_edge == ICU_FALLING_EDGE){
	  clr_bit(TCCR1B , TCCR1B_ICES1) ;
  }
}

void TIMER1_ICU_IntEnable(void){
	set_bit(TIMSK ,TIMSK_TICIE1) ;
}

void TIMER1_ICU_IntDisable(void)
{
	clr_bit(TIMSK ,TIMSK_TICIE1) ;
}

u16 TIMER1_ICU_takeReading(void){
	return ICR1 ;
}

void TIMER1_ICU_setCallBack(void (*fptr)(void) ){
	if(fptr != NULL){
		gptrtofunc = fptr ;
	}
}


void __vector_6(void) __attribute__((signal,used)) ;
void __vector_6(void) {
	if(gptrtofunc !=NULL){
		//CALL THE address of function from app layer
		gptrtofunc() ;
	}else {}
}

