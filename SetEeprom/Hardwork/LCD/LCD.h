
#ifndef _LCD_H
#define _LCD_H

#include "stm32f0xx.h"

//#define LED_ON                    (GPIOC->BSRR = Pin_11)
//#define LED_OFF                   (PORT_LED->BRR  = PIN_LED)

#define LCD_DB GPIOD
#define RS_1 GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define RS_0 GPIO_ResetBits(GPIOB,GPIO_Pin_5)

#define WR_1 GPIO_SetBits(GPIOB,GPIO_Pin_4)
#define WR_0 GPIO_ResetBits(GPIOB,GPIO_Pin_4)

#define RES_1 GPIO_SetBits(GPIOC,GPIO_Pin_11)
#define RES_0 GPIO_ResetBits(GPIOC,GPIO_Pin_11)


#define CS_1 GPIO_SetBits(GPIOC,GPIO_Pin_12)
#define CS_0 GPIO_ResetBits(GPIOC,GPIO_Pin_12)

#define RD_1 GPIO_SetBits(GPIOB,GPIO_Pin_3)
#define RD_0 GPIO_ResetBits(GPIOB,GPIO_Pin_3)

#define BACK GPIO_SetBits(GPIOB,GPIO_Pin_8)
//初始化
void LCD_Init(void);
void LCD_ST7565_INIT(void);
void ClearRAM(void);
//忙检测
void LCD_Busy(void);
//写指令
void LCD_WriteCmd(u8 cmd);
//写数据
void LCD_WriteData(u8 dat);
//清屏
void LCD_CleanSc(void);
//设置坐标
void LCD_SetPosition(unsigned char row,unsigned char column);
//设置GPIO为输入模式
void SetDataGPIO_In(void);
//设置GPIO为输出模式
void SetDataGPIO_Out(void);
void LCD12864_Data(u8 data);
void clrscr(void);//清屏
void disp_str(u8 *p,u8 uCol,u8 uPage);
#endif
