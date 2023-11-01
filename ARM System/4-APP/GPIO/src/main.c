/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ahmed Abdallah
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"

void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MRCC_voidEnableClock(MRCC_APB2,3);
	MRCC_voidEnableClock(MRCC_APB2,4);
     MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN0,INPUT_PUPD);
     MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN1,OUTPUT_SPEED_10MHZ_PP);
     MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0,MGPIO_PIN_HIGH);

	while(1)
	{
		if(MGPIO_voidGetPinValue(MGPIOA,MGPIO_PIN0)==0)
		{
			MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN1,MGPIO_PIN_HIGH);

		}
		else
		{
			MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN1,MGPIO_PIN_LOW);
		}

	}
}


