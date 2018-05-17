#ifndef __MYIIC_H
#define __MYIIC_H
#include "sys.h"

#define IIC_SCL(val)    (val == 0)? GPIO_ResetBits(GPIOB,GPIO_Pin_6):GPIO_SetBits(GPIOB,GPIO_Pin_6)
#define IIC_SDA(val)    (val == 0)? GPIO_ResetBits(GPIOB,GPIO_Pin_7):GPIO_SetBits(GPIOB,GPIO_Pin_7)

#define READ_SDA   GPIOB->IDR  & GPIO_Pin_7 


//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	  
#endif
















