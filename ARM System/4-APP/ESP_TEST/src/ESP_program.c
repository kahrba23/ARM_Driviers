/******************************************************************/
/* Author  : Ahmed Abdallah                                       */
/* Date    : 9/10/2023                                            */
/* SWC     : ESP                                                  */
/* Version : V01                                                  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MUART_interface.h"
#include "MGPIO_interface.h"
#include "ESP_interface.h"
#include "ESP_config.h"
#include "ESP_private.h"
static u8 ESP_SRC=0;
static u8 ESP_Data=0;
void ESP_voidInit(void)
{
	ESP_SRC=0;
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
		MUSART1_voidSyncTransmitString("ATE0\r\n");
		Local_u8Result=voidESPvalidATCmd();
	}
	Local_u8Result=0;
	while(Local_u8Result==0)
	{
		MUSART1_voidSyncTransmitString("AT+CWMODE=1\r\n");
		Local_u8Result=voidESPvalidATCmd();
	}
}
void ESP_voidConnectToWIFI(u8 *Copy_pu8UserName,u8 *Copy_pu8Pass)
{
	ESP_SRC=2;
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
		MUSART1_voidSyncTransmitString("AT+CWJAP=\"");
		MUSART1_voidSyncTransmitString(Copy_pu8UserName);
		MUSART1_voidSyncTransmitString("\",\"");
		MUSART1_voidSyncTransmitString(Copy_pu8Pass);
		MUSART1_voidSyncTransmitString("\"\r\n");
		Local_u8Result=voidESPvalidATCmd();
	}
}
void ESP_voidConnectToServer(u8 *Copy_pu8IP,u8 *Copy_pu8Port)
{
	ESP_SRC=0;
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
		MUSART1_voidSyncTransmitString("AT+CIPSTART=\"TCP\",\"");
		MUSART1_voidSyncTransmitString(Copy_pu8IP);
		MUSART1_voidSyncTransmitString("\",");
		MUSART1_voidSyncTransmitString(Copy_pu8Port);
		MUSART1_voidSyncTransmitString("\r\n");
		Local_u8Result=voidESPvalidATCmd();
	}
}
u8 ESP_voidRecieveData(u8 *Copy_u8Size,u8 *Copy_pu8Server,u8 *Copy_u8File)
{
	ESP_SRC=0;
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
		MUSART1_voidSyncTransmitString("AT+CIPSEND=");
		MUSART1_voidSyncTransmitString(Copy_u8Size);
		MUSART1_voidSyncTransmitString("\r\n");
		Local_u8Result=voidESPvalidATCmd();
	}
	ESP_SRC=1;
	Local_u8Result=0;
	while(Local_u8Result==0)
	{
		MUSART1_voidSyncTransmitString("GET http://");
		MUSART1_voidSyncTransmitString(Copy_pu8Server);
		MUSART1_voidSyncTransmitChar('/');
		MUSART1_voidSyncTransmitString(Copy_u8File);
		MUSART1_voidSyncTransmitString("\r\n");
		Local_u8Result=voidESPvalidATCmd();
	}
	return ESP_Data;
}

u8 voidESPvalidATCmd(void)
{
	u8 Local_u8DataArray[100]={0};
	u8 Local_u8Counter=0;
	u8 Local_u8Result=0;
	u8 Dummy=0,i=0;
	while(Dummy!=255)
	{
		if(ESP_SRC!=2)
		{
			MUSART1_voidTimeoutRecieve(&Dummy);
			Local_u8DataArray[Local_u8Counter]=Dummy;
			Local_u8Counter++;
		}
		else
		{
			MUSART1_voidTimeoutRecieveWIFI(&Dummy);
			Local_u8DataArray[Local_u8Counter]=Dummy;
			Local_u8Counter++;
		}
	}
	while(Local_u8DataArray[i]!=255)
	{
		if(Local_u8DataArray[i]=='O'&&Local_u8DataArray[i+1]=='K')  {Local_u8Result=1;break;}
		i++;
	}
	i=0;
	if(ESP_SRC==1)
	{
		while(Local_u8DataArray[i]!=255)
		{
			if(Local_u8DataArray[i]==':')  {break;}
			i++;
		}
		ESP_Data=Local_u8DataArray[i+1]-'0';
		ESP_SRC=0;
	}
	return Local_u8Result;
}
