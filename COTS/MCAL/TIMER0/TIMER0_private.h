/*
 * TIMER.h
 *
 * Created: 3/6/2023 3:21:39 PM
 *  Author: Ahmed
 */ 

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

//MODES OF TIMER0 
#define  NORMAL_MODE    1
#define  PPWM_MODE      2
#define  CTC_MODE       3
#define  FPWM_MODE      4
//prescaler  value  
#define  STOP					0b000
#define  PRESCALER_1			0b001
#define  PRESCALER_8			0b010
#define  PRESCALER_64			0b011
#define  PRESCALER_256			0b100
#define  PRESCALER_1024			0b101
#define  EXT_CLK_FALLING_EDGE   0b110
#define  EXT_CLK_RISING_EDGE    0b111

//PWM TYPE
#define  INVERTING_PWM		 1
#define  NONINVERTING_PWM    2
#define  T0_ON               3
#define  T0_OFF              4

/*				define macros  controlling registers	     		*/
//waveform generation mode (CTC / PWM(FAST/PHASE CORRECT)/NORMAL)
#define TCCR0_WGM00    6
#define TCCR0_WGM01    3
//Compare match output mode 
#define TCCR0_COM00    4
#define TCCR0_COM01    5
//clock select 
#define TCCR0_CS00     0     
#define TCCR0_CS01     1
#define TCCR0_CS02     2
//Timer0 Overflow Interrupt Enable
#define TIMSK_TOIE0    0
//TIMER0 output compare match interrupt enable
#define TIMSK_OCIE0   1
//Timer/Counter0 Overflow Flag
#define TIF_TOV0      0
// Output Compare Flag 
#define TIF_OCF0      1

#endif /* TIMER0_PRIVATE_H_ */
