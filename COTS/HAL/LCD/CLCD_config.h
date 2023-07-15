

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*select the number of data pins connected with LCD
 * 		options: 1-FOUR_BIT
 * 				 2-EIGHT_BIT                     */
#define CLCD_u8_BIT_MODE           FOUR_BIT

#define CLCD_u8_DATA_PORT          	PORTB

#if CLCD_u8_BIT_MODE == FOUR_BIT

#define CLCD_u8_D4_PIN             PIN_0
#define CLCD_u8_D5_PIN             PIN_1
#define CLCD_u8_D6_PIN             PIN_2
#define CLCD_u8_D7_PIN             PIN_4

/*
#define CLCD_u8_D4_PIN             DIO_u8_PIN4
#define CLCD_u8_D5_PIN             DIO_u8_PIN5
#define CLCD_u8_D6_PIN             DIO_u8_PIN6
#define CLCD_u8_D7_PIN             DIO_u8_PIN7
*/

#endif



#define CLCD_u8_CTRL_PORT          PORTA

#define CLCD_u8_RS_PIN             PIN_3
#define CLCD_u8_RW_PIN             PIN_1
#define CLCD_u8_E_PIN              PIN_2

/*
#define CLCD_u8_RS_PIN             DIO_u8_PIN1
#define CLCD_u8_RW_PIN             DIO_u8_PIN2
#define CLCD_u8_E_PIN              DIO_u8_PIN3
*/

#endif
