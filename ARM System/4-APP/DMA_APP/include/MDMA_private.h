/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 10/3/2023                                            */
/* SWC     : DMA                                              */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MDMA_PRIVATE_H
#define MDMA_PRIVATE_H


typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESERVED;
}DMA_CHANNEL;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	volatile DMA_CHANNEL CHANNEL[7];
}DMA_t;

#define MDMA ((volatile DMA_t *)0x40020000)

#define SELECTED_CHANNEL     1
#define UNSELECTED_CHANNEL   2

#define TRANSFER_COMPELET_INT_ENABLE       1
#define TRANSFER_COMPELET_INT_DISABLE      0

#define HALF_TRANSFER_COMPELET_INT_ENABLE  1
#define HALF_TRANSFER_COMPELET_INT_DISABLE 0

#define TRANSFER_ERROR_INT_ENABLE          1
#define TRANSFER_ERROR_INT_DISABLE         0

#define ENABLE_M2M_MODE      1
#define DISABLE_M2M_MODE     0

#define PERIPHERAL_TO_MEMORY 0
#define MEMORY_TO_PERIPHERAL 1

#define ENABLE_CIRCULAR_MODE  1
#define DISABLE_CIRCULAR_MODE 0

#define ENABLE_PINC  1
#define DISABLE_PINC 0

#define ENABLE_MINC  1
#define DISABLE_MINC 0

#define PSIZE_8_BIT   0
#define PSIZE_16_BIT  1
#define PSIZE_32_BIT  2

#define MSIZE_8_BIT   0
#define MSIZE_16_BIT  1
#define MSIZE_32_BIT  2

#define SMALL_PRIORITY   0
#define MEDIUM_PRIORITY  1
#define HIGH_PRIORITY    2

#endif
////TRANSFER_COMPELET_INT_ENABLE
///HALF_TRANSFER_COMPELET_INT_DISABLE
///TRANSFER_ERROR_INT_DISABLE
