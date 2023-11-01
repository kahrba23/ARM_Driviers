/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 9/9/2023                                             */
/* SWC     :LED MATRIX                                            */
/* Version : V01                                                  */
/******************************************************************/
#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFCAE_H

#define LEDMRX_COLUMN_CONTROL 0
#define LEDMRX_ROW_CONTROL   1

void HLEDMRX_voidInit();
void HLEDMRX_voidMove(u8 Row);
void HLEDMRX_voidDisplay(u8 * Copy_pu8Ptr,u8 Copy_u8Control);

#endif
