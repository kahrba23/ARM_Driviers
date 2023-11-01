/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Bebo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
void func1(void);
void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MSTK_voidInt();
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN1,OUTPUT_SPEED_2MHZ_PP);
		MSTK_voidSetIntervalSingle(1500000,func1);
	while(1)
	{
		MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0,MGPIO_PIN_HIGH);
	}


}
void func1()
{
	MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0,MGPIO_PIN_LOW);
	for(int i=0;i<=250000;i++)
	{
		asm("NOP");
	}

}

