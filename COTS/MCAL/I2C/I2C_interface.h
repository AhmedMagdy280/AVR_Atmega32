/*
 * I2C_interface.h
 *
 *  Created on: Jun 25, 2023
 *      Author: ahmed
 */

#ifndef I2C_I2C_INTERFACE_H_
#define I2C_I2C_INTERFACE_H_
#define   I2C_ACK        1
#define   I2C_NOT_ACK    0

#define START_ACK          			 	0x08
#define REP_START_ACK       			0x10
#define SLAVE_ADDRESS_W_ACK				0x18
#define SLAVE_ADDRESS_R_ACK				0x40
#define MASTER_W_BYTE_ACK				0x28
#define MASTER_R_BYTE_WITH_ACK			0x50
#define MASTER_R_BYTE_WITH_NACK			0x58
#define SLAVE_ADD_RECIEVE_R_REQ			0xA8
#define SLAVE_ADD_RECIEVE_W_REQ			0x60
#define SLAVE_DATA_RECEIVE				0x80
#define SLAVE_BYTE_TRAMSMIT				0xB8

#define   I2C_W    0
#define   I2C_R	   1
void I2C_masterinit(void);
u8 I2C_sendStart(void);
u8 I2C_sendSlvaeAddress(u8 slave_address , u8 rw) ;
u8 I2C_sendByte(u8 copy_u8data);
void I2C_sendStop(void);
u8 I2C_receiveByte_ACK(u8 * ptr);
u8 I2C_receiveByte_NoACK(u8 * ptr);
void I2C_getStatus(u8* status ) ;
#endif /* I2C_I2C_INTERFACE_H_ */
