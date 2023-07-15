/******************************************************************************************/
/*                             Authar : Ahmed Magdy   									  */
/*        					   Version: 1.0											      */
/*                             DIO implemention 										  */
/*        					   Date:28/2/2023										      */
/******************************************************************************************/

//include
#include"DIO.h"
//initialize function
void DIO_initpin     ( u8 PORT  ,  u8 PIN  , u8 direction ) {
	
	switch(PORT){
		case PORTA :
		if(direction==OUT){
			//OUTPUT PORT A
			set_bit(DDR_A,PIN) ;
			}else if (direction==IN ){
			//INPUT PORT A
			clr_bit(DDR_A,PIN) ;
			}else{
			
		}break ;
		case PORTB :
		if(direction==OUT){
			//OUTPUT PORT B
			set_bit(DDR_B,PIN) ;
			}else if (direction==IN ){
			//INPUT PORT B
			clr_bit(DDR_B,PIN) ;
			}else{
			
		}break ;
		case PORTC :
		if(direction==OUT){
			//OUTPUT PORT C
			set_bit(DDR_C,PIN) ;
			}else if (direction==IN ){
			//INPUT PORT C
			clr_bit(DDR_C,PIN) ;
			}else{
			
		}break ;
		case PORTD :
		if(direction==OUT){
			//OUTPUT PORT D
			set_bit(DDR_D,PIN) ;
			}else if (direction==IN ){
			//INPUT PORT D
			clr_bit(DDR_D,PIN) ;
			}else{
			
		}break ;
	}
}
void DIO_initport    (u8 PORT   ,  u8 direction                ) {
	switch(PORT){
		case PORTA :DDR_A = direction ;  break ;
		case PORTB :DDR_B = direction ;  break ;
		case PORTC :DDR_C = direction ;  break ;
		case PORTD :DDR_D = direction ;  break ;
	}
}
//function to write on pin
void DIO_writepin    ( u8 PORT  ,  u8 PIN  , u8 value     ){
	switch(PORT){
		case PORTA :
		if(value==HIGH){
			//OUTPUT PORT A
			set_bit(PORT_A,PIN) ;
			}else if (value==LOW ){
			//INPUT PORT A
			clr_bit(PORT_A,PIN) ;
			}else{
			
		}break ;
		case PORTB :
		if(value==HIGH){
			//OUTPUT PORT B
			set_bit(PORT_B,PIN) ;
			}else if (value==LOW ){
			//INPUT PORT B
			clr_bit(PORT_B,PIN) ;
			}else{
			
		}break ;
		case PORTC :
		if(value==HIGH){
			//OUTPUT PORT C
			set_bit(PORT_C,PIN) ;
			}else if (value==LOW ){
			//INPUT PORT C
			clr_bit(PORT_C,PIN) ;
			}else{
			
		}break ;
		case PORTD :
		if(value==HIGH){
			//OUTPUT PORT D
			set_bit(PORT_D,PIN) ;
			}else if (value==LOW ){
			//INPUT PORT D
			clr_bit(PORT_D,PIN) ;
			}else{
			
		}break ;
	}
} 
void DIO_writeport   ( u8 PORT  ,  u8 value                    ){
switch(PORT){
	case PORTA :PORT_A = value ;break ;
	case PORTB :PORT_B = value ;break ;
	case PORTC :PORT_C = value ;break ;
	case PORTD :PORT_D = value ;break ;
}
}

//function to toggle pin
void DIO_togglepin   ( u8 PORT  ,  u8 PIN 					  ) {
	switch(PORT){
		case PORTA :
		//toggle PORT A
		toggle_bit(PORT_A ,PIN) ;break ;
		case PORTB :
		//TOGGLE PORT B
		toggle_bit(PORT_B ,PIN) ;break ;
		case PORTC :
		//TOGGLE PORT C
		toggle_bit(PORT_C ,PIN) ;break ;
		case PORTD :
		//TOGGLE PORT D
		toggle_bit(PORT_D ,PIN) ;break ;
	}
}
//function to read pin
void DIO_readpin     ( u8 PORT  ,  u8 PIN  , u8 * value   ) {
	switch(PORT){
		case PORTA :
		//save the value PORT A
		*value =  get_bit(PIN_A ,PIN) ;  break ;
		case PORTB :
		//save the value PORT B
		*value = get_bit(PIN_B ,PIN)  ;  break ;
		case PORTC :
		//save the value PORT C
		*value = get_bit(PIN_C ,PIN)  ;  break ;
		case PORTD :
		//save the value PORT D
		*value = get_bit(PIN_D ,PIN)  ;  break ;
	}
}

void DIO_readport    ( u8 PORT  ,  u8 *value                   ){
	switch(PORT){
		case PORTA :
		//save the value PORT A
		*value =  PIN_A ;  break ;
		case PORTB :
		//save the value PORT B
		*value = PIN_B ;  break ;
		case PORTC :
		//save the value PORT C
		*value = PIN_C ;  break ;
		case PORTD :
		//save the value PORT D
		*value = PIN_D ;  break ;
	}
}
