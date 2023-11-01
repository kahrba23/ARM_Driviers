/*
 * main.c
 *
 *  Created on: Oct 4, 2023
 *      Author: Bebo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MUART_interface.h"
#include "MSYSTICK_interface.h"
#include "MNVIC_interface.h"
#include "OS_interface.h"
void Recieve(u8 DATA);
void Task1 (void);
void Task2 (void);
u8 x;
void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MRCC_voidEnableClock(MRCC_APB2,14);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN10,INPUT_FLOATING);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN0,OUTPUT_SPEED_2MHZ_PP);
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(37);
	MUSART1_voidInit();
   /* SOS_voidCreateTask(0,2000,Task1,0);
    SOS_voidCreateTask(1,2000,Task2,1000);
    SOS_voidStart();*/
	MUSART1_voidASyncTransmitChar('A');
	MUSART1_u8ASyncReceive(Recieve);
	while(1)
	{
		if(x=='5')
		{
			MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0,MGPIO_PIN_HIGH);
		}
		else if(x=='R')
		{
			MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN0,MGPIO_PIN_LOW);
		}

	}
}

void Recieve(u8 DATA)
{
	x=DATA;
}
/*void Task1 (void)
{
	MUSART1_voidASyncTransmitString("AHMED IS HERE HI ");
}
void Task2 (void)
{
	MUSART1_voidASyncTransmitString("WAGIH IS HERE HI ");
}*/
