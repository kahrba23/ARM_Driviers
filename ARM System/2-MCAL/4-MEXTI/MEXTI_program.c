/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 22/8/2023                                            */
/* SWC     : External interrupt                                    */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MEXTI_interface.h"
#include "MEXTI_config.h"
#include "MEXTI_private.h"
void MEXTI_voidInit()
{
    #if MEXTI_MODE==RISING_EDGE
      SET_BIT(MEXTI->RTSR,MEXTI_LINE);
    #elif MEXTI_MODE==FALLING_EDGE
      SET_BIT(MEXTI->FTSR,MEXTI_LINE);
    #elif MEXTI_MODE==ON_CHANGE
      SET_BIT(MEXTI->RTSR,MEXTI_LINE);
      SET_BIT(MEXTI->FTSR,MEXTI_LINE);
    #else 
      #error "Wrong Choice TRigger Mode"
    #endif
    CLR_BIT(MEXTI->IMR,MEXTI_LINE);
}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
    SET_BIT(MEXTI->IMR,Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    CLR_BIT(MEXTI->IMR,Copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
    SET_BIT(MEXTI->SWIER,Copy_u8Line);
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line,u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case RISING_EDGE :  SET_BIT(MEXTI->RTSR,Copy_u8Line); break;
    case FALLING_EDGE : SET_BIT(MEXTI->FTSR,Copy_u8Line);break;
    case ON_CHANGE : 
      SET_BIT(MEXTI->RTSR,Copy_u8Line);
      SET_BIT(MEXTI->FTSR,Copy_u8Line);
      break;   
    default : break;
    }
}