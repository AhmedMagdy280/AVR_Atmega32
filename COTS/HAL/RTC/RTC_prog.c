/*
 * RTC_prog.c
 *
 *  Created on: Jun 28, 2023
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "I2C_interface.h"
#include "RTC_private.h"
#include "RTC_config.h"
#include "RTC_interface.h"
#include "CLCD_interface.h"

void RTC_init(void){
	I2C_masterinit() ;
	I2C_sendStart() ;
	I2C_sendByte(0xD0);
	I2C_sendByte(0x07);
	I2C_sendByte(0x00);
	I2C_sendStop();
}

void RTC_SetTime(u8 h , u8 m  ,u8 s ){
	I2C_sendStart() ;
	I2C_sendByte(0xD0);
	I2C_sendByte(0x00);
	I2C_sendByte(s) ;
	I2C_sendByte(m) ;
	I2C_sendByte(h) ;
	I2C_sendStop()  ;
}

void RTC_ReadTime(u8* h , u8* m  ,u8* s ){
	I2C_sendStart() ;
	I2C_sendByte(0xD0);
	I2C_sendByte(0x00);
	I2C_sendStop()    ;
	I2C_sendStart()   ;
	I2C_sendByte(0xD1);
	I2C_receiveByte_ACK(s) ;
	I2C_receiveByte_ACK(m) ;
	I2C_receiveByte_NoACK(h) ;
	I2C_sendStop() ;

}

void RTC_SetDate(u8 d , u8 mon  ,u8 year ){
	I2C_sendStart() ;
	I2C_sendByte(0xD0);
	I2C_sendByte(0x04);
	I2C_sendByte(d) ;
	I2C_sendByte(mon) ;
	I2C_sendByte(year) ;
	I2C_sendStop()  ;
}

void RTC_ReadDate(u8* d , u8* mon  ,u8* year ){
	I2C_sendStart() ;
	I2C_sendByte(0xD0);
	I2C_sendByte(0x04);
	I2C_sendStop()    ;
	I2C_sendStart()   ;
	I2C_sendByte(0xD1);
	I2C_receiveByte_ACK(d) ;
	I2C_receiveByte_ACK(mon) ;
	I2C_receiveByte_NoACK(year) ;
	I2C_sendStop() ;

}
