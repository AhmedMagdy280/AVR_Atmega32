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
#include   "TIMER0_private.h"
#include   "TIMER0_config.h"
#include   "TIMER0_interface.h"


#define FCPU     16UL

/*				Function implementations						*/

volatile static  u64 OVF_count = 0 ;
volatile static  u64 OVF_Getcount = 0;
static   u8  Gremainig_count = 0 ;
 static void (* gptrtofunc[2])(void) = {NULL,NULL } ;

//initialize function
void TIMER0_init (void){

       #if TIMER_MODE  == 	NORMAL_MODE
		clr_bit(TCCR0,TCCR0_WGM00) ;
		clr_bit(TCCR0,TCCR0_WGM01) ;

		#elif TIMER_MODE  == PPWM_MODE
		set_bit(TCCR0,TCCR0_WGM00) ;
		clr_bit(TCCR0,TCCR0_WGM01) ;
		#if		PPWM_TYPE == NONINVERTING_PWM
		clr_bit(TCCR0 , TCCR0_COM00);
		set_bit(TCCR0 , TCCR0_COM01);

		#elif	PPWM_TYPE == INVERTING_PWM
		set_bit(TCCR0 , TCCR0_COM00);
		set_bit(TCCR0 , TCCR0_COM01);
		#endif
		#elif TIMER_MODE  == CTC_MODE
		clr_bit(TCCR0,TCCR0_WGM00) ;
		set_bit(TCCR0,TCCR0_WGM01) ;

		#elif TIMER_MODE  == FPWM_MODE
		set_bit(TCCR0,TCCR0_WGM00) ;
		set_bit(TCCR0,TCCR0_WGM01) ;
		#if FPWM_TYPE  ==	NONINVERTING_PWM
		clr_bit(TCCR0 , TCCR0_COM00);
		set_bit(TCCR0 , TCCR0_COM01);
		#elif PPWM_TYPE ==  INVERTING_PWM
		set_bit(TCCR0 , TCCR0_COM00);
		set_bit(TCCR0 , TCCR0_COM01);
		#endif
		#else
		#error "Wrong TIMER MODE"
		#endif
		
	}
	
//TCNT start value
void TIMER0_GetCounts (u64 *OVF_number){
	u8 value_of_TCNT = TCNT0 ;
	*OVF_number = (OVF_Getcount*256) + value_of_TCNT ;
    }
//OCR compare  value
void TIMER0_comparevalue(u8 ocrvalue  ){
	OCR0= ocrvalue  ;
}
//function take prescaler and start timer
void TIMER0_start (void){
/*
 * #if(PRESCALER_x >= 0 && PRESCALER_x <= 7)
 *   TCCR0 = TCCR0 & 0xF8
 *   TCCR0 = TCCR0 | PRESCALER_x;
 */

  #if(PRESCALER_x >= 0 && PRESCALER_x <= 7)
    TCCR0 = TCCR0 & 0xF8 ;
	TCCR0 = TCCR0 | PRESCALER_x;
	/*#if   PRESCALER_x	 == PRESCALER_1
		TCCR0 = (TCCR0 &0xf8)|(PRESCALER_1) ;
	#elif PRESCALER_x	 == PRESCALER_8
		TCCR0 = (TCCR0 &0xf8)|(PRESCALER_8) ;
	#elif PRESCALER_x	 == PRESCALER_64
		TCCR0 = (TCCR0 &0xf8)|(PRESCALER_64) ;
	#elif PRESCALER_x	 == PRESCALER_256
		TCCR0 = (TCCR0 &0xf8)|(PRESCALER_256) ;
	#elif PRESCALER_x	 == PRESCALER_1024
		TCCR0 = (TCCR0 &0xf8)|(PRESCALER_1024) ;

	#elif PRESCALER_x	 ==  EXT_CLK_FALLING_EDGE
		TCCR0 = (TCCR0 &0xf8)|(EXT_CLK_FALLING_EDGE) ;
	#elif PRESCALER_x	 ==  EXT_CLK_RISING_EDGE
		TCCR0 = (TCCR0 &0xf8)|(EXT_CLK_RISING_EDGE) ;
		*/
	#else
	#error "Wrong PRESCALER_x "

	#endif
}

void TIMER0_stop(void){
	TCCR0 = TCCR0 &0xf8;
}

void TIMER0_setDelayTimeMilliSec(u16 MilliSec_time){
 const u16 map_arry[5] = {1 ,8 ,64,256 ,1024} ;
 f64 Tick_Time =(f64)(map_arry[PRESCALER_x -1])/FCPU ;
 u64 Countrequirement = (f64)(MilliSec_time/Tick_Time)*1000 ;
 u32 Number_Of_OVF = Countrequirement/256 ;
 u8 remainig_count = Countrequirement%265 ;
 if(remainig_count != 0)
 {
	 TCNT0 = 256 - remainig_count ;
	 OVF_count = Number_Of_OVF+1 ;
	 Gremainig_count =remainig_count ;
 }



}

void TIMER0_setFastPWM(u8 duty){
	u8 ocr_value = (f32)(duty*256)/100.0 ;

	#if FPWM_TYPE  ==	NONINVERTING_PWM
	OCR0 = ocr_value ;
	#elif  FPWM_TYPE  == INVERTING_PWM
	OCR0 = 256-ocr_value ;
	#endif
}

void TIMER0_setphaseCorrectPWM(u8 duty){
	u8 ocr_value = (f32)(duty*255)/100.0 ;
		#if PPWM_TYPE  ==	NONINVERTING_PWM
		OCR0 = ocr_value ;
		#elif  PPWM_TYPE  == INVERTING_PWM
		OCR0 = 256-ocr_value ;
		#endif
}

//function to enable INT (PIE)
void TIMER0_enableINT(u8 INTtype){
	switch(INTtype){
		case TIMER0_OVF  :
		set_bit(TIMSK ,TIMSK_TOIE0) ;
		break;
		case TIMER0_COMP:
		set_bit(TIMSK , TIMSK_OCIE0);
		break;
		case ALL_INT :
			set_bit(TIMSK ,TIMSK_TOIE0) ;
			set_bit(TIMSK , TIMSK_OCIE0);
			break ;
	}

}
//function to disable INT (PIE)
void TIMER0_disableINT(u8 INTtype){
	switch(INTtype){
		case  TIMER0_OVF  :
		clr_bit(TIMSK ,TIMSK_TOIE0) ;
		break;
		case TIMER0_COMP :
		clr_bit(TIMSK , TIMSK_OCIE0);
		break;

		case ALL_INT :
		clr_bit(TIMSK ,TIMSK_TOIE0) ;
		clr_bit(TIMSK , TIMSK_OCIE0);
		break ;
	}

}

void TIMER0_setCallBack(void (*fptr)(void) , u8 ID){
	if(fptr != NULL){
		gptrtofunc[ID] = fptr ;
	}
}


void __vector_10(void) __attribute__((signal,used)) ;
void __vector_10(void) {
	if(gptrtofunc[TIMER0_COMP]!=NULL){
		//CALL THE address of function from app layer
		gptrtofunc[TIMER0_COMP]() ;
	}else {}
}

void __vector_11(void) __attribute__((signal,used)) ;
void __vector_11(void) {
	static u64 OVF_Localcount = 0 ;
	OVF_Localcount++ ;
	OVF_Getcount++;
	if(OVF_Localcount == OVF_count){
	if(gptrtofunc[TIMER0_OVF]!=NULL){
		//CALL THE address of function from app layer
		gptrtofunc[TIMER0_OVF]() ;
		OVF_Localcount = 0 ;
		TCNT0=Gremainig_count;

	}else {}
	}else{}
}
