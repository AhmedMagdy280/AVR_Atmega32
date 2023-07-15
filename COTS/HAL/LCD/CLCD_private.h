

#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

#define LINE_TWO_OFFSET    0x40

#define EIGHT_BIT           1
#define FOUR_BIT            2

static void SendEnablePulse(void);
static void SetHalfDataPort(u8 Copy_u8Data);

#endif
