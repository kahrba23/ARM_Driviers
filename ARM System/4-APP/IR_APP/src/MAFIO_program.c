/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 22/8/2023                                            */
/* SWC     : AFIO                                                 */
/* Version : V01                                                  */
/******************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MAFIO_interface.h"
#include"MAFIO_private.h"
#include"MAFIO_config.h"
void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line,u8 Copy_u8PortMap)
{
    u8 Local_u8Index=(Copy_u8Line/4);
    
    /**/
    MAFIO->EXTICR[Local_u8Index]&=~((0b1111)<<(((Copy_u8Line)%4)*4));
    MAFIO->EXTICR[Local_u8Index]|=(Copy_u8PortMap<<(((Copy_u8Line)%4)*4));
}