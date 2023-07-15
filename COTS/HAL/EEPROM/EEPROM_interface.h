/*
 * EEPROM_interface.h
 *
 *  Created on: Jun 25, 2023
 *      Author: ahmed
 */

#ifndef EEPROM_EEPROM_INTERFACE_H_
#define EEPROM_EEPROM_INTERFACE_H_


void EEPROM_Init(void);
void EEPROM_WriteByte(u16 addr, u8 data);
void EEPROM_ReadByte(u16 addr, u8 *data);
#endif /* EEPROM_EEPROM_INTERFACE_H_ */
