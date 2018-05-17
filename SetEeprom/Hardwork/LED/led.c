#include "LED.h"
/**************************************
* ������   : LED_Init
* ����     : led�˿ڳ�ʼ�� 
* ������� : ��
* ����ֵ   : ��
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
* ������   : LED1_ON
* ����     : ��led1
* ������� : ��
* ����ֵ   : ��
**************************************/
void LED1_OFF(void)
{
	 GPIO_ResetBits(GPIOB, GPIO_Pin_9);
}

/**************************************
* ������   : LED1_OFF
* ����     : �ر�led1
* ������� : ��
* ����ֵ   : ��
**************************************/
void LED1_ON(void)
{
		GPIO_SetBits(GPIOB, GPIO_Pin_9);
}

/**************************************
* ������   : LED1_Toggle
* ����     : ��תled1
* ������� : ��
* ����ֵ   : ��
**************************************/
void LED1_Toggle(void)
{
GPIO_WriteBit(GPIOB, GPIO_Pin_9, 
		               (BitAction)((1-GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_9))));
}

/**************************************
* ������   : LED2_ON
* ����     : ��led2
* ������� : ��
* ����ֵ   : ��
**************************************/
void LED2_OFF(void)
{
	 GPIO_ResetBits(GPIOE, GPIO_Pin_0);
}

/**************************************
* ������   : LED2_OFF
* ����     : �ر�led2
* ������� : ��
* ����ֵ   : ��
**************************************/
void LED2_ON(void)
{
		GPIO_SetBits(GPIOE, GPIO_Pin_0);
}

/**************************************
* ������   : LED2_Toggle
* ����     : ��תled2
* ������� : ��
* ����ֵ   : ��
**************************************/
void LED2_Toggle(void)
{
GPIO_WriteBit(GPIOE, GPIO_Pin_0, 
		               (BitAction)((1-GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_0))));
}

