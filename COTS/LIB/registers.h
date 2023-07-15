/******************************************************************************************/
/*                             Author : Ahmed Magdy   									  */
/*        					   Version: 1.0											      */
/*                             registers file 											  */
/*        					   Date:28/2/2023										      */
/******************************************************************************************/

//guard of file

#ifndef  REGISTER_H_

#define  REGISTER_H_
//includes
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*					DIO REGISTERS						*/
//port A  register
#define  PORT_A    *((volatile u8*)0x3B)
#define  DDR_A     *((volatile u8*)0x3A)
#define  PIN_A     *((volatile u8*)0x39)
//PORT B  register
#define  PORT_B    *((volatile u8*)0x38)
#define  DDR_B     *((volatile u8*)0x37)
#define  PIN_B     *((volatile u8*)0x36)
//PORT C  register
#define  PORT_C    *((volatile u8*)0x35)
#define  DDR_C     *((volatile u8*)0x34)
#define  PIN_C     *((volatile u8*)0x33)
//PORT  D  register
#define  PORT_D    *((volatile u8*)0x32)
#define  DDR_D     *((volatile u8*)0x31)
#define  PIN_D     *((volatile u8*)0x30)
/*				END OF DIO REGISTERS			*/
/*				status register				*/
#define SREG				 *((volatile u8 *)0x5F)
/*				INTERRUPTS REGISTERS			*/

//register responsible to control sense mode for INT1 & INT0
#define MCUCR            *((volatile u8 *)0x55)
//register responsible to control sense mode for INT2 
#define MCUCSR	         *((volatile u8 *)0x54)
//register responsible to peripheral interrupt
#define GICR			 *((volatile u8 *)0X5B)
//register responsible to flag interrupt  
#define GIFR			 *((volatile u8 *)0x5A)
/*			END OF INTERRUPTS REGISTERS			*/
/*				TIMER REGISTERS					*/
//TIMER COUNTER CONTROL REGISTER for timer0 
#define TCCR0			 *((volatile u8*)0x53)
//timer counter register for timer0
#define TCNT0			 *((volatile u8*)0x52)
//output compare register for timer0
#define OCR0			 *((volatile u8*)0x5C)
//Timer Interrupt Mask register 
#define TIMSK			 *((volatile u8*)0x59)
//Timer interrupt flag register
#define TIFR			 *((volatile u8*)0x58)
//Special Function IO Register
#define SFIOR			 *((volatile u8*)0x50)
/*		   	  END OF TIMER REGISTERS				*/
/*				ADC REGISTERS						*/
#define		ADCMUX				*((volatile u8*)0X27)
#define		ADCSRA				*((volatile u8*)0X26)
#define		ADCL				*((volatile u16*)0X24)
#define		ADCH				*((volatile u8*)0X25)

/*				END ADC REGISTERS					*/
/*				UART REGISTERS						*/
#define		UDR					     *((volatile u8*)0x2C)
#define		UCSRA					 *((volatile u8*)0x2B)
#define		UCSRB					 *((volatile u8*)0x2A)
#define		UCSRC					 *((volatile u8*)0x40)
#define		UBRRL					 *((volatile u8*)0x29)
/*				END UART REGISTERS					*/
/*				SPI REGISTERS						*/
#define		SPCR			*((volatile u8*)0x2D)
#define		SPSR			*((volatile u8*)0x2E)
#define		SPDR			*((volatile u8*)0x2F)
/*				END SPI REGISTERS					*/
/*				TIMER1 REGISTERS						*/
#define		TCCR1A			*((volatile u8*)0x4F)
#define		TCCR1B			*((volatile u8*)0x4E)
#define		TCNT1			*((volatile u16*)0x4C)
#define     OCR1A			*((volatile u16*)0x4A)
#define     OCR1B           *((volatile u16*)0x48)
#define     ICR1			*((volatile u16*)0x46)
/*				END TIMER1 REGISTERS					*/
/*				I2C REGISTERS						*/
#define		TWBR		            *((volatile u8*)0x20)
#define		TWCR                    *((volatile u8*)0x56)
#define		TWSR                    *((volatile u8*)0x21)
#define     TWDR                    *((volatile u8*)0x23)
#define     TWAR                   	*((volatile u8*)0x22)
/*				END I2C REGISTERS							*/


//end of guard
#endif

