/*
 * EEPROM_program.c
 *
 *  Created on: Jun 25, 2023
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCD_interface.h"
#include "I2C_interface.h"

void EEPROM_Init(void)
{
  I2C_masterinit();
}

void EEPROM_WriteByte(u16 addr, u8 data)
{
//  u8 state = 0;
//
//
//  // Start TWI
//  I2C_sendStart();
//  // Get State
//  I2C_getStatus(&state) ;
//  // Check if TWI Start
//  if (state != START_ACK)
//  {
//    return 0;
//  }
//  state = 0 ;
//
//  I2C_sendByte(0b10100000) ;
//  // Get Status
//  I2C_getStatus(&state) ;
//
//  if (state != SLAVE_ADDRESS_W_ACK)
//  {
//    return 0;
//  }
//
//  state = 0 ;
//
//  I2C_sendByte((u8) addr);
//
//  // Get State
//  I2C_getStatus(&state) ;
//
//
//  if (state != MASTER_W_BYTE_ACK)
//  {
//    return 0;
//  }
//  state = 0 ;
//  // Send Data
//  I2C_sendByte(data);
//
//  // Get Status
//  I2C_getStatus(&state) ;
//
//
//  if (state != MASTER_W_BYTE_ACK)
//  {
//
//    return 0;
//  }
//  state = 0 ;
//  // TWI Stop
//  I2C_sendStop();
//  // Return Done
//  return 1;

	I2C_sendStart() ;
	I2C_sendByte(0b10100000) ;
	I2C_sendByte(addr) ;
	I2C_sendByte(data) ;
	I2C_sendStop() ;
}

void EEPROM_ReadByte(u16 addr, u8 *data)
{
//
//  u8 state = 0;
//
//  // Start
//
//  I2C_sendStart();
//
//  // Get State
//  I2C_getStatus(&state) ;
//
//
//  if (state != START_ACK)
//  {return 0;}
//  state = 0 ;
//  I2C_sendByte(0b10100000) ;
//
//  // Get Status
//  I2C_getStatus(&state) ;
//
//
//  if (state != SLAVE_ADDRESS_W_ACK)
//  {  return 0; }
//  state = 0 ;
//
//  I2C_sendByte((u8) addr);
//
//  // Get State
//  I2C_getStatus(&state) ;
//
//
//  if (state != MASTER_W_BYTE_ACK)
//    {return 0; }
//
//  state = 0 ;
//  I2C_sendStart();
//
//  // Get State
//  I2C_getStatus(&state) ;
//
//
//  if (state != REP_START_ACK)
//    {return 0; }
//  state = 0 ;
//
//  I2C_sendByte(0b10100001);
//  // Get Status
//  I2C_getStatus(&state) ;
//
//
//  if (state != SLAVE_ADDRESS_R_ACK)
//    return 0;
//
//   I2C_receiveByte_ACK(data, I2C_NOT_ACK);
//
//  // Get Status
//   I2C_getStatus(&state) ;
//
//  // Check if it is
//  if (state != MASTER_R_BYTE_WITH_ACK)
//  {
//
//    return 0;
//  }
//  // TWI Stop
//  I2C_sendStop();
//
//  // Return Done
//  return 1;
	I2C_sendStart() ;
		I2C_sendByte(0b10100000) ;
		I2C_sendByte(addr) ;
		I2C_sendStart() ;
		I2C_sendByte(0b10100001) ;

		I2C_receiveByte_NoACK(data) ;
		I2C_sendStop() ;
}
