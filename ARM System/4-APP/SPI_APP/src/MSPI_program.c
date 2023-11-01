/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 10/3/2023                                            */
/* SWC     : SPI                                                  */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSPI_interface.h"
#include "MSPI_config.h"
#include "MSPI_private.h"

static void(*MSPI_CallBack)(u16)=NULL;
static u16* MSPI_TransmittAgain=NULL;
void MSPI_voidMasterInit()
{
	MSPI->CR1=0x00000000;
	MSPI->CR1 &= ~( 0b111 << 3 );
	MSPI->CR1 |= ( BAUD_RATE << 3 );
	MSPI->CR1 &= 0b00;
	MSPI->CR1 |=MSPI_MASTER_CLK_POL_PH;
#if MSPI_MASTER_DATA_SIZE==_8_BIT_DATA
	CLR_BIT(MSPI->CR1,11);
#elif MSPI_MASTER_DATA_SIZE==_16_BIT_DATA
	SET_BIT(MSPI->CR1,11);
#else
#warning "WRONG CONFIG HAS BEEN CHOSSEN"
#endif
#if MSPI_MASTER_DATA_ORDER==LSB_FIRST
	SET_BIT(MSPI->CR1,7);
#elif
	CLR_BIT(MSPI->CR1,7);
#else
#warning "WRONG CONFIG HAS BEEN CHOSSEN"
#endif
	SET_BIT(MSPI->CR1,9);
	SET_BIT(MSPI->CR1,8);
	SET_BIT(MSPI->CR1,2);
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
#elif
	CLR_BIT(MSPI->CR1,7);
#else
#warning "WRONG CONFIG HAS BEEN CHOSSEN"
#endif
	SET_BIT(MSPI->CR1,9);
    CLR_BIT(MSPI->CR1,8);
	CLR_BIT(MSPI->CR1,2);
	SET_BIT(MSPI->CR1,6);
}
void MSPI_voidStarSynctTransmittReceive(u16 Copy_u16TransmittedData,u16 * Copy_pu16ReceivedData)
{
	MSPI->DR=Copy_u16TransmittedData;
	while(GET_BIT(MSPI->SR,1)==0);
	while(GET_BIT(MSPI->SR,7)==1);
	while(GET_BIT(MSPI->SR,0)==0);
	*Copy_pu16ReceivedData=MSPI->DR;
}
void MSPI_voidStarAsynctTransmittReceive(u16 Copy_u16TransmittedData,void (*Copy_ptr)(u16))
{
	SET_BIT(MSPI->CR2,7);
	SET_BIT(MSPI->CR2,6);
	MSPI->DR=Copy_u16TransmittedData;
	MSPI_CallBack=Copy_ptr;
}

void MSPI_voidTXBufferEmpty(u16 *Copy_pu16Data)
{
	MSPI_TransmittAgain=Copy_pu16Data;
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


