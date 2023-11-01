/*
 * main.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Bebo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MUART_interface.h"
#include "ESP_interface.h"
void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MRCC_voidEnableClock(MRCC_APB2,14);
	MUSART1_voidInit();
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN10,INPUT_FLOATING);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN1,OUTPUT_SPEED_2MHZ_PP);
	ESP_voidInit();
	ESP_voidConnectToWIFI("Bebo","##khrba1234##");
	while(1)
	{
		ESP_voidConnectToServer("23.179.32.37","80");
		u8 Data=ESP_voidRecieveData("40","pciq.freevar.com","status.txt");
		if(Data)
		{
			u8 x=0;
			TOG_BIT(x,0);
			MGPIO_voidSetPinValue(MGPIOA,0,1);
		}
		else
		{
			u8 x=0;
			TOG_BIT(x,1);
			MGPIO_voidSetPinValue(MGPIOA,0,0);
		}
	}
}


