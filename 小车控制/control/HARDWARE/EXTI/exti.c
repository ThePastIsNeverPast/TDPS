#include "exti.h"
#include "delay.h"

	   
//�ⲿ�жϳ�ʼ������
//��ʼ��PA0/PE2/PE3/PE4Ϊ�ж�����.
void EXTIX_Init(void)
{
	RCC->APB2ENR|=1<<3;    //ʹ��PORTBʱ��	   	 
	GPIOB->CRL&=0XFFFFFF00; 
	GPIOB->CRL|=0X00000088;//PB0,1 ����   	 
  GPIOB->ODR|=0x03;      //PB0,1 ���� 

	Ex_NVIC_Config(GPIO_B,0,FTIR); 			//�½��ش���
//	Ex_NVIC_Config(GPIO_B,1,FTIR); 			//�½��ش���

	MY_NVIC_Init(2,3,EXTI0_IRQn,2);	//��ռ2�������ȼ�3����2
//	MY_NVIC_Init(2,1,EXTI1_IRQn,2);	//��ռ2�������ȼ�2����2	   
// 	MY_NVIC_Init(2,1,EXTI3_IRQn,2);	//��ռ2�������ȼ�1����2	   
// 	MY_NVIC_Init(2,0,EXTI4_IRQn,2);	//��ռ2�������ȼ�0����2	   
}












