#include "delay.h"

static u32 TimingDelay;

/**************************************
* 函数名   : Delay_ms
* 描述     : ms级延时
* 输入参数 : u32 nTime
* 返回值   : 无
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
* 函数名   : TimingDelay_Decrement
* 描述     : 变量TimingDelay自减
* 输入参数 : 无
* 返回值   : 无
**************************************/
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

/**************************************
* 函数名   : SysTick_Init
* 描述     : 系统定时器初始化
* 输入参数 : 无
* 返回值   : 无

  HSE = 4M
  SYSCLK=HSE * 12 = 48M
  AHB = APB = SYSCLK
**************************************/


void delay_Init(void)
{
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);
	if(RCC_WaitForHSEStartUp() == SUCCESS) {  /*等待HSE起振,  SUCCESS：HSE晶振稳定且就绪*/  

   RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_12);/*设置PLL时钟源及倍频系数*/    
   RCC_PLLCmd(ENABLE); 	 /*使能PLL */ 
		
   RCC_HCLKConfig(RCC_SYSCLK_Div1); /* AHB clock = HCLK = SYSCLK */
   RCC_PCLKConfig(RCC_HCLK_Div1);		/* APB clock = PCLK = SYSCLK  */     

   
   while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) ; /*检查指定的RCC标志位(PLL准备好标志)设置与否*/ 
    
   RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);  /*设置系统时钟（SYSCLK） */  
   while(RCC_GetSYSCLKSource() != 0x08);     /*0x08：PLL作为系统时钟 */	    
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
