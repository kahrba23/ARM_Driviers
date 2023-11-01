/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 10/3/2023                                            */
/* SWC     : SPI                                                  */
/* Version : V01                                                  */
/******************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define BAUD_RATE  F_CLK_DIV_BY_2

#define MSPI_MASTER_CLK_POL_PH LEADING_EDGE_RISING_SAMPLE
#define MSPI_MASTER_DATA_SIZE   _8_BIT_DATA
#define MSPI_MASTER_DATA_ORDER  LSB_FIRST

#define MSPI_SLAVE_CLK_POL_PH  LEADING_EDGE_RISING_SAMPLE
#define MSPI_SLAVE_DATA_SIZE   _8_BIT_DATA
#define MSPI_SLAVE_DATA_ORDER  LSB_FIRST

#endif
