/*
 * main.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Bebo
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSPI_interface.h"
#include "TFT_interface.h"
#include "MSYSTICK_interface.h"
#include "image.h"
void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MRCC_voidEnableClock(MRCC_APB2,12);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN5,OUTPUT_SPEED_10MHZ_AFPP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN7,OUTPUT_SPEED_10MHZ_AFPP);
	MSTK_voidInt();
	MSPI_voidMasterInit();
	HTFT_voidInit();
	HTFT_voidFillColor(0xf132);
	HTFT_voidDrawRect(30,80,30,90,0xff00);

	while(1);
}

