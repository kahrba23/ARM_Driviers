/*
 * main.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Ahmed Abdallah
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "STP_interface.h"
void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN2,OUTPUT_SPEED_2MHZ_PP);
	MSTK_voidInt();
	HSTP_voidSendSynchrouns(0x0A);
	while(1)
	{

	}

}



