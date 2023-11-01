/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 22/8/2023                                            */
/* SWC     : SysTick                                              */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MSYSTICK_PRIVATE_H
#define MSYSTICK_PRIVATE_H
typedef struct 
{
    u32 CTRL;
    u32 LOAD;
    u32 VAL;
    u32 CALIB;
}STK_t;

#define MSTK              ((volatile STK_t *)0xE000E010)


#define MSTK_ENABLE       1
#define MSTK_DISABLE      2

#define MSTK_INT_ENABLE   1
#define MSTK_INT_DISABLE  2

#define MSTK_AHB          1
#define MSTK_AHB_DIV_BY_8 2

#define SINGLE 0
#define PERIODIC 1



#endif