/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 23/9/2023                                            */
/* SWC     : OS                                                   */
/* Layer   : Services                                                  */
/* Version : V01                                                  */
/******************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H
void SOS_voidCreateTask(u16 Copy_Id,u16 Copy_Priodicity,void(*Copy_Ptr)(void),u16 Copy_FirstDelay);
void SOS_voidStart(void);

#endif
