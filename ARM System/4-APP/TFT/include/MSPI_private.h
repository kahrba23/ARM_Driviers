/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 10/3/2023                                            */
/* SWC     : SPI                                                  */
/* Version : V01                                                  */
/******************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;

}SPI_t;

#define MSPI  ((volatile SPI_t *)0x40013000)

#define F_CLK_DIV_BY_2   0
#define F_CLK_DIV_BY_4   1
#define F_CLK_DIV_BY_8   2
#define F_CLK_DIV_BY_16  3
#define F_CLK_DIV_BY_32  4
#define F_CLK_DIV_BY_64  5
#define F_CLK_DIV_BY_128 6
#define F_CLK_DIV_BY_256 7

#define  LEADING_EDGE_RISING_SAMPLE   0b00
#define  LEADING_EDGE_RISING_SETUP    0b01
#define  LEADING_EDGE_FALLING_SAMPLE  0b10
#define  LEADING_EDGE_FALLING_SETUP   0b11

#define _8_BIT_DATA  1
#define _16_BIT_DATA 2

#define LSB_FIRST 1
#define MSB_FIRST 2






#endif
