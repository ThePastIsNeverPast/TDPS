/***************************************************************************
������ɹ�ѧϰʹ�ã�����������Ҳ������������;��������������飬��ӭ���罻��ָ��
Ӳ���汾��FreeLink STM32��·ֱ��������ư�V2.41
����оƬ��STM32F103RCT6
�������ƣ�STM32����ȫ���ƶ�С������--UI�������
����������UI�л����棬���������˻���������


*****************************************************************************/


#ifndef _UI_H_
#define	_UI_H_

#include "sys.h"
#include "usart.h"
#include "led.h"
#include "delay.h"
#include "timer.h"
#include "ps2.h"
#include "beep.h"
#include "servor.h"
#include "motor.h"
#include "adc.h"
#include "key.h"
#include "oled.h"
#include "control_app.h"
#include "oled_user.h"
#include "Control.h"
#include "encoder.h"
#include "ULN.h"
#include "Traversing.h"
#include "servor.h"



extern unsigned short int Keytimes;					//��������ʱ�����
extern unsigned char Kaysta;								//����״̬����
extern unsigned char WorkMode;							//����ģʽ����
extern unsigned char Control_Flag;	
extern unsigned int Voltage;										//��ص�ѹ��������λ0.1V
extern char Menux;													//�˵�����
extern unsigned short int AdjustAngle_Flag;	//�Ƕ�У׼��־λ
extern short int Lang_x;										//��������
extern unsigned char UI_Display_Flag;				//��ǽ���д��һ��
extern short int PS2_CH[3];
//extern short int	VoltLowWarn;							//�͵�ѹ����ֵ
//extern unsigned short int VoltLowTimes;					//��ѹ�ͼ�����
void Display_Menux(char Menuxx);
void Ps2_Mode(void);
void Blutooth_Mode(void);
void Avoid_Mode(void);
void Tracking_Mode(void);
u8 Standby_Mode(void);
void Line_Mode(void);

#endif


/*************************************END************************************/

