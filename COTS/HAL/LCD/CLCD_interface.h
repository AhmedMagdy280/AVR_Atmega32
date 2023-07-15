

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define CLCD_u8_LINE_ONE   		0
#define CLCD_u8_LINE_TWO   		1
#define CLCD_u8_LINE_THREE   	2
#define CLCD_u8_LINE_FOUR   	3

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char *Copy_pcharString);

void CLCD_voidSendNumber(u32 Copy_u32Number);

void CLCD_voidSetPosition(u8 Copy_u8Row,u8 Copy_u8Column);

void CLCD_voidSendSpecialCharter(u8 *Copy_u8Pattern,u8 Copy_u8PatternNumber,u8 Copy_XPosition,u8 Copy_yPosition);
//void CLCD_voidSendSpecialCharter(u8 location,u8 *pattern);

#endif
