/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 22/8/2023                                            */
/* SWC     : SysTick                                              */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MSYSTICK_INTERFACE_H
#define MSYSTICK_INTERFACE_H

void MSTK_voidInt();
void MSTK_voidBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,void (*Copy_ptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr)(void));
void MSTK_voidStopInterval();
u32  MSTK_u32GetElapsedTime();
u32  MSTK_u32GetRemaningTime();
void MSTK_voidSetLoadValue(u32 Copy_u32LoadValue);
void MSTK_voidINTSate(u8 Copy_u8Sate);
u8 MSTK_u8ClearCountFlag();
void MSTK_voidClearValueReg();
#define MSTK_INT_EN    1
#define MSTK_INT_DIS   0

#endif