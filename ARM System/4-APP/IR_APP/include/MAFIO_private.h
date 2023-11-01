/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 22/8/2023                                            */
/* SWC     : AFIO                                                 */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MAFIO_PRIVATE_H
#define MAFIO_PRIVATE_H

typedef struct
{
   volatile u32 EVCR;
   volatile u32 MAPR;
   volatile u32 EXTICR[4];
   volatile u32 MAPR2;
}AFIO_t;

#define MAFIO ((volatile AFIO_t*)0x40010000)

#endif