/*
 * DCMOTOR_interface.h
 *
 *  Created on: Jun 19, 2023
 *      Author: ahmed
 */

#ifndef DC_MOTOR_DCMOTOR_INTERFACE_H_
#define DC_MOTOR_DCMOTOR_INTERFACE_H_

typedef  struct  {
	u8 port ;
	u8 pin1 ;
	u8 pin2 ;
}DC_motor_t ;

#define  LEFT  1
#define  RIGHT 2

void DC_Motor_Init(DC_motor_t MOTOR );
void DC_Motor_ON(DC_motor_t MOTOR , u8 speed ,u8 direction );
void DC_Motor_OFF(DC_motor_t MOTOR) ;

#endif /* DC_MOTOR_DCMOTOR_INTERFACE_H_ */
