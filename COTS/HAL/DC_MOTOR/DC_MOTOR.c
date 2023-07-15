/*
 * DC_MOTOR.c
 *
 *  Created on: Jun 19, 2023
 *      Author: ahmed
 */
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "DIO.h"
#include  "TIMER0_interface.h"
#include  "DCMOTOR_private.h"
#include  "DCMOTOR_config.h"
#include  "DCMOTOR_interface.h"


void DC_Motor_Init(DC_motor_t MOTOR ){
 DIO_initpin(MOTOR.port , MOTOR.pin1 ,OUT) ;
 DIO_initpin(MOTOR.port , MOTOR.pin2 ,OUT) ;
 DIO_writepin(MOTOR.port , MOTOR.pin1 ,LOW) ;
 DIO_writepin(MOTOR.port , MOTOR.pin2 ,LOW) ;

 TIMER0_init();
}

void DC_Motor_ON(DC_motor_t MOTOR , u8 speed ,u8 direction ){
	switch (direction){
	case LEFT : DIO_writepin(MOTOR.port , MOTOR.pin1 ,LOW) ;
	 	 	 	DIO_writepin(MOTOR.port , MOTOR.pin2 ,HIGH) ;break ;

	case RIGHT : DIO_writepin(MOTOR.port , MOTOR.pin1 ,HIGH) ;
	 			DIO_writepin(MOTOR.port , MOTOR.pin2 ,HIGH) ;break ;
	}
	TIMER0_setphaseCorrectPWM(speed) ;
	DIO_initpin(PORTB ,PIN_3 ,OUT) ;
	TIMER0_start() ;
}

void DC_Motor_OFF(DC_motor_t MOTOR){

	DIO_writepin(MOTOR.port , MOTOR.pin1 ,LOW) ;
    DIO_writepin(MOTOR.port , MOTOR.pin2 ,LOW) ;
}
