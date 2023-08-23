/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 16/8/2023                                            */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H

#define MRCC_AHB     0
#define MRCC_APB1    1
#define MRCC_APB2    2
void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);

#endif
