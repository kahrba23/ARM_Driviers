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

static void (* MEXTI_CallBack[5])(void)={NULL};
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
    SET_BIT(MEXTI->IMR,MEXTI_LINE);
}
/******************************************************************/
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
    SET_BIT(MEXTI->IMR,Copy_u8Line);
}
/*********************************************************************/
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    CLR_BIT(MEXTI->IMR,Copy_u8Line);
}
/*********************************************************************/
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
    SET_BIT(MEXTI->SWIER,Copy_u8Line);
}
/*********************************************************************/
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
/*********************************************************************/
void MEXTI_voidClrPendingBit(u8 Copy_u8Line)
{
  SET_BIT(MEXTI->PR,Copy_u8Line);
}
/******************************************************************************************/
/*************************CALL_BACK_FUNCTIONS**********************************************/
void MEXTI_voidSetCallBack0(void (*Copy_ptr)(void))
{
  MEXTI_CallBack[0]=Copy_ptr;
}
/*********************************************************************/
void MEXTI_voidSetCallBack1(void (*Copy_ptr)(void))
{
  MEXTI_CallBack[1]=Copy_ptr;
}
/*********************************************************************/
void MEXTI_voidSetCallBack2(void (*Copy_ptr)(void))
{
  MEXTI_CallBack[2]=Copy_ptr;
}
/*********************************************************************/
void MEXTI_voidSetCallBack3(void (*Copy_ptr)(void))
{
  MEXTI_CallBack[3]=Copy_ptr;
}
/*********************************************************************/
void MEXTI_voidSetCallBack4(void (*Copy_ptr)(void))
{
  MEXTI_CallBack[4]=Copy_ptr;
}
/*********************************************************************/
void EXTI0_IRQHandler(void)
{
  MEXTI_CallBack[0]();
  MEXTI_voidClrPendingBit(LINE0);
}
/*********************************************************************/
void EXTI1_IRQHandler(void)
{
  MEXTI_CallBack[1]();
  MEXTI_voidClrPendingBit(LINE1);
}
/*********************************************************************/
void EXTI2_IRQHandler(void)
{
  MEXTI_CallBack[2]();
}
/*********************************************************************/
void EXTI3_IRQHandler(void)
{
  MEXTI_CallBack[3]();
}
/*********************************************************************/
void EXTI4_IRQHandler(void)
{
  MEXTI_CallBack[4]();
}
/*********************************************************************/
