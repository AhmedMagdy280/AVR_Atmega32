/*
 * TIMER0_config.h
 *
 *  Created on: Jun 17, 2023
 *      Author: ahmed
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/*choose Timer1 mode :	1-NORMAL_MODE_T1
     		    		2-PPWM_MODE_T1
       					3-CTC_MODE_T1
	       				4-FPWM_MODE_T1
	       				*/

#define   TIMER1_MODE     NORMAL_MODE_T1

/*choose prescaler mode : 1-PRESCALER_T1_1
						  2-PRESCALER_T1_8
						  3-PRESCALER_T1_64
						  4-PRESCALER_T1_256
						  5-PRESCALER_T1_1024
						  6-EXT_CLK_FALLING_EDGE
						  7-EXT_CLK_RISING_EDGE
    				*/

#define   PRESCALER_T1_x     PRESCALER_T1_1024
/*choose ICU_MODE :1-ICU_ENABLE
 * 				   2-ICU_DISABLE
 * 				   */
#define   ICU_MODE         ICU_ENABLE

#endif /* TIMER1_CONFIG_H_ */
