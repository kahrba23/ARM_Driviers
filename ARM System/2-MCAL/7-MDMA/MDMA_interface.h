/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 10/3/2023                                            */
/* SWC     : DMA                                              */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MDMA_INTERFACE_H
#define MDMA_INTERFACE_H

#define CHANNEL1_ID      0
#define CHANNEL2_ID      1
#define CHANNEL3_ID      2
#define CHANNEL4_ID      3
#define CHANNEL5_ID      4
#define CHANNEL6_ID      5
#define CHANNEL7_ID      6









void MDMA_voidInit(void);
void MDMA_voidChannelStart(u8 Copy_u8ChannelId,u32 * Copy_pu32PeriAddress,u32 * Copy_pu32MemoryAddress,u16 Copy_u16DataSize);

#endif
