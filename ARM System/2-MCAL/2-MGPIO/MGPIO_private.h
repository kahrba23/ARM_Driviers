/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 19/8/2023                                            */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MGPIO_PRIVATE_H
#define MGPIO_PRIVATE_H

#define MGPIOA_BASE_ADDRES    0x40010800
#define MGPIOB_BASE_ADDRES    0x40010C00
#define MGPIOC_BASE_ADDRES    0x40011000


                 /* REGISTERS FOR PORTA*/
#define MGPIOA_CRL                          *((volatile u32*)(MGPIOA_BASE_ADDRES+0x00))
#define MGPIOA_CRH                          *((volatile u32*)(MGPIOA_BASE_ADDRES+0x04))
#define MGPIOA_IDR                          *((volatile u32*)(MGPIOA_BASE_ADDRES+0x08))
#define MGPIOA_ODR                          *((volatile u32*)(MGPIOA_BASE_ADDRES+0x0C))
#define MGPIOA_BSRR                         *((volatile u32*)(MGPIOA_BASE_ADDRES+0x10))
#define MGPIOA_BRR                          *((volatile u32*)(MGPIOA_BASE_ADDRES+0x14))
#define MGPIOA_LCKR                         *((volatile u32*)(MGPIOA_BASE_ADDRES+0x18))


                  /* REGISTERS FOR PORTB*/
#define MGPIOB_CRL                          *((volatile u32*)(MGPIOB_BASE_ADDRES+0x00))
#define MGPIOB_CRH                          *((volatile u32*)(MGPIOB_BASE_ADDRES+0x04))
#define MGPIOB_IDR                          *((volatile u32*)(MGPIOB_BASE_ADDRES+0x08))
#define MGPIOB_ODR                          *((volatile u32*)(MGPIOB_BASE_ADDRES+0x0C))
#define MGPIOB_BSRR                         *((volatile u32*)(MGPIOB_BASE_ADDRES+0x10))
#define MGPIOB_BRR                          *((volatile u32*)(MGPIOB_BASE_ADDRES+0x14))
#define MGPIOB_LCKR                         *((volatile u32*)(MGPIOB_BASE_ADDRES+0x18))

                  /* REGISTERS FOR PORTC*/
#define MGPIOC_CRL                          *((volatile u32*)(MGPIOC_BASE_ADDRES+0x00))
#define MGPIOC_CRH                          *((volatile u32*)(MGPIOC_BASE_ADDRES+0x04))
#define MGPIOC_IDR                          *((volatile u32*)(MGPIOC_BASE_ADDRES+0x08))
#define MGPIOC_ODR                          *((volatile u32*)(MGPIOC_BASE_ADDRES+0x0C))
#define MGPIOC_BSRR                         *((volatile u32*)(MGPIOC_BASE_ADDRES+0x10))
#define MGPIOC_BRR                          *((volatile u32*)(MGPIOC_BASE_ADDRES+0x14))
#define MGPIOC_LCKR                         *((volatile u32*)(MGPIOC_BASE_ADDRES+0x18))

















#endif
