/***************************************************************************
������ɹ�ѧϰʹ�ã�����������Ҳ������������;��������������飬��ӭ���罻��ָ��
Ӳ���汾��FreeLink STM32��·ֱ��������ư�V2.41
����оƬ��STM32F103RCT6
�������ƣ�STM32����ȫ���ƶ�С������--������������
����������������������

*****************************************************************************
�޸�˵����
��


*****************************************************************************/


#include "key.h"
#include "delay.h"
						    
//������ʼ������
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
} 


/*************************************END************************************/
