/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 23/9/2023                                            */
/* SWC     : OS                                                   */
/* Layer   : Services                                                  */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSYSTICK_interface.h"
#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"

static Task OS_TASKS[OS_NUMBER_OF_TASKS]={NULL};
void SOS_voidCreateTask(u16 Copy_Id,u16 Copy_Priodicity,void(*Copy_Ptr)(void),u16 Copy_FirstDelay)
{
	OS_TASKS[Copy_Id].Priodicity=Copy_Priodicity;
	OS_TASKS[Copy_Id].FirstDelay=Copy_FirstDelay;
	OS_TASKS[Copy_Id].Fptr=Copy_Ptr;
}
/************************************************************************************************************/
void SOS_voidStart(void)
{
	MSTK_voidInt();
	MSTK_voidSetIntervalPeriodic(OS_SYS_TICK_NUMBER_OF_TICKS,SOS_Scheduler);
}
/************************************************************************************************************/
/*static void SOS_Scheduler(void)
{
	for(u16 i=0;i<OS_NUMBER_OF_TASKS;i++)
	{
		if(OS_Counter % OS_TASKS[i].Priodicity==0)
		{
			OS_TASKS[i].Fptr();
		}
	}
	OS_Counter++;
}
*/
static void SOS_Scheduler(void)
{
	for(u16 i=0;i<OS_NUMBER_OF_TASKS;i++)
	{
		if(OS_TASKS[i].Fptr!=NULL)
		{
			if(OS_TASKS[i].FirstDelay==0)
			{
				OS_TASKS[i].FirstDelay=OS_TASKS[i].Priodicity-1;
				OS_TASKS[i].Fptr();
			}
			else
			{
				OS_TASKS[i].FirstDelay--;
			}
		}
	}
}
