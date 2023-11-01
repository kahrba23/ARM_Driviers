/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 4/10/2023                                            */
/* SWC     : UART                                                  */
/* Version : V01                                                  */
/******************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_t;

#define MUSART1 ((volatile UART_t *)0x40013800)

#define MUSART1_ENABLE   1
#define MUSART1_DISABLE   0

#define MUSART1_8_DATA_BITS  0
#define MUSART1_9_DATA_BITS 1

#define PARITY_CONTROL_DISABLED  0
#define PARITY_CONTROL_ENABLED   1

#define ODD_PARITY  1
#define EVEN_PARITY 0

#define INT_ENABLED 1
#define INT_DISABLED 0

#define TRANSMITTER_ENABLED  1
#define TRANSMITTER_DISABLED 0

#define RECEIVER_ENABLED  1
#define RECEIVER_DISABLED 0

#define ONE_STOP_BIT  0
#define HALF_STOP_BIT 1
#define ONE_HALF_STOP_BIT 2
#define TWO_STOP_BIT 3

#define CLK_ENABLED   1
#define CLK_DISABLED  0

#define  LEADING_EDGE_RISING_SAMPLE   0b00
#define  LEADING_EDGE_RISING_SETUP    0b01
#define  LEADING_EDGE_FALLING_SAMPLE  0b10
#define  LEADING_EDGE_FALLING_SETUP   0b11

#define TRANSMIT_CHAR   0
#define TRANSMIT_STRING 1
#define NO_SOURCE       2

#endif
