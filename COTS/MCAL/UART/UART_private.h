/*
 * UART_private.h
 *
 *  Created on: Jun 24, 2023
 *      Author: ahmed
 */

#ifndef UART_UART_PRIVATE_H_
#define UART_UART_PRIVATE_H_

//define baud rate register
#define  UBRRH     UCSRC
//define UCSRA flags bit
#define  UCSRA_RXC      7
#define  UCSRA_TXC      6
#define  UCSRA_UDRE     5
#define  UCSRA_FE		4
#define  UCSRA_DOR		3
#define  UCSRA_PE		2
#define  UCSRA_U2X		1
#define  UCSRA_MPCM     0
//define UCSRB  bit
#define  UCSRB_TXEN  3
#define  UCSRB_RXEN  4
//define bits of data size
#define  UCSRB_UCSZ2		2
#define  UCSRC_UCSZ1		2
#define  UCSRC_UCSZ0        1

//define bits of UCSRC
#define  UCSRC_RSEL			7
#define  UCSRC_UMSEL		6
#define  UCSRC_UPM1			5
#define  UCSRC_UPM0			4
#define  UCSRC_USBS			3

//define bits of interrupt
#define  UCSRB_RXCIE        7
#define THRESHOLD_VALUE        500000

#endif /* UART_UART_PRIVATE_H_ */
