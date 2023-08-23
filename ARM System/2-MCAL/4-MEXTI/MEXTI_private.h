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
     u32 IMR;
     u32 EMR;
     u32 RTSR;
     u32 FTSR;
     u32 SWIER;
     u32 PR;
}EXTI_t;

#define MEXTI   ((volatile EXTI_t *) 0x40010400 )





#endif