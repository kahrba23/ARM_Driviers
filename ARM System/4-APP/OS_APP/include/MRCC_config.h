/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 16/8/2023                                            */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MRCC_CONFIG_H
#define MRCC_CONFIG_H
/*options   MRCC_HSE_CRYSTAL
            MRCC_HSE_RC
            MRCC_HSI
            MRCC_PLL   */
#define MRCC_CLOCK_TYPE   MRCC_HSE_CRYSTAL


/*Options  MRCC_PLL_INPUT_HSI_DIV_2
           MRCC_PLL_INPUT_HSE_DIV_2
           MRCC_PLL_INPUT_HSE  */
/*Note:Select value only when clock type is PLL*/
#if MRCC_CLOCK_TYPE==MRCC_PLL
#define MRCC_PLL_INPUT    MRCC_PLL_INPUT_HSI_DIV_2
#endif


/*Options PLL_MUL_BY_2 TO PLL_MUL_BY_16 */
/*Note:Select value only when clock type is PLL*/
#if MRCC_CLOCK_TYPE==MRCC_PLL
#define MRCC_PLL_MUL_VAL    PLL_MUL_BY_2
#endif
/*Security clock system*/
/*options  ENABLE_CLOCK_SECURITY_SYSTEM
 *         DISABLE_CLOCK_SECURITY_SYSTEM*/
#define CLOCK_SECURITY_SYSTEM  ENABLE_CLOCK_SECURITY_SYSTEM


#endif
