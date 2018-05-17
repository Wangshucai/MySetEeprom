#ifndef __LED_H
#define	__LED_H

#include "stm32f0xx.h"

#define LED1(val)    (val == 0)? GPIO_ResetBits(GPIOB,GPIO_Pin_9):GPIO_SetBits(GPIOB,GPIO_Pin_9)
#define LED2(val)    (val == 0)? GPIO_ResetBits(GPIOE,GPIO_Pin_0):GPIO_SetBits(GPIOE,GPIO_Pin_0)

void LED_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED1_Toggle(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED2_Toggle(void);

#endif /* __LED_H */
