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
#define MGPIOA_CRL                          *((u32*)(MGPIOA_BASE_ADDRES+0x00))
#define MGPIOA_CRH                          *((u32*)(MGPIOA_BASE_ADDRES+0x04))
#define MGPIOA_IDR                          *((u32*)(MGPIOA_BASE_ADDRES+0x08))
#define MGPIOA_ODR                          *((u32*)(MGPIOA_BASE_ADDRES+0x0C))
#define MGPIOA_BSRR                         *((u32*)(MGPIOA_BASE_ADDRES+0x10))
#define MGPIOA_BRR                          *((u32*)(MGPIOA_BASE_ADDRES+0x14))
#define MGPIOA_LCKR                         *((u32*)(MGPIOA_BASE_ADDRES+0x18))


                  /* REGISTERS FOR PORTB*/
#define MGPIOB_CRL                          *((u32*)(MGPIOB_BASE_ADDRES+0x00))
#define MGPIOB_CRH                          *((u32*)(MGPIOB_BASE_ADDRES+0x04))
#define MGPIOB_IDR                          *((u32*)(MGPIOB_BASE_ADDRES+0x08))
#define MGPIOB_ODR                          *((u32*)(MGPIOB_BASE_ADDRES+0x0C))
#define MGPIOB_BSRR                         *((u32*)(MGPIOB_BASE_ADDRES+0x10))
#define MGPIOB_BRR                          *((u32*)(MGPIOB_BASE_ADDRES+0x14))
#define MGPIOB_LCKR                         *((u32*)(MGPIOB_BASE_ADDRES+0x18))

                  /* REGISTERS FOR PORTC*/
#define MGPIOC_CRL                          *((u32*)(MGPIOC_BASE_ADDRES+0x00))
#define MGPIOC_CRH                          *((u32*)(MGPIOC_BASE_ADDRES+0x04))
#define MGPIOC_IDR                          *((u32*)(MGPIOC_BASE_ADDRES+0x08))
#define MGPIOC_ODR                          *((u32*)(MGPIOC_BASE_ADDRES+0x0C))
#define MGPIOC_BSRR                         *((u32*)(MGPIOC_BASE_ADDRES+0x10))
#define MGPIOC_BRR                          *((u32*)(MGPIOC_BASE_ADDRES+0x14))
#define MGPIOC_LCKR                         *((u32*)(MGPIOC_BASE_ADDRES+0x18))

















#endif
