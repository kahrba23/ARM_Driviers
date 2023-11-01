/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 19/8/2023                                            */
/* Version : V01                                                  */
/******************************************************************/
#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFCAE_H

#define MGPIOA        0
#define MGPIOB        1
#define MGPIOC        2

#define MGPIO_PIN0    0
#define MGPIO_PIN1    1
#define MGPIO_PIN2    2
#define MGPIO_PIN3    3
#define MGPIO_PIN4    4
#define MGPIO_PIN5    5
#define MGPIO_PIN6    6
#define MGPIO_PIN7    7
#define MGPIO_PIN8    8
#define MGPIO_PIN9    9
#define MGPIO_PIN10   10
#define MGPIO_PIN11   11
#define MGPIO_PIN12   12
#define MGPIO_PIN13   13
#define MGPIO_PIN14   14
#define MGPIO_PIN15   15

/*Modes*/
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

#define INPUT_ANALOG              0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PUPD                0b1000


#define MGPIO_PIN_LOW  0
#define MGPIO_PIN_HIGH 1

#define POSITION_LOW  0
#define POSITION_HIGH 1

#define MGPIO_LOW_PORT_HIGH  0x00FF
#define MGPIO_LOW_PORT_LOW   0x0000
#define MGPIO_HIGH_PORT_HIGH 0xFF00
#define MGPIO_HIGH_PORT_LOW  0x0000





void MGPIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
u8 MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);
void MGPIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Position,u8 Copy_u8Mode);
void MGPIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Position,u16 Copy_u8Value);

















#endif
