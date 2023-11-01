/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 4/10/2023                                            */
/* SWC     : UART                                                  */
/* Version : V01                                                  */
/******************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H
#define ENABLE_INT  1
#define DISABLE_INT 0

#define TC_INT   6
#define TXE_INT  7
#define RXNE_INT 5
#define PE_INT   8
#define IDLE_INT 4

void MUSART1_voidInit(void);
void MUSART1_voidSyncTransmitChar(u8 Copy_u8Data);
void MUSART1_voidSyncTransmitString(u8 *Copy_pu8Data);
void MUSART1_u8SyncReceive(u8 *Copy_pu8Data);
void MUSART1_voidASyncTransmitChar(u8 Copy_u8Data);
void MUSART1_voidASyncTransmitString(u8 *Copy_pu8String);
void MUSART1_u8ASyncReceive(void (*Copy_Ptr)(u8));
void MUSART1_voidINTState(u8 Copy_u8State,u8 Copy_u8IntId);



#endif
