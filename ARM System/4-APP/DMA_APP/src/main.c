/*
 * main.c
 *
 *  Created on: Oct 3, 2023
 *      Author: AHMED ABDALLAH
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MNVIC_interface.h"
#include "MDMA_interface.h"

	u32 ARR0[1000],ARR1[1000],ARR2[1000],ARR3[1000];
void main(void)
{
	for(int i=0;i<1000;i++)
	{
		ARR1[i]=5;
		ARR2[i]=10;
	}
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_AHB,0);
	MNVIC_voidEnableInterrupt(11);
	MDMA_voidInit();
	MDMA_voidChannelStart(CHANNEL1_ID,ARR0,ARR1,1000);
	for(u16 i=0;i<1000;i++)
	{
		ARR3[i]=ARR2[i];
	}

}

void DMA1_Channel1_IRQHandler(void)
{
	MDMA_voidClrFlag();
}
