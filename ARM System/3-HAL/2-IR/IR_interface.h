/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 19/9/2023                                            */
/* SWC     : IR                                                   */
/* Layer   : HAL                                                  */
/* Version : V01                                                  */
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

#define ON_OFF_BUTTON  69
#define MODE_BUTTON    70
#define MUTE_BUTTON    71
#define PLAY_BUTTON    68
#define LEFT_BUTTON    64
#define RIGHT_BUTTON   67
#define EQ_BUTTON      7
#define VOL_MINS_BUTTON 21
#define VOL_PLUS_BUTTON 9
#define ZERO_BUTTON     22
#define RPT_BUTTON    25
#define U_SD_BUTTON  13
#define ONE_BUTTON 12
#define TWO_BUTTON  24
#define THREE_BUTTON  94
#define FOUR_BUTTON  8
#define FIVE_BUTTON 28
#define SIX_BUTTON   90
#define SEVEN_BUTTON   66
#define EIGHT_BUTTON  82
#define NINE_BUTTON   74

void IR_voidInt();
static void IR_voidGetFrame(void);
static void IR_voidGetData(void);
u16 IR_u16Data(void);
void IR_voidCallBack(void(*Copy_pfCallBack)(void));


#endif
