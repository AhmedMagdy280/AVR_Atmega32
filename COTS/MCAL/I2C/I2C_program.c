/*
 * I2C_program.c
 *
 *  Created on: Jun 25, 2023
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "registers.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"
#include "CLCD_interface.h"

void I2C_masterinit(void){
	/*clock init to speed 100Kb/s*/
	clr_bit(TWCR , TWCR_TWIE) ;
	TWBR =72 ;

}

u8 I2C_sendStart(void){

	TWCR = (1<<	TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN) ;
	while (!(TWCR & (1<<TWCR_TWINT)));
	return (TWSR & 0xF8) ;

}
u8 I2C_sendSlvaeAddress(u8 slave_address , u8 rw){
	TWDR = (slave_address<<1) | (rw) ;
	TWCR = (1<<TWCR_TWINT) |(1<<TWCR_TWEN) ;

	clr_bit(TWCR ,TWCR_TWSTA) ;
	while (!(TWCR & (1<<TWCR_TWINT)));
	return (TWSR & 0xF8) ;
}
u8 I2C_sendByte(u8 copy_u8data){
	TWDR = copy_u8data;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

	while (!(TWCR & (1<<TWCR_TWINT)));
	return (TWSR & 0xF8) ;
}
void I2C_sendStop(void){
	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTO);
	for(u8 i = 0 ; i<100 ; i++) ;
}
u8 I2C_receiveByte_ACK(u8 * ptr ){

	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWEA) ;

	while (!(TWCR & (1<<TWCR_TWINT)));

	* ptr = TWDR ;

	return (TWSR& 0xF8) ;
}
u8 I2C_receiveByte_NoACK(u8 * ptr){
	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWEN) ;
	while (!(TWCR & (1<<TWCR_TWINT)));
	* ptr = TWDR ;
	return (TWSR& 0xF8) ;

}
void I2C_getStatus(u8* status ){
	*status = TWSR & 0xF8;
}
