/*
 * TIMER0_config.h
 *
 *  Created on: Jun 17, 2023
 *      Author: ahmed
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/*choose Timer mode :	1-NORMAL_MODE
     		    		2-PPWM_MODE
       					3-CTC_MODE
	       				4-FPWM_MODE
	       				*/

#define   TIMER_MODE     PPWM_MODE

/*choose Timer mode :	1-FPWM_MODE
     		    		2-PPWM_MODE
*/
#if       TIMER_MODE  == FPWM_MODE
/*choose FPWM_TYPE : 1- INVERTING_PWM
					 2- NONINVERTING_PWM
*/
#define  FPWM_TYPE       NONINVERTING_PWM

#elif 	TIMER_MODE  == PPWM_MODE

#define  PPWM_TYPE       NONINVERTING_PWM
#endif
/*choose prescaler mode : 1- PRESCALER_1
						  2-PRESCALER_8
						  3-PRESCALER_64
						  4-PRESCALER_256
						  5-PRESCALER_1024
						  6-EXT_CLK_FALLING_EDGE
						  7-EXT_CLK_RISING_EDGE
    				*/

#define   PRESCALER_x     PRESCALER_1024


#endif /* TIMER0_CONFIG_H_ */
