#include "delay.h"

static u32 TimingDelay;

/**************************************
* ������   : Delay_ms
* ����     : ms����ʱ
* ������� : u32 nTime
* ����ֵ   : ��
**************************************/
void delay_ms(u16 nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}


//void delay_us(u32 nTime)
//{ 
//  TimingDelay = nTime;

//  while(TimingDelay != 0);
//}


/**************************************
* ������   : TimingDelay_Decrement
* ����     : ����TimingDelay�Լ�
* ������� : ��
* ����ֵ   : ��
**************************************/
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

/**************************************
* ������   : SysTick_Init
* ����     : ϵͳ��ʱ����ʼ��
* ������� : ��
* ����ֵ   : ��

  HSE = 4M
  SYSCLK=HSE * 12 = 48M
  AHB = APB = SYSCLK
**************************************/


void delay_Init(void)
{
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);
	if(RCC_WaitForHSEStartUp() == SUCCESS) {  /*�ȴ�HSE����,  SUCCESS��HSE�����ȶ��Ҿ���*/  

   RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_12);/*����PLLʱ��Դ����Ƶϵ��*/    
   RCC_PLLCmd(ENABLE); 	 /*ʹ��PLL */ 
		
   RCC_HCLKConfig(RCC_SYSCLK_Div1); /* AHB clock = HCLK = SYSCLK */
   RCC_PCLKConfig(RCC_HCLK_Div1);		/* APB clock = PCLK = SYSCLK  */     

   
   while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) ; /*���ָ����RCC��־λ(PLL׼���ñ�־)�������*/ 
    
   RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);  /*����ϵͳʱ�ӣ�SYSCLK�� */  
   while(RCC_GetSYSCLKSource() != 0x08);     /*0x08��PLL��Ϊϵͳʱ�� */	    
	 } 
	
	
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
    while (1);
  }
}

void SysTick_Handler(void)
{
	TimingDelay_Decrement();
}
