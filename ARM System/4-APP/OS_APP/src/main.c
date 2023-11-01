/*
 * main.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Ahmed Abdallah
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "OS_interface.h"
volatile u8 flag=0,flagg=0,flaggg=0;
void led1(void);
void led2(void);
void led3(void);
void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MGPIO_voidSetPortDirection(MGPIOA,POSITION_LOW,OUTPUT_SPEED_2MHZ_PP);
	SOS_voidCreateTask(0,1000,led1,0);
	SOS_voidCreateTask(1,2000,led2,1000);
	SOS_voidCreateTask(2,4000,led3,2000);
	SOS_voidStart();
	while(1);
}
void led1(void)
{
	if(!flag)
	{
		MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0,MGPIO_PIN_HIGH);
		flag=1;
	}

	else
	{
		MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0,MGPIO_PIN_LOW);
		flag=0;
	}
}


void led2(void)
{
	if(!flagg)
	{
		MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN1,MGPIO_PIN_HIGH);
		flagg=1;
	}

	else
	{
		MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN1,MGPIO_PIN_LOW);
		flagg=0;
	}

}

void led3(void)
{
	if(!flaggg)
	{
		MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN2,MGPIO_PIN_HIGH);
		flaggg=1;
	}

	else
	{
		MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN2,MGPIO_PIN_LOW);
		flaggg=0;
	}
}
