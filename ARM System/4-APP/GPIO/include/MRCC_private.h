/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 16/8/2023                                            */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H
/* Register Definitions*/
//0x40021000
#define MRCC_CR        *((u32*)0x40021000) //Clock

#define MRCC_CFGR      *((u32*)0x40021004) //Clock

#define MRCC_CIR       *((u32*)0x40021008)

#define MRCC_APB2RSTR  *((u32*)0x4002100C)

#define MRCC_APB1RSTR  *((u32*)0x40021010)

#define MRCC_AHBENR    *((u32*)0x40021014) //Clock

#define MRCC_APB2ENR   *((u32*)0x40021018) //Clock

#define MRCC_APB1ENR   *((u32*)0x4002101C) //Clock

#define MRCC_BDCR      *((u32*)0x40021020)

#define MRCC_CSR       *((u32*)0x40021024)

/*Clock Types*/
#define MRCC_HSE_CRYSTAL     1
#define MRCC_HSE_RC          2
#define MRCC_HSI             3
#define MRCC_PLL             4
/*PLL_INPUT*/
#define MRCC_PLL_INPUT_HSI_DIV_2  1
#define MRCC_PLL_INPUT_HSE_DIV_2  2
#define MRCC_PLL_INPUT_HSE        3
/*PLL Multiplication Factor*/
#define PLL_MUL_BY_2    0b0000
#define PLL_MUL_BY_3    0b0001
#define PLL_MUL_BY_4    0b0010
#define PLL_MUL_BY_5    0b0011
#define PLL_MUL_BY_6    0b0100
#define PLL_MUL_BY_7    0b0101
#define PLL_MUL_BY_8    0b0110
#define PLL_MUL_BY_9    0b0111
#define PLL_MUL_BY_10   0b1000
#define PLL_MUL_BY_11   0b1001
#define PLL_MUL_BY_12   0b1010
#define PLL_MUL_BY_13   0b1011
#define PLL_MUL_BY_14   0b1100
#define PLL_MUL_BY_15   0b1101
#define PLL_MUL_BY_16   0b1110
/*Security system in clock*/
#define ENABLE_CLOCK_SECURITY_SYSTEM  1
#define DISABLE_CLOCK_SECURITY_SYSTEM 2


#endif
