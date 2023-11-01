/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 4/10/2023                                            */
/* SWC     : UART                                                  */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MUART_interface.h"
#include "MUART_private.h"
#include "MUART_config.h"

static void (*MUSART1_ReceiveCallBack)(u8)= NULL;
static u8 *MUSART1_TransmitCallBack=NULL;
static u8 MUSART1_Source=NO_SOURCE;
static u8 MUSART1_Char=0;
static u32 MUSART1_u32Counter=0;
/******************************************************************/
void MUSART1_voidInit(void)
{
	MUSART1->CR1=0x00000000;
	MUSART1->CR2=0x00000000;
	u32 Mantissa=(MUSART_F_CLk)/(MUSART_BAUD_RATE*16);
	u32 Fraction=((((MUSART_F_CLk)*100)/(MUSART_BAUD_RATE*16))%100)*16;
	if(Fraction>1500){Mantissa++;Fraction=0;}

	MUSART1->CR1|=(MUSART1_STATE<<13);

	MUSART1->CR1|=(MUSART1_WORD_LENGTH<<12);

	MUSART1->CR1|=(MUSART1_PARITY_CONTROL_STATE<<10);

#if MUSART1_PARITY_CONTROL_STATE==PARITY_CONTROL_ENABLED
	MUSART1->CR1|=(MUSART1_PARITY_TYPE<<9);
#endif

	MUSART1->CR1|=(MUSART1_PE_INT_STATE<<8);

	MUSART1->CR1|=(MUSART1_TXE_INT_STATE<<7);

	MUSART1->CR1|=(MUSART1_TC_INT_STATE<<6);

	MUSART1->CR1|=(MUSART1_RXNE_INT_STATE<<5);

	MUSART1->CR1|=(MUSART1_IDLE_INT_STATE<<4);

	MUSART1->CR2&=~(0b11<<12);

	MUSART1->CR2|=(MUSART1_STOP_BITS<<12);

	MUSART1->CR2|=(MUSART1_CLK_SATE<11);

#if MUSART1_CLK_SATE==CLK_ENABLED
	MUSART1->CR2&=~(0b11<<9);
	MUSART1->CR2|=(MUSART1_CLK_POL_PH<<9);
#endif

	MUSART1->BRR=(Mantissa<<4)|(Fraction/100);

	MUSART1->CR1|=(MUSART1_TRANSMITTER_STATE<<3);

	MUSART1->CR1|=(MUSART1_RECEIVER_STATE<<2);

}
/******************************************************************/
void MUSART1_voidSyncTransmitChar(u8 Copy_u8Data)
{
	MUSART1->DR=Copy_u8Data;
	while(GET_BIT(MUSART1->SR,6)==0);
}
/******************************************************************/
void MUSART1_voidSyncTransmitString(u8 *Copy_pu8Data)
{
	u8 i=0;
	while(Copy_pu8Data[i]!='\0')
	{
		MUSART1_voidSyncTransmitChar(Copy_pu8Data[i]);
		i++;
	}
}
/******************************************************************/
void MUSART1_u8SyncReceive(u8 *Copy_pu8Data)
{
	while(GET_BIT(MUSART1->SR,5)==0);
	*Copy_pu8Data=MUSART1->DR;
}
/******************************************************************/
void MUSART1_voidTimeoutRecieve(u8 *Copy_u8Data)
{
	u32 Local_u16Timeout=0;
	while(GET_BIT(MUSART1->SR,5)==0)
	{
		Local_u16Timeout++;
		if(Local_u16Timeout==100000)
		{
			break;
		}
	}

	if(Local_u16Timeout==100000)
	{
		*Copy_u8Data=255;
	}
	else
	{
		*Copy_u8Data=MUSART1->DR;
	}
}
/******************************************************************/
void MUSART1_voidTimeoutRecieveWIFI(u8 *Copy_u8Data)
{
	u32 Local_u16Timeout=0;
	while(GET_BIT(MUSART1->SR,5)==0)
	{
		Local_u16Timeout++;
		if(Local_u16Timeout==1000000)
		{
			break;
		}
	}

	if(Local_u16Timeout==1000000)
	{
		*Copy_u8Data=255;
	}
	else
	{
		*Copy_u8Data=MUSART1->DR;
	}
}
/******************************************************************/
void MUSART1_voidASyncTransmitChar(u8 Copy_u8Data)
{
	MUSART1_Source=TRANSMIT_CHAR;
	MUSART1_Char=Copy_u8Data;
	MUSART1_voidINTState(ENABLE_INT,TC_INT);
}
/******************************************************************/
void MUSART1_voidASyncTransmitString(u8 *Copy_pu8String)
{
	MUSART1_Source=TRANSMIT_STRING;
	MUSART1_TransmitCallBack=Copy_pu8String;
	MUSART1_voidINTState(ENABLE_INT,TC_INT);
}
/******************************************************************/
void MUSART1_u8ASyncReceive(void (*Copy_Ptr)(u8))
{
	MUSART1_voidINTState(ENABLE_INT,RXNE_INT);
	MUSART1_ReceiveCallBack=Copy_Ptr;
}
/******************************************************************/
void MUSART1_voidINTState(u8 Copy_u8State,u8 Copy_u8IntId)
{
	MUSART1->CR1&=~(1<<Copy_u8IntId);
	MUSART1->CR1|=(Copy_u8State<<Copy_u8IntId);
}
/******************************************************************/
void USART1_IRQHandler(void)
{
	if(GET_BIT(MUSART1->SR,RXNE_INT)==1)
	{
		if(MUSART1_ReceiveCallBack!=NULL) MUSART1_ReceiveCallBack(MUSART1->DR);
	}
	if(GET_BIT(MUSART1->SR,TC_INT)==1)
	{
		if(MUSART1_Source==TRANSMIT_STRING)
		{
			if(MUSART1_TransmitCallBack[MUSART1_u32Counter]!='\0')
			{
				CLR_BIT(MUSART1->SR,TC_INT);
				MUSART1->DR=MUSART1_TransmitCallBack[MUSART1_u32Counter];
				MUSART1_u32Counter++;
			}
			else if(MUSART1_TransmitCallBack[MUSART1_u32Counter]=='\0')
			{
				MUSART1_u32Counter=0;
				MUSART1_voidINTState(DISABLE_INT,TC_INT);
				MUSART1_Source=NO_SOURCE;
			}
		}
		else if(MUSART1_Source==TRANSMIT_CHAR)
		{
			MUSART1->DR=MUSART1_Char;
			MUSART1_voidINTState(DISABLE_INT,TC_INT);
			MUSART1_Source=NO_SOURCE;
		}
	}
}

