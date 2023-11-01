/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 4/10/2023                                            */
/* SWC     : UART                                                  */
/* Version : V01                                                  */
/******************************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define MUSART_F_CLk          8000000UL

#define MUSART_BAUD_RATE  (u32)9600

#define MUSART1_STATE  MUSART1_ENABLE

#define MUSART1_WORD_LENGTH  MUSART1_8_DATA_BITS

#define MUSART1_PARITY_CONTROL_STATE  PARITY_CONTROL_DISABLED

#define MUSART1_PARITY_TYPE  ODD_PARITY

#define MUSART1_TXE_INT_STATE    INT_DISABLED
#define MUSART1_PE_INT_STATE     INT_DISABLED
#define MUSART1_TC_INT_STATE     INT_DISABLED
#define MUSART1_RXNE_INT_STATE   INT_DISABLED
#define MUSART1_IDLE_INT_STATE   INT_DISABLED

#define MUSART1_TRANSMITTER_STATE        TRANSMITTER_ENABLED

#define MUSART1_RECEIVER_STATE           RECEIVER_ENABLED

#define MUSART1_STOP_BITS    ONE_STOP_BIT

#define MUSART1_CLK_SATE     CLK_DISABLED

#define MUSART1_CLK_POL_PH   LEADING_EDGE_RISING_SAMPLE

#endif
