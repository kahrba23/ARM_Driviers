/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 9/9/2023                                             */
/* SWC     :LED MATRIX                                            */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

u8 Copy_u8Data[30][8]={{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 120},{0, 0, 0, 0, 0, 0, 120, 20},{0, 0, 0, 0, 0, 120, 20, 20},{0, 0, 0, 0, 120, 20, 20, 120},{0, 0, 0, 120, 20, 20, 120, 0},{0, 0, 120, 20, 20, 120, 0, 124},{0, 120, 20, 20, 120, 0, 124, 16},{120, 20, 20, 120, 0, 124, 16, 16},{20, 20, 120, 0, 124, 16, 16, 124},{20, 120, 0, 124, 16, 16, 124, 0},{120, 0, 124, 16, 16, 124, 0, 124},{0, 124, 16, 16, 124, 0, 124, 8},{124, 16, 16, 124, 0, 124, 8, 8},{16, 16, 124, 0, 124, 8, 8, 124},{16, 124, 0, 124, 8, 8, 124, 0},{124, 0, 124, 8, 8, 124, 0, 124},{0, 124, 8, 8, 124, 0, 124, 84},{124, 8, 8, 124, 0, 124, 84, 68},{8, 8, 124, 0, 124, 84, 68, 0},{8, 124, 0, 124, 84, 68, 0, 124},{124, 0, 124, 84, 68, 0, 124, 68},{0, 124, 84, 68, 0, 124, 68, 56},{124, 84, 68, 0, 124, 68, 56, 0},{84, 68, 0, 124, 68, 56, 0, 0},{68, 0, 124, 68, 56, 0, 0, 0},{0, 124, 68, 56, 0, 0, 0, 0},{124, 68, 56, 0, 0, 0, 0, 0},{68, 56, 0, 0, 0, 0, 0, 0},{56, 0, 0, 0, 0, 0, 0, 0}};

void HLEDMRX_voidInit()
{
	MGPIO_voidSetPortDirection(LEDMRX_ROW_PORT,POSITION_HIGH,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPortDirection(LEDMRX_COLUMN_PORT,POSITION_LOW,OUTPUT_SPEED_2MHZ_PP);
}
/****************************************************************************************/
void HLEDMRX_voidDisplay(u8 Row)
{

    u32 timeout=5;
    u32 counter=0;
    while(timeout!=counter)
    {
    counter++;
	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
	MGPIO_voidSetPortValue(LEDMRX_COLUMN_PORT,POSITION_LOW,~(Copy_u8Data[Row][0]));
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT,LEDMRX_ROW7_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(2500);

	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
	MGPIO_voidSetPortValue(LEDMRX_COLUMN_PORT,POSITION_LOW,~(Copy_u8Data[Row][1]));
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT,LEDMRX_ROW6_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(2500);

	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
	MGPIO_voidSetPortValue(LEDMRX_COLUMN_PORT,POSITION_LOW,~(Copy_u8Data[Row][2]));
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT,LEDMRX_ROW5_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(2500);

	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
	MGPIO_voidSetPortValue(LEDMRX_COLUMN_PORT,POSITION_LOW,~(Copy_u8Data[Row][3]));
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT,LEDMRX_ROW4_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(2500);

	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
	MGPIO_voidSetPortValue(LEDMRX_COLUMN_PORT,POSITION_LOW,~(Copy_u8Data[Row][4]));
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT,LEDMRX_ROW3_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(2500);

	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
	MGPIO_voidSetPortValue(LEDMRX_COLUMN_PORT,POSITION_LOW,~(Copy_u8Data[Row][5]));
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT,LEDMRX_ROW2_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(2500);

	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
	MGPIO_voidSetPortValue(LEDMRX_COLUMN_PORT,POSITION_LOW,~(Copy_u8Data[Row][6]));
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT,LEDMRX_ROW1_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(2500);

	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
	MGPIO_voidSetPortValue(LEDMRX_COLUMN_PORT,POSITION_LOW,~(Copy_u8Data[Row][7]));
	MGPIO_voidSetPinValue(LEDMRX_ROW_PORT,LEDMRX_ROW0_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(2500);
    }


}
void HLEDMRX_voidOff()
{
	MGPIO_voidSetPortValue(LEDMRX_ROW_PORT,POSITION_HIGH,MGPIO_HIGH_PORT_LOW);
}
