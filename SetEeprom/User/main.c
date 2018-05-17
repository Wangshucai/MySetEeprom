#include "stm32f0xx.h"
#include "LED.h"
#include "LCD.h"
#include "delay.h"
#include "24cxx.h" 

u8 num = 0;


uint8_t Data[64];
uint8_t DataRead[64];


void SetInit(void)
{ 
	disp_str((u8 *)"系初始统化",0,2);	
	disp_str((u8 *)"□□□□□□□",0,4);
	delay_ms(500);
	disp_str((u8 *)"■",0,4);
	delay_ms(500);
	disp_str((u8 *)"■■",0,4);
	delay_ms(500);
	disp_str((u8 *)"■■■",0,4);
	delay_ms(500);
	disp_str((u8 *)"■■■■",0,4);
	delay_ms(500);
	disp_str((u8 *)"■■■■■",0,4);
	delay_ms(500);
	disp_str((u8 *)"■■■■■■",0,4);
    delay_ms(500);
	disp_str((u8 *)"■■■■■■■",0,4);
}
int main()
{
	int i;
	 delay_Init();
	 LED_Init();
	 LCD_Init();
	 //SetInit();
	for(i = 0;i < 64;i ++)
	{
	  Data[i] = 0XFF;
	}
	

	 AT24CXX_Init();
	

	for(i = 0;i < 256;i ++)
	{
	   AT24CXX_Write(i*64,Data,sizeof(Data));
	}
	
	
	
	
	num=AT24CXX_ReadOneByte(63);	  
	
	while(1)
	{
//	    LED1_Toggle();
//		
//	    LED2_Toggle();
		LED1(0);
		LED2(0);
		delay_ms(500);
		LED1(1);
		LED2(1);
		delay_ms(500);
		
		//num++;
	}
	
}
