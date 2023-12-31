/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 22/8/2023                                            */
/* SWC     : AFIO                                                 */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MAFIO_INTERFACE_H
#define MAFIO_INTERFACE_H


#define EXTI0  0
#define EXTI1  1
#define EXTI2  2
#define EXTI3  3

#define EXTI4  4
#define EXTI5  5
#define EXTI6  6
#define EXTI7  7

#define EXTI8  8
#define EXTI9  9
#define EXTI10 10
#define EXTI11 11

#define EXTI12 12
#define EXTI13 13
#define EXTI14 14
#define EXTI15 15

#define PORTA  0000
#define PORTB  0001
#define PORTC  0010


void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line,u8 Copy_u8PortMap);

#endif