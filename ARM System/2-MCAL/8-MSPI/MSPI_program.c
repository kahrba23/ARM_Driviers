/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 10/3/2023                                            */
/* SWC     : SPI                                                  */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSPI_interface.h"
#include "MSPI_private.h"
#include "MSPI_config.h"

static void(*MSPI_CallBack)(u8)=NULL;
static u8* MSPI_TransmittAgain=NULL;
void MSPI_voidMasterInit()
{
	MSPI->CR1&=~(0b111<<3);
	MSPI->CR1|=(BAUD_RATE<<3);
	MSPI->CR1&=~(0b11);
	MSPI->CR1|=MSPI_MASTER_CLK_POL_PH;
#if MSPI_MASTER_DATA_SIZE==_8_BIT_DATA
	CLR_BIT(MSPI->CR1,11);
#elif MSPI_MASTER_DATA_SIZE==_16_BIT_DATA
	SET_BIT(MSPI->CR1,11);
#else
#warning "WRONG CONFIG HAS BEEN CHOSSEN"
#endif
#if MSPI_MASTER_DATA_ORDER==LSB_FIRST
	SET_BIT(MSPI->CR1,7);
#elif MSPI_MASTER_DATA_ORDER==MSB_FIRST
	CLR_BIT(MSPI->CR1,7);
#else
#warning "WRONG CONFIG HAS BEEN CHOSSEN"
#endif
	SET_BIT(MSPI->CR1,2);
	SET_BIT(MSPI->CR1,9);
	SET_BIT(MSPI->CR1,8);
	SET_BIT(MSPI->CR1,6);
}

void MSPI_voidSlaveInit()
{
	MSPI->CR1=0x00000000;
	MSPI->CR1 &= 0b00;
	MSPI->CR1 |=MSPI_SLAVE_CLK_POL_PH;
#if MSPI_SLAVE_DATA_SIZE==_8_BIT_DATA
	CLR_BIT(MSPI->CR1,11);
#elif MSPI_SLAVE_DATA_SIZE==_16_BIT_DATA
	SET_BIT(MSPI->CR1,11);
#else
#warning "WRONG CONFIG HAS BEEN CHOSSEN"
#endif
#if MSPI_SLAVE_DATA_ORDER==LSB_FIRST
	SET_BIT(MSPI->CR1,7);
#elif MSPI_MASTER_DATA_ORDER==MSB_FIRST
	CLR_BIT(MSPI->CR1,7);
#else
#warning "WRONG CONFIG HAS BEEN CHOSSEN"
#endif
	SET_BIT(MSPI->CR1,9);
    CLR_BIT(MSPI->CR1,8);
	CLR_BIT(MSPI->CR1,2);
	SET_BIT(MSPI->CR1,6);
}
void MSPI_voidStarSynctTransmittReceive(u8 Copy_u8TransmittedData,u8 * Copy_pu8ReceivedData)
{
	MSPI->DR=Copy_u8TransmittedData;
	while(GET_BIT(MSPI->SR,1)==0);
	while(GET_BIT(MSPI->SR,7)==1);
	while(GET_BIT(MSPI->SR,0)==0);
	*Copy_pu8ReceivedData=MSPI->DR;
}
void MSPI_voidStarAsynctTransmittReceive(u8 Copy_u8TransmittedData,void (*Copy_ptr)(u8))
{
	SET_BIT(MSPI->CR2,7);
	SET_BIT(MSPI->CR2,6);
	MSPI->DR=Copy_u8TransmittedData;
	MSPI_CallBack=Copy_ptr;
}

void MSPI_voidTXBufferEmpty(u8 *Copy_pu8Data)
{
	MSPI_TransmittAgain=Copy_pu8Data;
}
void MSPI_voidDisable(void)
{
	while(GET_BIT(MSPI->SR,1)==0);
	while(GET_BIT(MSPI->SR,7)==1);
	CLR_BIT(MSPI->CR1,6);

}

void SPI1_IRQHandler(void)
{
	if(GET_BIT(MSPI->SR,0)==1)
	{
	    if(MSPI_CallBack!=NULL)
	    {
		 MSPI_CallBack(MSPI->DR);
	    }
	}
	else if(GET_BIT(MSPI->SR,1)==1)
	{
		if(MSPI_TransmittAgain!=NULL)
		{
			MSPI->DR=*MSPI_TransmittAgain;
		}
	}

}


