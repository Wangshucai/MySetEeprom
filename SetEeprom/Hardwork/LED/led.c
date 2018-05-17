#include "LED.h"
/**************************************
* 函数名   : LED_Init
* 描述     : led端口初始化 
* 输入参数 : 无
* 返回值   : 无
**************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed =GPIO_Speed_Level_3;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
   GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_9);
	GPIO_SetBits(GPIOE, GPIO_Pin_0);
}

/**************************************
* 函数名   : LED1_ON
* 描述     : 打开led1
* 输入参数 : 无
* 返回值   : 无
**************************************/
void LED1_OFF(void)
{
	 GPIO_ResetBits(GPIOB, GPIO_Pin_9);
}

/**************************************
* 函数名   : LED1_OFF
* 描述     : 关闭led1
* 输入参数 : 无
* 返回值   : 无
**************************************/
void LED1_ON(void)
{
		GPIO_SetBits(GPIOB, GPIO_Pin_9);
}

/**************************************
* 函数名   : LED1_Toggle
* 描述     : 翻转led1
* 输入参数 : 无
* 返回值   : 无
**************************************/
void LED1_Toggle(void)
{
GPIO_WriteBit(GPIOB, GPIO_Pin_9, 
		               (BitAction)((1-GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_9))));
}

/**************************************
* 函数名   : LED2_ON
* 描述     : 打开led2
* 输入参数 : 无
* 返回值   : 无
**************************************/
void LED2_OFF(void)
{
	 GPIO_ResetBits(GPIOE, GPIO_Pin_0);
}

/**************************************
* 函数名   : LED2_OFF
* 描述     : 关闭led2
* 输入参数 : 无
* 返回值   : 无
**************************************/
void LED2_ON(void)
{
		GPIO_SetBits(GPIOE, GPIO_Pin_0);
}

/**************************************
* 函数名   : LED2_Toggle
* 描述     : 翻转led2
* 输入参数 : 无
* 返回值   : 无
**************************************/
void LED2_Toggle(void)
{
GPIO_WriteBit(GPIOE, GPIO_Pin_0, 
		               (BitAction)((1-GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_0))));
}

