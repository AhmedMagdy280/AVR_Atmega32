/*
 * UART.h
 *
 * Created: 3/20/2023 8:59:39 AM
 *  Author: ahmed
 */ 


#ifndef UART_H_
#define UART_H_
//INCLUDE PART 
#include "registers.h"
#include "DIO.h"

/*				function prototype			*/
//initialize function   
void UART_init(u8 baudrate , u8 parity , u8 numofstopbits , u8 speed , u8 data_size , u8 frequancy) ;
//enable transmitter 
void UART_enableTX(void) ;
//enable receiver
void UART_enableRX(void) ;
//transmit data
void UART_sendByte(u8 data) ;
void UART_sendString(u8 *str) ;
//receive data
u8 UART_receiveByteSynchNonBlocking (void) ;

void UART_receiveByteAsynchCallBack(void (*ptrf)(u8 data));

//defines baud rate 
#define  baud_2400    1
#define  baud_9600    2
#define  baud_115K  3
//speed define 
#define NORMAL_SPEED    1
#define  X2_SPEED       2
//define parity mode
#define DISABLE_PARITY		1
#define EVEN_PARITY			2
#define ODD_PARITY			3	
//define number of stop bits mode 
#define ONE_STOP   1
#define TWO_STOP   2	

#define  F_8       1
#define  F_16      2

#define EIGHT_BIT   1
#define SEVEN_BIT   2
#define SIX_BIT     3
#define FIVE_BIT    4
#define NINE_BIT    5

#endif /* UART_H_ */
