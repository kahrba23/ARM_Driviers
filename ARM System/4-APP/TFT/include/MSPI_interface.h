/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 10/3/2023                                            */
/* SWC     : SPI                                                  */
/* Version : V01                                                  */
/******************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI_voidMasterInit(void);
void MSPI_voidSlaveInit(void);
void MSPI_voidStarSynctTransmittReceive(u8 Copy_u8TransmittedData,u8 * Copy_pu8ReceivedData);
void MSPI_voidStarAsynctTransmittReceive(u8 Copy_u8TransmittedData,void (*Copy_ptr)(u8));
void MSPI_voidTXBufferEmpty(u8 *Copy_pu8Data);
void MSPI_voidDisable(void);

#endif
