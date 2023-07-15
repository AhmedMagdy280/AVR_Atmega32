/*
 * CLCD_Program.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Omar
 */
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include <util/delay.h>

static void SendEnablePulse(void)
{
	DIO_writepin(CLCD_u8_CTRL_PORT, CLCD_u8_E_PIN, HIGH);
	_delay_ms(2);
	DIO_writepin(CLCD_u8_CTRL_PORT, CLCD_u8_E_PIN, LOW);
	_delay_ms(2);

}
static void SetHalfDataPort(u8 Copy_u8Data)
{
	DIO_writepin(CLCD_u8_DATA_PORT, CLCD_u8_D4_PIN, get_bit(Copy_u8Data,4));
	DIO_writepin(CLCD_u8_DATA_PORT, CLCD_u8_D5_PIN, get_bit(Copy_u8Data,5));
	DIO_writepin(CLCD_u8_DATA_PORT, CLCD_u8_D6_PIN, get_bit(Copy_u8Data,6));
	DIO_writepin(CLCD_u8_DATA_PORT, CLCD_u8_D7_PIN, get_bit(Copy_u8Data,7));
	SendEnablePulse();
	DIO_writepin(CLCD_u8_DATA_PORT, CLCD_u8_D4_PIN, get_bit(Copy_u8Data,0));
	DIO_writepin(CLCD_u8_DATA_PORT, CLCD_u8_D5_PIN, get_bit(Copy_u8Data,1));
	DIO_writepin(CLCD_u8_DATA_PORT, CLCD_u8_D6_PIN, get_bit(Copy_u8Data,2));
	DIO_writepin(CLCD_u8_DATA_PORT, CLCD_u8_D7_PIN, get_bit(Copy_u8Data,3));
	SendEnablePulse();
}

void CLCD_voidInit(void)
{
	_delay_ms(30);
	#if CLCD_u8_BIT_MODE == FOUR_BIT

	CLCD_voidSendCommand(0x02);
	_delay_ms(15);
	CLCD_voidSendCommand(0x28);
	_delay_ms(1);
	CLCD_voidSendCommand(0x0C);
	_delay_ms(1);
	CLCD_voidSendCommand(0x01);
	_delay_ms(15);
	CLCD_voidSendCommand(0x06);
	_delay_ms(2);


	#endif

	#if CLCD_u8_BIT_MODE == EIGHT_BIT

	  CLCD_voidSendCommand(0x38);
	  _delay_ms(1);
	  //1011
	  CLCD_voidSendCommand(0x0C);
	  _delay_ms(1);
	  CLCD_voidSendCommand(0x01);
	  _delay_ms(2);
	  //0 	0110
	//  CLCD_voidSendCommand(0x04);
	#endif

}
void CLCD_voidSendData(u8 Copy_u8Data)
{
	DIO_initpin(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, OUT);
	//DIO_initpin(CLCD_u8_CTRL_PORT, CLCD_u8_RW_PIN, OUT);
	DIO_initpin(CLCD_u8_CTRL_PORT, CLCD_u8_E_PIN, OUT);

	#if CLCD_u8_BIT_MODE == FOUR_BIT
	DIO_writepin(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, HIGH);
	DIO_initpin(CLCD_u8_DATA_PORT, CLCD_u8_D4_PIN, OUT);
	DIO_initpin(CLCD_u8_DATA_PORT, CLCD_u8_D5_PIN, OUT);
	DIO_initpin(CLCD_u8_DATA_PORT, CLCD_u8_D6_PIN, OUT);
	DIO_initpin(CLCD_u8_DATA_PORT, CLCD_u8_D7_PIN, OUT);
	SetHalfDataPort(Copy_u8Data);
	//_delay_ms(15);
	#endif

	#if CLCD_u8_BIT_MODE == EIGHT_BIT
	DIO_u8SetPortDirection(CLCD_u8_DATA_PORT, OUT);
	DIO_writepin(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, DIO_u8_PIN_HIGH);
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Data);
	SendEnablePulse();
	#endif


}
void CLCD_voidSendString(const char *Copy_pcharString)
{


		while (*(Copy_pcharString)!='\0')
		{
			CLCD_voidSendData(*(Copy_pcharString));
			Copy_pcharString++;
		}

}
void CLCD_voidSendNumber(u32 Copy_u32Number)
{
	if(Copy_u32Number==0)
		CLCD_voidSendData('0');
	u32 Local_u8Reversed=1;
	while(Copy_u32Number!=0)
	{
		Local_u8Reversed=(Local_u8Reversed*10)+(Copy_u32Number%10);
		Copy_u32Number=Copy_u32Number/10;
	}
	while(Local_u8Reversed!=1)
	{
		CLCD_voidSendData((Local_u8Reversed%10)+48);
		Local_u8Reversed/=10;
	}
}
void CLCD_voidSendCommand(u8 Copy_u8Command)
{

	DIO_initpin(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, OUT);
	DIO_initpin(CLCD_u8_CTRL_PORT, CLCD_u8_RW_PIN, OUT);
	DIO_initpin(CLCD_u8_CTRL_PORT, CLCD_u8_E_PIN, OUT);

	#if CLCD_u8_BIT_MODE == FOUR_BIT
	DIO_initpin(CLCD_u8_DATA_PORT, CLCD_u8_D4_PIN, OUT);
	DIO_initpin(CLCD_u8_DATA_PORT, CLCD_u8_D5_PIN, OUT);
	DIO_initpin(CLCD_u8_DATA_PORT, CLCD_u8_D6_PIN, OUT);
	DIO_initpin(CLCD_u8_DATA_PORT, CLCD_u8_D7_PIN, OUT);
	DIO_writepin(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, LOW);
	SetHalfDataPort(Copy_u8Command);
	_delay_ms(5);

	#endif

	#if CLCD_u8_BIT_MODE == EIGHT_BIT
	DIO_u8SetPortDirection(CLCD_u8_DATA_PORT, OUT);
	DIO_writepin(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, DIO_u8_PIN_LOW);
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Command);
	SendEnablePulse();
	#endif

}

void CLCD_voidSetPosition(u8 Copy_u8Row,u8 Copy_u8Column)
{
	u8 command; //enable DDRAM
	if(Copy_u8Row==1) //first line
	{
		command=0x80+Copy_u8Column;
	}
	else if (Copy_u8Row==2)
	{
		command=(0xc0+Copy_u8Column);
	}
	else if (Copy_u8Row==3)
	{
		command=(0x94+Copy_u8Column);
	}
	else if (Copy_u8Row==4)
	{
		command=(0xD4+Copy_u8Column);
	}
	CLCD_voidSendCommand(command);
}

/*void CLCD_voidSendSpecialCharter(u8 location,u8 *pattern)
{
	CLCD_voidSendCommand(0x40+(location*8));//40 enable cgram and choose the address you want save in the pattern
	for(u8 i=0;i<8;i++)
	{
		CLCD_voidSendData(pattern[i]);
	}
	CLCD_voidSetPosition(0,0); // to return the address from CGRAM address to DDRAM
}*/
void CLCD_voidSendSpecialCharter(u8 *Copy_u8Pattern,u8 Copy_u8PatternNumber,u8 Copy_XPosition,u8 Copy_yPosition)
{
	u8 Local_u8Counter,Local_u8CGRAMAdd;

	/*1- Calculate the CGRAM knowing that each pattern uses 8 Bytes*/
	Local_u8CGRAMAdd=Copy_u8PatternNumber *8;

	/*2- Set bit 6 and clear bit 7 in the address for the set CGRAM address command*/
	set_bit(Local_u8CGRAMAdd,6);
	clr_bit(Local_u8CGRAMAdd,7);

	/*3- Invoke the set CGRAM address command*/
	CLCD_voidSendCommand(Local_u8CGRAMAdd);

	/*4- write the required pattern in the CGRAM*/
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_u8Pattern[Local_u8Counter]);
	}

	/*5- set the required DDRAM address before displaying the data*/
	CLCD_voidSetPosition(Copy_XPosition,Copy_yPosition);

	/*6- Display the data written in the pattern number in the CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}

