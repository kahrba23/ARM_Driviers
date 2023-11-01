/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Bebo
 */
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "MSYSTICK_interface.h"
#include "MAFIO_interface.h"
#include "MEXTI_interface.h"
void EXTI0_ISR(void);
void EXTI1_ISR(void);
void main()
{
	MEXTI_voidSetCallBack0(EXTI0_ISR);
	MEXTI_voidSetCallBack1(EXTI1_ISR);

	MRCC_voidInitSysClock();

	MRCC_voidEnableClock(MRCC_APB2,0);
	MRCC_voidEnableClock(MRCC_APB2,2);
	MRCC_voidEnableClock(MRCC_APB2,3);

	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN0,INPUT_PUPD);
	MGPIO_voidSetPinDirection(MGPIOB,MGPIO_PIN1,INPUT_PUPD);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN2,OUTPUT_SPEED_2MHZ_PP);

	MNVIC_voidSetPriority(6,0,0,GROUP5);
	MNVIC_voidSetPriority(7,1,0,GROUP5);

	MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0,MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MGPIOB,MGPIO_PIN1,MGPIO_PIN_HIGH);

	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);

	MAFIO_voidSetEXTIConfiguration(EXTI0,PORTA);
	MAFIO_voidSetEXTIConfiguration(EXTI1,PORTB);

	MEXTI_voidEnableEXTI(LINE0);
	MEXTI_voidEnableEXTI(LINE1);

	MEXTI_voidSetSignalLatch(LINE0,FALLING_EDGE);
	MEXTI_voidSetSignalLatch(LINE1,FALLING_EDGE);
	while(1)
	{
		MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN2,MGPIO_PIN_LOW);
	}

}
void EXTI0_ISR(void)
{
	MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN2,MGPIO_PIN_HIGH);
	for(int i=0;i<500000;i++)
		{
			asm("NOP");
		}
}
void EXTI1_ISR(void)
{
	MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN2,MGPIO_PIN_LOW);
	for(int i=0;i<500000;i++)
	{
		asm("NOP");
	}
}
