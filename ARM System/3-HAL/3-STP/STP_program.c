/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 10/3/2023                                            */
/* SWC     : Serial To Parallel                                  */
/* Version : V01                                                  */
/******************************************************************/
#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "STP_interface.h"
#include "STP_config.h"
#include "STP_private.h"

void HSTP_voidSendSynchrouns(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for(Local_s8Counter=7;Local_s8Counter>=0;Local_s8Counter--)
	{
		Local_u8Bit=GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,MGPIO_PIN_HIGH);
		MSTK_voidBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,MGPIO_PIN_LOW);
		MSTK_voidBusyWait(1);
	}
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(1);
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,MGPIO_PIN_LOW);
	MSTK_voidBusyWait(1);
}
