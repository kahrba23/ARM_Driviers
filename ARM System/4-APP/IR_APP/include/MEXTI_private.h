/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 22/8/2023                                            */
/* SWC     : External interrupt                                    */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MEXTI_PRIVATE_H
#define MEXTI_PRIVATE_H

typedef struct 
{
     volatile u32 IMR;
     volatile u32 EMR;
     volatile u32 RTSR;
     volatile u32 FTSR;
     volatile u32 SWIER;
     volatile u32 PR;
}EXTI_t;

#define MEXTI   ((volatile EXTI_t *) 0x40010400 )





#endif
