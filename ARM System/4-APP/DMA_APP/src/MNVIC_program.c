/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 21/8/2023                                            */
/* SWC     : NVIC                                                 */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MNVIC_interface.h"
#include "MNVIC_private.h"
#include "MNVIC_config.h"


void MNVIC_voidInit()
{
SCB_AIRCR=MNVIC_GROUP_SUB_DISTRIBUTION;
}
/********************************************************************/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber<=31)
    {
       MNVIC_ISER0=(1 << Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber<=59)
    {
        Copy_u8IntNumber-=32;
         MNVIC_ISER1=(1 << Copy_u8IntNumber);
    }
    else
    {
        /*Return Error*/
    }
}
/*****************************************************************/
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber<=31)
    {
        MNVIC_ICER0=(1 << Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber<=59)
    {
        Copy_u8IntNumber-=32;
        MNVIC_ICER1=(1 << Copy_u8IntNumber);
    }
    else
    {
        /*Return Error*/
    }
}
/******************************************************************/
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber<=31)
    {
        MNVIC_ISPR0=(1 << Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber<=59)
    {
        Copy_u8IntNumber-=32;
        MNVIC_ISPR1=(1 << Copy_u8IntNumber);
    }
    else
    {
        /*Return Error*/
    }
}
/******************************************************************/
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber<=31)
    {
        MNVIC_ICPR0=(1 << Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber<=59)
    {
        Copy_u8IntNumber-=32;
        MNVIC_ICPR1=(1 << Copy_u8IntNumber);
    }
    else
    {
        /*Return Error*/
    }
}
/************************************************************************/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
    u8 Local_u8Result=0;
    if(Copy_u8IntNumber<=31)
    {
        Local_u8Result=GET_BIT(MNVIC_IABR0,Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber<=59)
    {
        Copy_u8IntNumber-=32;
         Local_u8Result=GET_BIT(MNVIC_IABR1,Copy_u8IntNumber);
    }
    else
    {
        /*Return Error*/
    }
    return Local_u8Result;
}
/**********************************************************************/
void MNVIC_voidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32Group )
{
    u8 Local_u8Priority=Copy_u8SubPriority | (Copy_u8GroupPriority << ((Copy_u32Group-0x05FA0300)/256));
    if(Copy_u8INTID>=0)
    {
        MNVIC_IPR[Copy_u8INTID] = Local_u8Priority << 4;
    }
    SCB_AIRCR=Copy_u32Group;
}
