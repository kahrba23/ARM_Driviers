/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 19/9/2023                                            */
/* SWC     : IR                                                   */
/* Layer   : HAL                                                  */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "MEXTI_interface.h"
#include "MAFIO_interface.h"
#include "MSYSTICK_interface.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"

static volatile  u8 IR_u8Flag=0;
static volatile  u32 IR_u32Frame[50]={0};
static volatile  u8 IR_u8Counter=0;
static volatile  u16 IR_Data=0;
void (*IR_pfCallBack)(void)=NULL;
void IR_voidInt()
{
	MRCC_voidEnableClock(MRCC_APB2,2);
    MEXTI_voidSetCallBack0(IR_voidGetFrame);
	MGPIO_voidSetPinDirection(IR_PORT,IR_PIN,INPUT_FLOATING);
	MNVIC_voidEnableInterrupt(6);

	MEXTI_voidEnableEXTI(IR_LINE);
	MEXTI_voidSetSignalLatch(IR_LINE,FALLING_EDGE);
	MAFIO_voidSetEXTIConfiguration(IR_EXTI,IR_PORT_MAP);
}


static void IR_voidGetFrame(void)
{
	if(!IR_u8Flag)
	{
		MSTK_voidSetIntervalSingle2(500000,&IR_voidGetData);
		IR_u8Flag=1;
	}
	else
	{
		IR_u32Frame[IR_u8Counter]=MSTK_u32GetElapsedTime();
		IR_u8Counter++;
		MSTK_voidSetIntervalSingle2(500000,&IR_voidGetData);
	}
}

static void IR_voidGetData(void)
{

	if(IR_u32Frame[0]>=10000&&IR_u32Frame[0]<=14000)
	{
		for(int i=0;i<8;i++)
		{
			if(IR_u32Frame[17+i]>=2000&&IR_u32Frame[17+i]<=2300)
			{
				SET_BIT(IR_Data,i);
			}
			else CLR_BIT(IR_Data,i);
		}
	}
	else
	{
		/*Wrong Frame*/
	}
	IR_u8Flag=0;
	IR_u32Frame[0]=0;
	IR_u8Counter=0;
	IR_pfCallBack();

}
void IR_voidCallBack(void(*Copy_pfCallBack)(void))
{
	IR_pfCallBack=Copy_pfCallBack;
}
u16 IR_u16Data(void)
{
	return IR_Data;
}
