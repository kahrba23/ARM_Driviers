/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed Abdallah
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "LEDMRX_interface.h"


	u8 Local_u8Arr[8]={0, 120, 36, 36, 120, 0, 0, 0};

void main(void)
 {
	MRCC_voidInitSysClock();
	MSTK_voidInt();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MRCC_voidEnableClock(MRCC_APB2,3);
	HLEDMRX_voidInit();
	while(1)
	{
		for(int i=0;i<30;i++)
		{
			HLEDMRX_voidMove(i);
		}
	}

}
