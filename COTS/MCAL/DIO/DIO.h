/******************************************************************************************/
/*                             Authar : Ahmed Magdy   									  */
/*        					   Version: 1.0											      */
/*                             DIO interface 											  */
/*        					   Date:28/2/2023										      */
/******************************************************************************************/

//guard of file
#ifndef  DIO_H_
#define  DIO_H_
//INCLUDE REGISTERS
#include"registers.h"
//initialize function
void DIO_initpin     ( u8 PORT  ,  u8 PIN  , u8 direction ) ;
void DIO_initport    (u8 PORT   ,  u8 direction                ) ;
//function to write on pin
void DIO_writepin    ( u8 PORT  ,  u8 PIN  , u8 value     ) ;
void DIO_writeport   ( u8 PORT  ,  u8 value                    ) ;
//function to toggle pin
void DIO_togglepin   ( u8 PORT  ,  u8 PIN 					 ) ;
//function to read pin
void DIO_readpin     ( u8 PORT  ,  u8 PIN  , u8 * value   ) ;
void DIO_readport    ( u8 PORT  ,  u8 *value                   ) ;

//TO SET PIN  1
#define  HIGH   1
//TO SET PIN 0
#define  LOW    0
//TO SET DIRECTION OUT
#define  OUT    1
//TO SET DIRECTION IN
#define  IN     0

//defines PORTS
#define PORTA  'A'
#define PORTB  'B'
#define PORTC  'C'
#define PORTD  'D'

//Defines port number  
#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7
//end of guard
#endif
