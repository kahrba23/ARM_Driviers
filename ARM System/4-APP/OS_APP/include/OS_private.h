/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 23/9/2023                                            */
/* SWC     : OS                                                   */
/* Layer   : Services                                                  */
/* Version : V01                                                  */
/******************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H
typedef struct {
	u16 Priodicity;
	void(* Fptr)(void);
	u16 FirstDelay;
}Task;
static void SOS_Scheduler(void);
#endif
