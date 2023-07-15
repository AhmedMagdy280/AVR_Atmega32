/*
 * UART.c
 *
 * Created: 3/20/2023 8:59:49 AM
 *  Author: Ahmed
 */ 
//include part 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "registers.h"
#include "DIO.h"
#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "CLCD_interface.h"
void (*G_UART1_CallBack)(u8 data);

//initialize function
void UART_init(u8 baudrate , u8 parity , u8 numofstopbits , u8 speed , u8 data_size , u8 frequancy) {
	//CHOOSE SPEED
		switch(frequancy){

	case F_8 :
	//CHOOSE SPEED
	switch(speed){
		//CHOOSE BAUD RATE FOR NORMAL SPEED
		case NORMAL_SPEED :
		clr_bit(UCSRA , UCSRA_U2X) ;
		switch(baudrate){
		case baud_2400 :clr_bit(UCSRC,UCSRC_RSEL) ;
		UBRRH = 0x00;
		UBRRL = 207	; break;

		case baud_9600 :clr_bit(UCSRC,UCSRC_RSEL) ;
		UBRRH = 0x00;
		UBRRL = 51	;
		break;
		case baud_115K :clr_bit(UCSRC,UCSRC_RSEL) ;
		UBRRH = 0x00;
		UBRRL = 3	;
		break ;
	}break;
	//CHOOSE BAUD RATE FOE 2X SPEED
	case X2_SPEED :
	set_bit(UCSRA , UCSRA_U2X) ;
	switch(baudrate){
		case baud_2400 :clr_bit(UCSRC,UCSRC_RSEL) ;
		UBRRH = 0x01;
		UBRRL = 0xA0; break;
		case baud_9600 :clr_bit(UCSRC,UCSRC_RSEL) ;
		UBRRH = 0x00;
		UBRRL = 103	;
		break;
		case baud_115K :clr_bit(UCSRC,UCSRC_RSEL) ;
		UBRRH = 0x00;
		UBRRL = 8	;
		break ;

	} break;
}     break ;
	case F_16 :   switch(speed){
//CHOOSE BAUD RATE FOR NORMAL SPEED
	case NORMAL_SPEED :
clr_bit(UCSRA , UCSRA_U2X) ;
switch(baudrate){
case baud_2400 :clr_bit(UCSRC,UCSRC_RSEL) ;
UBRRH = 0x01;
UBRRL = 0xA0;
break;
case baud_9600 :clr_bit(UCSRC,UCSRC_RSEL) ;
UBRRH = 0x00;
UBRRL = 103	;
break;
case baud_115K :clr_bit(UCSRC,UCSRC_RSEL) ;
UBRRH = 0x00;
UBRRL = 8	;
break ;
}break;
//CHOOSE BAUD RATE FOE 2X SPEED
case X2_SPEED :
set_bit(UCSRA , UCSRA_U2X) ;
switch(baudrate){
case baud_2400 :clr_bit(UCSRC,UCSRC_RSEL) ;
UBRRH = 0x03;
UBRRL = 0x40; break;
case baud_9600 :clr_bit(UCSRC,UCSRC_RSEL) ;
UBRRH = 0x00;
UBRRL = 207	;
break;
case baud_115K :clr_bit(UCSRC,UCSRC_RSEL) ;
UBRRH = 0x00;
UBRRL = 16	;
break ;
} break;
}     break ;

	}   //set select bit to write on UCSRC register
   set_bit(UCSRC, UCSRC_RSEL)  ;
   //SET DATA SIZE 8 BIT
   switch(data_size){
   case EIGHT_BIT :
   set_bit(UCSRC , UCSRC_UCSZ0);
   set_bit(UCSRC , UCSRC_UCSZ1);
   clr_bit(UCSRB , UCSRB_UCSZ2);
   break ;
   case SEVEN_BIT :
   clr_bit(UCSRC , UCSRC_UCSZ0);
   set_bit(UCSRC , UCSRC_UCSZ1);
   clr_bit(UCSRB , UCSRB_UCSZ2);
   break ;

   case FIVE_BIT :
   clr_bit(UCSRC , UCSRC_UCSZ0);
   clr_bit(UCSRC , UCSRC_UCSZ1);
   clr_bit(UCSRB , UCSRB_UCSZ2);
   break ;
   case SIX_BIT :
   set_bit(UCSRC , UCSRC_UCSZ0);
   clr_bit(UCSRC , UCSRC_UCSZ1);
   clr_bit(UCSRB , UCSRB_UCSZ2);
	      break ;
   case NINE_BIT :
	   set_bit(UCSRC , UCSRC_UCSZ0);
	   set_bit(UCSRC , UCSRC_UCSZ1);
	   set_bit(UCSRB , UCSRB_UCSZ2);
	   break ;
   }
   //CHOOSE PARITY
   set_bit(UCSRC , UCSRC_RSEL) ;
   switch(parity){
	   case DISABLE_PARITY: clr_bit(UCSRC , UCSRC_UPM0) ; clr_bit(UCSRC ,UCSRC_UPM1) ; break ;
	   case EVEN_PARITY   : clr_bit(UCSRC , UCSRC_UPM0) ; set_bit(UCSRC ,UCSRC_UPM1) ; break ;
	   case ODD_PARITY    : set_bit(UCSRC , UCSRC_UPM0) ; set_bit(UCSRC ,UCSRC_UPM1) ; break ;
   }
   //CHOOSE NOMBER OF STOP BITS
   switch(numofstopbits){
	   case ONE_STOP: set_bit(UCSRC , UCSRC_RSEL);clr_bit(UCSRC,UCSRC_USBS) ; break;
	   case TWO_STOP: set_bit(UCSRC , UCSRC_RSEL);set_bit(UCSRC,UCSRC_USBS) ; break;
   }
}


//enable transmitter
void UART_enableTX(void) {
	set_bit(UCSRB , UCSRB_TXEN) ;
}
//enable receiver
void UART_enableRX(void) {
	set_bit(UCSRB , UCSRB_RXEN) ;
}
//transmit data
void UART_sendByte(u8 data){
	 while(!get_bit(UCSRA,UCSRA_UDRE)) ;
		 UDR = data ;

}

void UART_sendString( u8 *str){


	while (*str != '\0'){
		UART_sendByte(*str) ;
			 str++ ;
}
}
//receive data
u8 UART_receiveByteSynchNonBlocking (void) {
	u8 loc_u8Data = 0;
		u32 loc_u8TimeOut = 0;
		while ((get_bit(UCSRA ,UCSRA_RXC)==0) && (loc_u8TimeOut < THRESHOLD_VALUE) )
		{
			loc_u8TimeOut++;
		}
		if (loc_u8TimeOut==THRESHOLD_VALUE)
		{
			loc_u8Data = 255;
		}
		else
		{
			loc_u8Data =  UDR;
		}
		return loc_u8Data;
}

void UART_receiveByteAsynchCallBack(void (*ptrf)(u8 data)){
	set_bit(UCSRB ,UCSRB_RXCIE);
	G_UART1_CallBack = ptrf ;
}

void __vector_13(void) __attribute__((signal,used)) ;
void __vector_13(void){
	 G_UART1_CallBack(UDR);
}

