/*
 * main.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Ahmed Abdallah
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "MEXTI_interface.h"
#include "MAFIO_interface.h"
#include "MSYSTICK_interface.h"

volatile u8 StartFLag=0;
volatile u32 ElapsedTime[50]={0};
volatile u8 Counter=0;
volatile u8 Data=0;
void Getframe (void);
void action(void);
void Play()
{
	switch(Data)
	{
	case 69 :MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN1,MGPIO_PIN_HIGH);break;
	case 70 :MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN1,MGPIO_PIN_LOW);break;
	case 68 :MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN2,MGPIO_PIN_HIGH);break;
	case 64 :MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN2,MGPIO_PIN_LOW);break;
	case 7 :MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN3,MGPIO_PIN_HIGH);break;
	case 21 :MGPIO_voidSetPinValue(MGPIOA,MGPIO_PIN3,MGPIO_PIN_LOW);break;
	}
}
void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,2);

	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN0,INPUT_FLOATING);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(MGPIOA,MGPIO_PIN3,OUTPUT_SPEED_2MHZ_PP);

	MEXTI_voidSetCallBack0(Getframe);
	MEXTI_voidEnableEXTI(LINE0);
	MEXTI_voidSetSignalLatch(LINE0,FALLING_EDGE);

	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6);

	MAFIO_voidSetEXTIConfiguration(EXTI0,PORTA);

	MSTK_voidInt();

	while(1);

}

void Getframe(void)
{
	if(!StartFLag)
	{
		MSTK_voidSetIntervalSingle2(1000000,action);
		StartFLag=1;
	}
	else
	{
		ElapsedTime[Counter]=MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle2(1000000,action);
		Counter++;
	}

}
void action(void)
{
	Data=0;
	u8 i;
	if(ElapsedTime[0]>=10000&&ElapsedTime[0]<=14000)
	{

		for(i=0;i<8;i++)
		{
			if(ElapsedTime[17+i]>=2000&&ElapsedTime[17+i]<=2300)
			{
				SET_BIT(Data,i);
			}
			else CLR_BIT(Data,i);
		}
	}
	else
	{
		/*invalid frmae */
	}
	StartFLag=0;
	Counter=0;
	ElapsedTime[0]=0;
	Play();
}
