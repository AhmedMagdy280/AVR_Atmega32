/*
 * KEYPAD.c
 *
 * Created: 3/13/2023 10:48:13 PM
 *  Author: ahmed
 */ 

//include part 
#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include <util/delay.h>


//initialize function
void KEYPAD_init(void){
	DIO_initpin    ( KPD_COL_PORT   ,  KPD_COL1_PIN  , OUT   ) ;
	DIO_initpin    ( KPD_COL_PORT   ,  KPD_COL2_PIN  , OUT   ) ;
	DIO_initpin    ( KPD_COL_PORT   ,  KPD_COL3_PIN  , OUT    ) ;
	DIO_initpin    ( KPD_COL_PORT   ,  KPD_COL4_PIN  , OUT    ) ;

	DIO_writepin    (KPD_COL_PORT  ,  KPD_COL1_PIN  , LOW   ) ;
	DIO_writepin    (KPD_COL_PORT  ,  KPD_COL2_PIN  , LOW   ) ;
	DIO_writepin    (KPD_COL_PORT  ,  KPD_COL3_PIN  , LOW  ) ;
	DIO_writepin    (KPD_COL_PORT  ,  KPD_COL4_PIN  , LOW  ) ;


	DIO_initpin    ( KPD_ROW_PORT  ,  KPD_ROW1_PIN  , IN   ) ;
	DIO_initpin    ( KPD_ROW_PORT  ,  KPD_ROW2_PIN  , IN  ) ;
	DIO_initpin    ( KPD_ROW_PORT  ,  KPD_ROW3_PIN  , IN   ) ;
	DIO_initpin    ( KPD_ROW_PORT  ,  KPD_ROW4_PIN  , IN  ) ;
	//TURN PULL UP RESISTANCE 




	DIO_writepin    (  KPD_ROW_PORT  ,  KPD_ROW1_PIN  , HIGH   ) ;
	DIO_writepin    (  KPD_ROW_PORT  ,  KPD_ROW2_PIN  , HIGH   ) ;
	DIO_writepin    (  KPD_ROW_PORT  ,  KPD_ROW3_PIN  , HIGH   ) ;
	DIO_writepin    (  KPD_ROW_PORT  ,  KPD_ROW4_PIN  , HIGH  ) ;

}

const u8 KPD_KEY_VAL[4][4] = {{'7','8','9','/'},
							  {'4','5','6','*'},
							  {'1','2','3','-'},
						   	  {'c','0','=','+'}};
//read function
u8 KEYPAD_GetPressedkey(void)
{
	u8 i=0, j=0;
	u8 readValueRow = 5;
	u8 rowPinx = KPD_ROW1_PIN, colPinx=KPD_COL1_PIN;
	for(;i<ROW_NUMBER;i++)
	{
		DIO_readpin(KPD_ROW_PORT, rowPinx, &readValueRow);
		if(readValueRow==0)
			for(;j<COL_NUMBER;j++)
			{
				DIO_writepin(KPD_COL_PORT, colPinx, HIGH);
				DIO_readpin(KPD_ROW_PORT, rowPinx, &readValueRow);
				if(readValueRow==1)
				{
					DIO_writepin(KPD_COL_PORT, colPinx, LOW);
					return KPD_KEY_VAL[i][j];
				}
				DIO_writepin(KPD_COL_PORT, colPinx, LOW);

				if(colPinx==KPD_COL3_PIN)
				{
				colPinx-=2;
				}
				else
				{
					colPinx--;
				}
			}
		rowPinx--;
	}
	return KPD_NO_PRESSED_KEY;
}
