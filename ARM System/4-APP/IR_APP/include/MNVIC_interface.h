/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 21/8/2023                                            */
/* SWC     : NVIC                                                 */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MNVIC_INTERFACE_H
#define MNVIC_INTERFACE_H

#define GROUP3   0x05FA0300  //4bits for group
#define GROUP4   0x05FA0400  //3bits for group 1bits for sub
#define GROUP5   0x05FA0500  //2bits for group 2bits for sub
#define GROUP6   0x05FA0600  //1bits for group 3bits for sub
#define GROUP7   0x05FA0700  //0bits for group 4bits for sub

void MNVIC_voidInit();
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32Group );

#endif
