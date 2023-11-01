/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 19/8/2023                                            */
/* Version : V01                                                  */
/******************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MGPIO_interface.h"
#include"MGPIO_config.h"
#include"MGPIO_private.h"


void MGPIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
	case MGPIOA :
		if(Copy_u8Pin<=7)
		{
			MGPIOA_CRL&=~((0b1111)<<(Copy_u8Pin*4));
			MGPIOA_CRL|=((Copy_u8Mode)<<(Copy_u8Pin*4));
		}
		else if(Copy_u8Pin>=8&&Copy_u8Pin<=15)
		{
			Copy_u8Pin-=8;
			MGPIOA_CRH&=~((0b1111)<<(Copy_u8Pin*4));
			MGPIOA_CRH|=((Copy_u8Mode)<<(Copy_u8Pin*4));
		}
		break;


	case MGPIOB :
		if(Copy_u8Pin<=7)
		{
			MGPIOB_CRL&=~((0b1111)<<(Copy_u8Pin*4));
			MGPIOB_CRL|=((Copy_u8Mode)<<(Copy_u8Pin*4));
		}
		else if(Copy_u8Pin>=8&&Copy_u8Pin<=15)
		{
			Copy_u8Pin-=8;
			MGPIOB_CRH&=~((0b1111)<<(Copy_u8Pin*4));
			MGPIOB_CRH|=((Copy_u8Mode)<<(Copy_u8Pin*4));
		}
		break;


	case MGPIOC :
		if(Copy_u8Pin<=7)
		{
			MGPIOC_CRL&=~((0b1111)<<(Copy_u8Pin*4));
			MGPIOC_CRL|=((Copy_u8Mode)<<(Copy_u8Pin*4));
		}
		else if(Copy_u8Pin>=8&&Copy_u8Pin<=15)
		{
			Copy_u8Pin-=8;
			MGPIOC_CRH&=~((0b1111)<<(Copy_u8Pin*4));
			MGPIOC_CRH|=((Copy_u8Mode)<<(Copy_u8Pin*4));
		}
		break;
	default:
		break;
	}

}
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	switch (Copy_u8Port)
	{
	case MGPIOA :
		if(Copy_u8Value==MGPIO_PIN_HIGH)
		{
			SET_BIT(MGPIOA_ODR,Copy_u8Pin);
		}
		else if(Copy_u8Value==MGPIO_PIN_LOW)
		{
			CLR_BIT(MGPIOA_ODR,Copy_u8Pin);
		}
		break;
	case MGPIOB :
		if(Copy_u8Value==MGPIO_PIN_HIGH)
		{
			SET_BIT(MGPIOB_ODR,Copy_u8Pin);
		}
		else if(Copy_u8Value==MGPIO_PIN_LOW)
		{
			CLR_BIT(MGPIOB_ODR,Copy_u8Pin);
		}
		break;
	case MGPIOC :
		if(Copy_u8Value==MGPIO_PIN_HIGH)
		{
			SET_BIT(MGPIOC_ODR,Copy_u8Pin);
		}
		else if(Copy_u8Value==MGPIO_PIN_LOW)
		{
			CLR_BIT(MGPIOC_ODR,Copy_u8Pin);
		}
		break;
	default : break;
	}
}
u8 MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Result=0;
	switch (Copy_u8Port)
	{
	case MGPIOA :
		Local_u8Result=GET_BIT(MGPIOA_IDR,Copy_u8Pin);
		break;
	case MGPIOB :
		Local_u8Result=GET_BIT(MGPIOB_IDR,Copy_u8Pin);
		break;
	case MGPIOC :
		Local_u8Result=GET_BIT(MGPIOC_IDR,Copy_u8Pin);
		break;
	default : break;
	}
	return Local_u8Result;
}
void MGPIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Position,u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
	case MGPIOA :
		if(Copy_u8Position==POSITION_LOW) {MGPIOA_CRL=((0x11111111)*Copy_u8Mode);}
		else if(Copy_u8Position==POSITION_HIGH) {MGPIOA_CRH=((0x11111111)*Copy_u8Mode);}
		break;
	case MGPIOB :
		if(Copy_u8Position==POSITION_LOW) {MGPIOB_CRL=((0x11111111)*Copy_u8Mode);}
		else if(Copy_u8Position==POSITION_HIGH) {MGPIOB_CRH=((0x11111111)*Copy_u8Mode);}
		break;
	case MGPIOC :
		if(Copy_u8Position==POSITION_LOW) {MGPIOC_CRL=((0x11111111)*Copy_u8Mode);}
		else if(Copy_u8Position==POSITION_HIGH) {MGPIOC_CRH=((0x11111111)*Copy_u8Mode);}
		break;
	default : break;
	}
}
void MGPIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Position,u16 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case MGPIOA :
		if(Copy_u8Position==POSITION_LOW) {MGPIOA_ODR=((MGPIOA_ODR & 0xFF00)|((u8)Copy_u8Value));}
		else if(Copy_u8Position==POSITION_HIGH) {MGPIOA_ODR=((MGPIOA_ODR & 0x00FF)|(Copy_u8Value));}
		break;
	case MGPIOB :
		if(Copy_u8Position==POSITION_LOW) {MGPIOB_ODR=((MGPIOB_ODR & 0xFF00)|((u8)Copy_u8Value));}
		else if(Copy_u8Position==POSITION_HIGH) {MGPIOB_ODR=((MGPIOB_ODR & 0x00FF)|(Copy_u8Value));}
		break;
	case MGPIOC :
		if(Copy_u8Position==POSITION_LOW) {MGPIOC_ODR=((MGPIOC_ODR & 0xFF00)|((u8)Copy_u8Value));}
		else if(Copy_u8Position==POSITION_HIGH) {MGPIOC_ODR=((MGPIOC_ODR & 0x00FF)|(Copy_u8Value));}
		break;
	default : break;
	}
}

