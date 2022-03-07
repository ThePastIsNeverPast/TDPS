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

#ifndef _OLED_USER_H
#define _OLED_USER_H

#include "sys.h"
#include "oled.h"

#define DARK		0		//OLED�����ص㲻��
#define LIGHT		1		//OLED�����ص���

extern unsigned char OLED_Buffer[8][128];						//OLED��ʾ����

void OLED_Draw_FreeLink(void);											//��ʾLogo
void OLED_Refresh_GDRAM(unsigned char displayxx);		//ˢ����ʾ
void OLED_Refresh_AllGDRAM(void);										//ȫ��ˢ��ʾ

void OLED_Put12x24Char(u8 x, u8 y, u8 ch,u8 Col);		//��ʾ12x24����Ӣ���ַ�
void OLED_Put10x20Char(u8 x, u8 y, u8 ch,u8 Col);		//��ʾ10x20����Ӣ���ַ�
void OLED_Put8x16Char(u8 x, u8 y, u8 ch,u8 Col);		//��ʾ8x16����Ӣ���ַ�
void OLED_Put7x14Char(u8 x, u8 y, u8 ch,u8 Col);		//��ʾ7x14����Ӣ���ַ�
void OLED_Put6x12Char(u8 x, u8 y, u8 ch,u8 Col);		//��ʾ6x12����Ӣ���ַ�
void OLED_Put5x7Char(u8 x, u8 y, u8 ch,u8 Col);			//��ʾ5x7����Ӣ���ַ�
void OLED_Put24x24CNstr(u8 x,u8 y,u8 *Chstr,u8 Col);//��ʾ���24x24���� �� 12x24Ӣ���ַ�
void OLED_Put20x20CNstr(u8 x,u8 y,u8 *Chstr,u8 Col);//��ʾ���20x20���� �� 10x20Ӣ���ַ�
void OLED_Put16x16CNstr(u8 x,u8 y,u8 *Chstr,u8 Col);//��ʾ���16x16���� �� 8x16Ӣ���ַ�
void OLED_Put14x14CNstr(u8 x,u8 y,u8 *Chstr,u8 Col);//��ʾ���14x14���� �� 7x14Ӣ���ַ�
void OLED_Put12x12CNstr(u8 x,u8 y,u8 *Chstr,u8 Col);//��ʾ���12x12���� �� 6x12Ӣ���ַ�
void OLED_Put5x7ENstr(u8 x,u8 y,u8 *ENstr,u8 Col);	//��ʾ���5x7Ӣ���ַ�

void OLED_DrawDot(u8 xx,u8 yy,u8 color);						//����
void OLED_DrawLine_X(u8 X0,u8 X1,u8 Y,u8 Color);		//������
void OLED_DrawLine_Y(u8 X,u8 Y0,u8 Y1,u8 Color);		//������
void OLED_DrawLine(short int X0, short int Y0, short int X1 ,short int Y1, short int Color);//��б��
void OLED_DrawRectangle(u8 X0,u8 Y0,u8 X1,u8 Y1,u8 Color);		//������
void OLED_DrawCircle(short int X0,short int Y0,short int R);	//��Բ
void OLED_FillRectangle(u8 X0,u8 Y0,u8 X1,u8 Y1,u8 Color);		//�������
void OLED_ClearBuffer(unsigned char Col);											//�����ʾ����

void OLED_Put6x12Num(u8 xx,u8 yy,int Num,u8 bitlen,u8 Col);		//��ʾ6x12��λ����
void OLED_Put6x12Num1dot(u8 xx,u8 yy,int Num,u8 Col);					//��ʾ6x12��1λС���������
void OLED_Put5x7Num1dot(u8 xx,u8 yy,int Num);									//��ʾ5x7��1λС���������

#endif

/*************************************END************************************/



