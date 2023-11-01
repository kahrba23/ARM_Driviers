/*
 * main.c
 *
 *  Created on: Sep 25, 2023
 *      Author: Ahmed Abdallah
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "file.h"
void voidSetDAC(void);
void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);
	MGPIO_voidSetPortDirection(MGPIOA,POSITION_LOW,OUTPUT_SPEED_2MHZ_PP);
	MSTK_voidInt();
	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);
	while(1);


}


void voidSetDAC(void)
{
	static u16 Counter=0;
	MGPIO_voidSetPortValue(MGPIOA,POSITION_LOW,Amaren_raw[Counter]);
	Counter++;
	if(Counter==Amaren3_raw_len) Counter=0;


}
