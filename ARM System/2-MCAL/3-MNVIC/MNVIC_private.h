/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 21/8/2023                                            */
/* SWC     : NVIC                                                 */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MNVIC_PRIVATE_H
#define MNVIC_PRIVATE_H

#define MNVIC_BASE_ADDRES    0xE000E100

#define MNVIC_ISER0          *((u32*)(MNVIC_BASE_ADDRES+0x000))
#define MNVIC_ISER1          *((u32*)(MNVIC_BASE_ADDRES+0x004))

#define MNVIC_ICER0          *((u32*)(MNVIC_BASE_ADDRES+0x080))
#define MNVIC_ICER1          *((u32*)(MNVIC_BASE_ADDRES+0x084))

#define MNVIC_ISPR0          *((u32*)(MNVIC_BASE_ADDRES+0x100))
#define MNVIC_ISPR1          *((u32*)(MNVIC_BASE_ADDRES+0x104))

#define MNVIC_ICPR0          *((u32*)(MNVIC_BASE_ADDRES+0x180))
#define MNVIC_ICPR1          *((u32*)(MNVIC_BASE_ADDRES+0x184))

#define MNVIC_IABR0          *((volatile u32*)(MNVIC_BASE_ADDRES+0x200))
#define MNVIC_IABR1          *((volatile u32*)(MNVIC_BASE_ADDRES+0x204))

#define MNVIC_IPR            ((volatile u8*)(MNVIC_BASE_ADDRES+0x300)) 

#define SCB_BASE_ADDRES       0xE000ED00
#define SCB_AIRCR            *((volatile u32*)(SCB_BASE_ADDRES+0x0C))

#define MNVIC_GROUP_4_SUB_0   0x05FA0300
#define MNVIC_GROUP_3_SUB_1   0x05FA0400
#define MNVIC_GROUP_2_SUB_2   0x05FA0500
#define MNVIC_GROUP_1_SUB_3   0x05FA0600
#define MNVIC_GROUP_0_SUB_4   0x05FA0700


#endif
