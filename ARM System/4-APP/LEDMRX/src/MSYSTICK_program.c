/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 22/8/2023                                            */
/* SWC     : SysTick                                              */
/* Version : V01                                                  */
/******************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"MSYSTICK_interface.h"
#include"MSYSTICK_config.h"
#include"MSYSTICK_private.h"

void (*MSTK_pvCallBack)(void)=NULL;
u8 MSTK_u8AsyncState=SINGLE;
/*************************************************************/
void MSTK_voidInt()
{
    #if MSTK_STATE==MSTK_ENABLE
      SET_BIT((MSTK->CTRL),0);
    #elif MSTK_STATE==MSTK_DISABLE
      CLR_BIT(MSTK->CTRL,0);
    #else
      #error "You Choose Wrong Configuration"
    #endif

    #if MSTK_INT_STATE==MSTK_INT_ENABLE
      SET_BIT((MSTK->CTRL),1);
    #elif MSTK_INT_STATE==MSTK_INT_DISABLE
      CLR_BIT((MSTK->CTRL),1);
    #else
      #error "You Choose Wrong Configuration"
    #endif

    #if MSTK_CLCK_SRC==MSTK_AHB
      SET_BIT((MSTK->CTRL),2);
    #elif MSTK_CLCK_SRC==MSTK_AHB_DIV_BY_8
      CLR_BIT((MSTK->CTRL),2);
    #else
      #error "You Choose Wrong Configuration"
    #endif
}
/********************************************************/
void MSTK_voidBusyWait(u32 Copy_u32Ticks)
{
  MSTK->LOAD=Copy_u32Ticks-1;
  SET_BIT((MSTK->CTRL),0);
  while(GET_BIT(MSTK->CTRL,16)==0);

}
/*******************************************************/
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
  if(Copy_ptr!=NULL)
  {
  MSTK_u8AsyncState=SINGLE;
  MSTK_pvCallBack=Copy_ptr;
  MSTK->LOAD=Copy_u32Ticks;
  MSTK_voidINTSate(MSTK_INT_EN);
  SET_BIT((MSTK->CTRL),0);
  }
  else
  {
    /*Return Error NULL_POINTER*/
  }
}
/*************************************************************/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
  if(Copy_ptr!=NULL)
  {
  MSTK_u8AsyncState=PERIODIC;
  MSTK_pvCallBack=Copy_ptr;
  MSTK->LOAD=Copy_u32Ticks-1;
  MSTK_voidINTSate(MSTK_INT_EN);
  SET_BIT((MSTK->CTRL),0);
  }
  else
  {
    /*Return Error NULL_POINTER*/
  }
}
/*******************************************************/
void MSTK_voidSetLoadValue(u32 Copy_u32LoadValue)
{
  MSTK->LOAD=Copy_u32LoadValue-1;
}
/**********************************************************/
void MSTK_voidINTSate(u8 Copy_u8Sate)
{
  MSTK->CTRL&=~(1<<1);
  MSTK->CTRL|=(Copy_u8Sate<<1);
}
/**********************************************************/
u8 MSTK_u8ClearCountFlag()
{
  return (GET_BIT(MSTK->CTRL,16));
}
/************************************************************/
void MSTK_voidClearValueReg()
{
  MSTK->VAL=0;
}
/**************************************************************/
void SysTick_Handler()
{
  if(MSTK_u8AsyncState==SINGLE)
  {
    MSTK_pvCallBack();


  }
  else if(MSTK_u8AsyncState==PERIODIC)
  {
    MSTK_pvCallBack();

  }
}
