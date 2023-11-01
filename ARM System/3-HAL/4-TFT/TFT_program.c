/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 7/10/2023                                            */
/* SWC     : TFT HAL Layer                                        */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_interface.h"
#include "MSPI_interface.h"
#include "MSYSTICK_interface.h"
#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
	MGPIO_voidSetPinValue(TFT_RST_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,MGPIO_PIN_LOW);
	MSTK_voidBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,MGPIO_PIN_LOW);
	MSTK_voidBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,MGPIO_PIN_HIGH);
	MSTK_voidBusyWait(120000);
	WriteCommand(0x11);
	MSTK_voidBusyWait(150000);
	WriteCommand(0x3A);
	WriteData(0x05);
	WriteCommand(0x29);




}
void HTFT_voidDisplayImage(const u16* Copy_pu16Image)
{
	/*Set X Address*/
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(127);
	/*Set Y Address*/
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(159);
	/*RAM WRITE*/
	WriteCommand(0x2C);
	for(u16 i=0;i<20480;i++)
	{
		WriteData(Copy_pu16Image[i]>>8);//High Byte
		WriteData(Copy_pu16Image[i]&0x00ff);//Low Byte
	}
}
void HTFT_voidFillColor(u16 Copy_u16Color)
{
	/*Set X Address*/
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(127);
	/*Set Y Address*/
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(159);
	/*RAM WRITE*/
	WriteCommand(0x2C);
	for(u16 i=0;i<20480;i++)
	{
		WriteData(Copy_u16Color>>8);//High Byte
		WriteData(Copy_u16Color&0x00ff);//Low Byte
	}
}

void HTFT_voidDrawRect(u8 Copy_u8X1,u8 Copy_u8X2,u8 Copy_u8Y1,u8 Copy_u8Y2,u16 Copy_u16Color)
{
	u16 Size =(Copy_u8X2-Copy_u8X1)*(Copy_u8Y1-Copy_u8Y2);
	/*Set X Address*/
	WriteCommand(0x2A);
	WriteData(0);
	WriteData(Copy_u8X1);
	WriteData(0);
	WriteData(Copy_u8X2);
	/*Set Y Address*/
	WriteCommand(0x2B);
	WriteData(0);
	WriteData(Copy_u8Y1);
	WriteData(0);
	WriteData(Copy_u8Y2);
	/*RAM WRITE*/
	WriteCommand(0x2C);
	for(u16 i=0;i<Size;i++)
	{
		WriteData(Copy_u16Color>>8);//High Byte
		WriteData(Copy_u16Color&0x00ff);//Low Byte
	}
}

static void WriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Buffer;
	MGPIO_voidSetPinValue(TFT_A0_PIN,MGPIO_PIN_LOW);
	MSPI_voidStarSynctTransmittReceive(Copy_u8Command,&Local_u8Buffer);
}

static void WriteData(u8 Copy_u8Data)
{
	u8 Local_u8Buffer;
	MGPIO_voidSetPinValue(TFT_A0_PIN,MGPIO_PIN_HIGH);
	MSPI_voidStarSynctTransmittReceive(Copy_u8Data,&Local_u8Buffer);
}
