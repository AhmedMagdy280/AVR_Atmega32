/*
 * RTC_interface.h
 *
 *  Created on: Jun 28, 2023
 *      Author: ahmed
 */

#ifndef RTC_RTC_INTERFACE_H_
#define RTC_RTC_INTERFACE_H_

void RTC_init(void);
void RTC_SetTime(u8 h , u8 m  ,u8 s ) ;
void RTC_ReadTime(u8* h , u8* m  ,u8* s ) ;
void RTC_SetDate(u8 d , u8 mon  ,u8 year );

void RTC_ReadDate(u8* d , u8* mon  ,u8* year );
#endif /* RTC_RTC_INTERFACE_H_ */
