/**********************************************************************************/
#include "timer.h"

/**********************��ʱ��1�ж����ú���*****************************************/
void TIM1_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  													
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}



/************************��ʱ�����ú���************************************************/
/************************��ʱ�����ú���************************************************/
void TIM1_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 , ENABLE);
    
	  TIM_DeInit(TIM1);											/* ����������ʱ�� */

    TIM_TimeBaseStructure.TIM_Period=2505;		 				/* �Զ���װ�ؼĴ������ڵ�ֵ(����ֵ) */
    TIM_TimeBaseStructure.TIM_Prescaler=71;						/* ʱ��Ԥ��Ƶ�� 72M/72 */
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		/* �ⲿʱ�Ӳ�����Ƶ */
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 	/* ���ϼ���ģʽ */
  	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    TIM_ClearFlag(TIM1, TIM_FLAG_Update);						/* �������жϱ�־ */

    TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);					/* �����жϴ���*/    
	
	  TIM_Cmd(TIM1,DISABLE);									    /* �رն�ʱ�� */ 
}

/**************************************************************************************/

/************************��ʱ��6���ú���***********************************************/

//������ʱ��6�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM6_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<4;//TIM6ʱ��ʹ��    
 	TIM6->ARR=arr;  	//�趨�������Զ���װֵ//�պ�1ms    
	TIM6->PSC=psc;  	//Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��	  
	TIM6->DIER|=1<<0;   //��������ж�	 
	TIM6->CR1|=0x01;    //ʹ�ܶ�ʱ��3
  MY_NVIC_Init(1,3,TIM6_IRQn,2);//��ռ1�������ȼ�3����2									 
}
void TIM7_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<5;		//TIM7ʱ��ʹ��    
 	TIM7->ARR=arr;  			//�趨�������Զ���װֵ  
	TIM7->PSC=psc;  			//Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��	  
	TIM7->DIER&=~(1<<0);  //����������ж�	 
	TIM7->CR1&=~(0x01);   //��ʹ�ܶ�ʱ��3								 
}

/**************************************************************************************/
/************************��ʱ����ʼ������*********************************************/
void Timer_Init(void)
{
	TIM1_NVIC_Configuration();
	TIM1_Configuration();
}
/**************************************************************************************/
/************************������ʱ������************************************************/
void Timer_ON(void)
{	
	  TIM_Cmd(TIM1,ENABLE);	
}
/**************************************************************************************/
/************************�رն�ʱ������************************************************/
void Timer_OFF(void)
{	
	
	TIM_Cmd(TIM1,DISABLE);
}
/**************************************************************************************/

