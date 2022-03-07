/***************************************************************************
������ɹ�ѧϰʹ�ã�����������Ҳ������������;��������������飬��ӭ���罻��ָ��
Ӳ���汾��FreeLink STM32��·ֱ��������ư�V2.41
����оƬ��STM32F103RCT6
�������ƣ�STM32����ȫ���ƶ�С������--OLED��������
��������������OLED��ʾ�ַ������֡�ͼ��
������ߣ�ˮľ����@FreeLink
��ϵ�绰��15802781535
��ϵ���䣺357704597@qq.com
�޸�ʱ�䣺2019/09/16
����汾��V2.1
Copyright(C) �人��������˿Ƽ����޹�˾ 
All rights reserved
*****************************************************************************
�޸�˵����
��


*****************************************************************************/

#ifndef _OLED_H
#define _OLED_H

#include "sys.h"
#include "delay.h"



#define X_WIDTH 		128
#define Y_WIDTH 		64

//IO����
//IO��������
#define OLED_SDA_IN()  {GPIOC->CRH&=0XFFFFF0FF;GPIOC->CRH|=0X00000800;}
#define OLED_SDA_OUT() {GPIOC->CRH&=0XFFFFF0FF;GPIOC->CRH|=0X00000300;}

#define OLED_I2C_SCL        PCout(11) 
#define OLED_I2C_SDA        PCout(10)

#define READ_OLED_SDA      PCin(10)



//#define OLED_SCL(x)  PCout(11) = x
//#define OLED_SDA(x)  PCout(10) = x
//#define OLED_RST(x)  PCout(9) = x
//#define OLED_DC(x)   PCout(8) = x

void OLED_I2C_Init(void);
void OLED_I2C_Start(void);
void OLED_I2C_Stop(void);
u8 OLED_I2C_Wait_Ack(void);
void OLED_I2C_Send_Byte(u8 txd);

void OLED_Init(void);
void OLED_WriteDat(unsigned char dat);
void OLED_WriteCmd(unsigned char cmd);
void OLED_Set_Pos(unsigned char x,unsigned char y);
void OLED_Fill(unsigned char bmp_dat);



#endif

/*************************************END************************************/


