/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 16/8/2023                                            */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_config.h"
#include "MRCC_private.h"
#include "MRCC_interface.h"
/*******************************************************************************************/
void MRCC_voidInitSysClock(void)
{
#if MRCC_CLOCK_TYPE==MRCC_HSE_CRYSTAL
	MRCC_CR=0x00010000;
	MRCC_CFGR=0x00000001;
#elif MRCC_CLOCK_TYPE==MRCC_HSE_RC
	MRCC_CR=0x00050000;
	MRCC_CFGR=0x00000001;
#elif MRCC_CLOCK_TYPE==MRCC_HSI
	MRCC_CR=0x00000081;
	MRCC_CFGR=0x00000000;
#elif MRCC_CLOCK_TYPE==MRCC_PLL
	MRCC_CFGR=0x00000002;  //select PLL as system clock
	/*MUltiplication factor of PLL */
	MRCC_CFGR&=~((0b1111)<<18);
	MRCC_CFGR|=((MRCC_PLL_MUL_VAL)<<18);
	/*Type of input of PLL circuit */
    #if MRCC_PLL_INPUT==MRCC_PLL_INPUT_HSI_DIV_2
	  CLR_BIT(MRCC_CFGR,16);
    #elif MRCC_PLL_INPUT==MRCC_PLL_INPUT_HSE_DIV_2
	  SET_BIT(MRCC_CR,16);
	  SET_BIT(MRCC_CFGR,16);
	  SET_BIT(MRCC_CFGR,17);
    #elif MRCC_PLL_INPUT==MRCC_PLL_INPUT_HSE
	  SET_BIT(MRCC_CR,16);
	  SET_BIT(MRCC_CFGR,16);
	  CLR_BIT(MRCC_CFGR,17);
    #else
      #warning " You Choose wrong PLL input type "
    #endif
	/*Enable PLL*/
	SET_BIT(MRCC_CR,24);
#else
  #error " You Choose wrong Clock type "
#endif
#if CLOCK_SECURITY_SYSTEM == ENABLE_CLOCK_SECURITY_SYSTEM
    SET_BIT(MRCC_CR,19);
#elif CLOCK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM
	  CLR_BIT(MRCC_CR,19);
#else
	  #warning " Wrong Clock Security System Configuration Choice "
#endif

}
/******************************************************************************************/
void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if(Copy_u8PerId<=31)
	{
		switch(Copy_u8BusId)
		{
		case MRCC_AHB  : SET_BIT(MRCC_AHBENR,Copy_u8PerId);  break;
		case MRCC_APB1 : SET_BIT(MRCC_APB1ENR,Copy_u8PerId); break;
		case MRCC_APB2 : SET_BIT(MRCC_APB2ENR,Copy_u8PerId); break;
		}
	}
	else
	{
		/*Ruturn Error*/
	}
}

/*******************************************************************************/
void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if(Copy_u8PerId<=31)
	{
		switch(Copy_u8BusId)
		{
		case MRCC_AHB  : CLR_BIT(MRCC_AHBENR,Copy_u8PerId);  break;
		case MRCC_APB1 : CLR_BIT(MRCC_APB1ENR,Copy_u8PerId); break;
		case MRCC_APB2 : CLR_BIT(MRCC_APB2ENR,Copy_u8PerId); break;
		}
	}
	else
	{
		/*Ruturn Error*/
	}
}
/****************************************************************************************/
