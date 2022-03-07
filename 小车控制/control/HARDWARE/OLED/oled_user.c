/***************************************************************************
������ɹ�ѧϰʹ�ã�����������Ҳ������������;��������������飬��ӭ���罻��ָ��
Ӳ���汾��FreeLink STM32��·ֱ��������ư�V2.41
����оƬ��STM32F103RCT6
�������ƣ�STM32����ȫ���ƶ�С������--OLED��������
��������������OLED��ʾ�ַ������֡�ͼ��

*****************************************************************************/



#include "oled_user.h"
#include "stdlib.h"
#include "Bitmap.h"
#include "cn_code.h" 
#include "en_code.h" 


unsigned char OLED_Buffer[8][128]={0}; 	//OLED��ʾ����

//***************************��Ļˢ����ʾ***************************
void OLED_Refresh_GDRAM(unsigned char displayxx)
{
	unsigned char disjj;
	OLED_Set_Pos(0,displayxx);
	for(disjj=0;disjj<128;disjj++)
	{
		OLED_WriteDat(OLED_Buffer[displayxx][disjj]);
	}	
}

//***************************ȫ��ˢ����ʾ***************************
void OLED_Refresh_AllGDRAM(void)
{
	OLED_Refresh_GDRAM(0);OLED_Refresh_GDRAM(1);
	OLED_Refresh_GDRAM(2);OLED_Refresh_GDRAM(3);
	OLED_Refresh_GDRAM(4);OLED_Refresh_GDRAM(5);
	OLED_Refresh_GDRAM(6);OLED_Refresh_GDRAM(7);	
}

//***************************��ʾLogo***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
void OLED_Draw_FreeLink(void)
{
	unsigned char i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<64;j++)
		{
			OLED_Buffer[i][j]=BMP_FreeLink[i][j];
		}
	}
}
//***************************��ʾ12x24�ַ�***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//ch,	��ʾ���ַ�
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put12x24Char(unsigned char x, unsigned char y, unsigned char ch,unsigned char Col)
{  
	unsigned char  font_dat;
	unsigned char  i,j,k;
	unsigned char col1,col0;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	if( (ch<0x20) || (ch>0x7f) ) ch = 0x20;   
	ch=ch-0x20;
	for(k=0;k<3;k++)
	{
		for(i=0; i<12; i++)
		{   
			font_dat = ASCII12X24[ch][k*12+i];//��ȡ�ֿ��������
			for(j=0; j<8; j++)//д��8����
			{  
				if(font_dat&0x80)	OLED_DrawDot(x+i, y+j+k*8, col0);   
				else 							OLED_DrawDot(x+i, y+j+k*8, col1); 
				font_dat=font_dat<<1;
			} 	
		}
	}
}
//***************************��ʾ10x20�ַ�***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//ch,	��ʾ���ַ�
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put10x20Char(unsigned char x, unsigned char y, unsigned char ch,unsigned char Col)
{  
	unsigned char  font_dat;
	unsigned char  i,j,k;
	unsigned char col1,col0;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	if( (ch<0x20) || (ch>0x7f) ) ch = 0x20;   
	ch=ch-0x20;
	for(k=0;k<3;k++)
	{
		for(i=0; i<10; i++)
		{   
			font_dat = ASCII10X20[ch][k*10+i];//��ȡ�ֿ��������
			for(j=0; j<8; j++)//д��8����
			{  
				if(font_dat&0x80)	OLED_DrawDot(x+i, y+j+k*8, col0);   
				else 							OLED_DrawDot(x+i, y+j+k*8, col1); 
				font_dat=font_dat<<1;
			} 	
		}
	}
}
//***************************��ʾ8x16�ַ�***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//ch,	��ʾ���ַ�
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put8x16Char(unsigned char x, unsigned char y, unsigned char ch,unsigned char Col)
{  
	unsigned char  font_dat;
	unsigned char   i, j;
	unsigned char col1,col0;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	if( (ch<0x20) || (ch>0x7f) ) ch = 0x20;   
	ch=ch-0x20;
	for(i=0; i<16; i++)
	{   
			font_dat = ASCII8X16[ch][i];//��ȡ�ֿ��������
			for(j=0; j<8; j++)//д��8����
			{  
				if(font_dat&0x80)	OLED_DrawDot(x+j, y+i, col0);   
				else 							OLED_DrawDot(x+j, y+i, col1); 
				font_dat=font_dat<<1;
			} 	
	}
}

//***************************��ʾ7x14�ַ�***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//ch,	��ʾ���ַ�
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put7x14Char(unsigned char x, unsigned char y, unsigned char ch,unsigned char Col)
{  
	unsigned char  font_dat;
	unsigned char   i, j;
	unsigned char col1,col0;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	if( (ch<0x20) || (ch>0x7f) ) ch = 0x20;   
	ch=ch-0x20;
	for(i=0; i<14; i++)
	{   
			font_dat = ASCII7X14[ch][i];//��ȡ�ֿ��������
			for(j=0; j<7; j++)//д��7����
			{  
				if(font_dat&0x80)	OLED_DrawDot(x+j, y+i, col0);   
				else 							OLED_DrawDot(x+j, y+i, col1); 
				font_dat=font_dat<<1;
			} 	
	}
}

//***************************��ʾ6x12�ַ�***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//ch,	��ʾ���ַ�
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put6x12Char(unsigned char x, unsigned char y, unsigned char ch,unsigned char Col)
{ 
	u8 font_dat,j,i;
	unsigned char col1,col0;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}
	 
	if( (ch<0x20) || (ch>0x7f) ) ch = 0x20;   
	ch=ch-0x20;
	for(i=0; i<12; i++)
	{   
			font_dat = ASCII6X12[ch][i];//��ȡ�ֿ��������
			for(j=0; j<6; j++)//д��6����
			{  
				if(font_dat&0x80)	OLED_DrawDot(x+j, y+i, col0);   
				else 							OLED_DrawDot(x+j, y+i, col1); 
				font_dat=font_dat<<1;
			} 	
	}
}
//***************************��ʾ5x7�ַ�***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//ch,	��ʾ���ַ�
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put5x7Char(unsigned char x, unsigned char y, unsigned char ch,unsigned char Col)
{
	u8 temp,j,i;
	u16 y0=y;
	unsigned char col1,col0;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}
	 
	if( (ch<0x20) || (ch>0x7f) ) ch = 0x20; 
	ch=ch-0x20;

	for(i=0;i<5;i++)
	{   
		temp=	ASCII5x7[ch][i];
		y=y0;
		for(j=0;j<7;j++)
		{	
			if(temp&0x01)	OLED_DrawDot(x+i,y+j,col0);
			else 					OLED_DrawDot(x+i,y+j,col1);
			temp>>=1;
		}  	 
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***************************��ʾ24x24���֡�12x24�ַ���***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//*Chstr,	��ʾ�ĺ��֡��ַ�����
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put24x24CNstr(u8 x,u8 y,u8 *Chstr,u8 Col)
{
  unsigned char m,c1,c2,i,j,add,length;
	unsigned char tmp_char;
	unsigned char col1,col0;
	m=0;length=0;
	while(Chstr[length]!=0)length++;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	do
	{
		c1=Chstr[m];		
		c2=Chstr[m+1];   
		if(c1>128)//�Ǻ���
		{
			for(j=0;j<sizeof(hanzi_24x24)/sizeof(hanzi_24x24[0]);j++)  //
			{
					if(c1==hanzi_24x24[j].Index[0]&&c2==hanzi_24x24[j].Index[1]) break; //
			}
			for(i=0;i<24;i++)
			{

				tmp_char=hanzi_24x24[j].Msk[i*3];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
				
				tmp_char=hanzi_24x24[j].Msk[i*3+1];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add+8,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
				tmp_char=hanzi_24x24[j].Msk[i*3+2];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add+16,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
			}
      m+=2;x+=24;	
		}
		else //��Ӣ���ַ�
		{
			OLED_Put12x24Char(x,y,c1,Col);//��ʾӢ���ַ�
			m++;x+=12;
		}
	}
	while(m<length);
}
//***************************��ʾ20x20���֡�12x24�ַ���***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//*Chstr,	��ʾ�ĺ��֡��ַ�����
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put20x20CNstr(u8 x,u8 y,unsigned char *Chstr,u8 Col)
{
  unsigned char m,c1,c2,i,j,add,length;
	unsigned char tmp_char;
	unsigned char col1,col0;
	m=0;length=0;
	while(Chstr[length]!=0)length++;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	do
	{
		c1=Chstr[m];		
		c2=Chstr[m+1];   
		if(c1>128)//�Ǻ���
		{
			for(j=0;j<sizeof(hanzi_20x20)/sizeof(hanzi_20x20[0]);j++)  //
			{
					if(c1==hanzi_20x20[j].Index[0]&&c2==hanzi_20x20[j].Index[1]) break; //
			}
			for(i=0;i<20;i++)
			{

				tmp_char=hanzi_20x20[j].Msk[i*3];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
				
				tmp_char=hanzi_20x20[j].Msk[i*3+1];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add+8,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
				tmp_char=hanzi_20x20[j].Msk[i*3+2];
				for (add=0;add<4;add++)
				{
					OLED_DrawDot(x+add+16,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
			}
      m+=2;x+=20;	
		}
		else //��Ӣ���ַ�
		{
			OLED_Put10x20Char(x,y,c1,Col);//��ʾӢ���ַ�
			m++;x+=10;
		}
	}
	while(m<length);
}
//***************************��ʾ1616���֡�8x16�ַ���***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//*Chstr,	��ʾ�ĺ��֡��ַ�����
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put16x16CNstr(u8 x,u8 y,unsigned char *Chstr,u8 Col)
{
  unsigned char m,c1,c2,i,j,add,length;
	unsigned char tmp_char;
	unsigned char col1,col0;
	m=0;length=0;
	while(Chstr[length]!=0)length++;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	do
	{
		c1=Chstr[m];		
		c2=Chstr[m+1];   
		if(c1>128)//
		{
			for(j=0;j<sizeof(hanzi_16x16)/sizeof(hanzi_16x16[0]);j++)  //
			{
					if(c1==hanzi_16x16[j].Index[0]&&c2==hanzi_16x16[j].Index[1]) break; //
			}
			for(i=0;i<16;i++)
			{

				tmp_char=hanzi_16x16[j].Msk[i*2];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
				
				tmp_char=hanzi_16x16[j].Msk[i*2+1];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add+8,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
			}
      m+=2;x+=16;	
		}
		else //��Ӣ���ַ�
		{
			OLED_Put8x16Char(x,y,c1,Col);//��ʾӢ���ַ�
			m++;x+=8;
		}
	}
	while(m<length);
}

//***************************��ʾ1414���֡�7x14�ַ���***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//*Chstr,	��ʾ�ĺ��֡��ַ�����
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put14x14CNstr(u8 x,u8 y,unsigned char *Chstr,u8 Col)
{
  unsigned char m,c1,c2,i,j,add,length;
	unsigned char tmp_char;
	unsigned char col1,col0;
	m=0;length=0;
	while(Chstr[length]!=0)length++;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	do
	{
		c1=Chstr[m];		
		c2=Chstr[m+1];   
		if(c1>128)//
		{
			for(j=0;j<sizeof(hanzi_14x14)/sizeof(hanzi_14x14[0]);j++)  //
			{
					if(c1==hanzi_14x14[j].Index[0]&&c2==hanzi_14x14[j].Index[1]) break; //
			}
			for(i=0;i<14;i++)
			{

				tmp_char=hanzi_14x14[j].Msk[i*2];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
				
				tmp_char=hanzi_14x14[j].Msk[i*2+1];
				for (add=0;add<6;add++)
				{
					OLED_DrawDot(x+add+8,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
			}
      m+=2;x+=14;	
		}
		else //��Ӣ���ַ�
		{
			OLED_Put7x14Char(x,y,c1,Col);//��ʾӢ���ַ�
			m++;x+=7;
		}
	}
	while(m<length);
}

//***************************��ʾ12x12���֡�6x12�ַ���***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,	��ʾ��X������
//y,	��ʾ��Y������
//*Chstr,	��ʾ�ĺ��֡��ַ�����
//Col,��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put12x12CNstr(u8 x,u8 y,unsigned char *Chstr,u8 Col)
{
  unsigned char m,c1,c2,i,j,add,length;
	unsigned char tmp_char;
	unsigned char col1,col0;
	m=0;length=0;
	while(Chstr[length]!=0)length++;
	if(Col==LIGHT)	{	col0=LIGHT;col1=DARK;	}
	else						{	col0=DARK;col1=LIGHT;	}

	do
	{
		c1=Chstr[m];		
		c2=Chstr[m+1];   
		if(c1>128)//�Ǻ��֣���ʾ����
		{
			//�����������ֿ��е�λ��
			for(j=0;j<sizeof(hanzi_12x12)/sizeof(hanzi_12x12[0]);j++)  
			{
					if(c1==hanzi_12x12[j].Index[0]&&c2==hanzi_12x12[j].Index[1]) break;//�ҵ���Ӧ�ĺ���
			}
			//��ʾ����
			for(i=0;i<12;i++)
			{
				tmp_char=hanzi_12x12[j].Msk[i*2];
				for (add=0;add<8;add++)
				{
					OLED_DrawDot(x+add,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
				
				tmp_char=hanzi_12x12[j].Msk[i*2+1];
				for (add=0;add<4;add++)
				{
					OLED_DrawDot(x+add+8,y+i,(tmp_char&0x80) ? col0:col1);//д����ɫֵ
					tmp_char=tmp_char<<1;
				}
			}
      m+=2;x+=12;	
		}
		else //���Ǻ��֣���ʾ�ַ�
		{
			OLED_Put6x12Char(x,y,c1,Col);//�ַ���ʾ
			m++;
			x+=6;
		}
	}
	while(m<length);
}

//***************************��ʾ5x7�ַ���***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//x,			��ʾ��X������
//y,			��ʾ��Y������
//*ENstr,	��ʾ�ĺ��ַ�����
//Col,		��ʾ����ɫ��1,����,�����ɫ��������ɫ��0,����,�����ɫ��������ɫ
void OLED_Put5x7ENstr(u8 x,u8 y,unsigned char *ENstr,u8 Col)
{
	while(*ENstr!='\0')
	{
			OLED_Put5x7Char(x,y,*ENstr,Col);
			*ENstr++;
			x+=6;
	}
}

//***************************����***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//xx,			��ʾ��X������
//yy,			��ʾ��Y������
//color,	��ʾ����ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_DrawDot(unsigned char xx,unsigned char yy,unsigned char color)
{
	unsigned char xlabel,xlabel_bit;
	unsigned char Read_Dat; 		//��LCD�е�����
	if(xx>=128) 	return;
	if(yy>=64) 	return;
	xlabel=yy>>3;								//ȡ8*8�׵�ַ
	xlabel_bit=yy & 0x07;				//����õ���16λ���ݵĵڼ�λ	
	Read_Dat=OLED_Buffer[xlabel][xx];
	switch(color)
	{
		case 0:Read_Dat &= (~(0x01<<(xlabel_bit)));break;	//����� 
		case 1:Read_Dat |= (0x01<<(xlabel_bit));break;		//��Ϳ�� 
		case 2:Read_Dat ^= (0x01<<(xlabel_bit));break;		//����ת 
		default:break;
	}
	OLED_Buffer[xlabel][xx]=Read_Dat;
}

//***************************������***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//X0,			���ߵ���ʼX������
//X1,			���ߵĽ���Y������
//Y,			���ߵ�Y������
//Color,	��ʾ����ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_DrawLine_X(unsigned char X0,unsigned char X1,unsigned char Y,unsigned char Color)//�� X��ˮƽ��
{
	unsigned char temp;
	if (X0>X1)
	{
	   temp=X1;
	   X1=X0;
	   X0=temp;
	}
	for(;X0<X1;X0++)
	{
   	OLED_DrawDot(X0,Y,Color);
	}
}

//***************************������***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//X,			���ߵ�X������
//Y0,			���ߵ���ʼY������
//Y1,			���ߵĽ���Y������
//Color,	���ߵ���ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_DrawLine_Y(unsigned char X,unsigned char Y0,unsigned char Y1,unsigned char Color)//�� Y��ˮƽ��
{
	unsigned char temp;
	if (Y0>Y1)
	{
	   temp=Y1;
	   Y1=Y0;
	   Y0=temp;
	}

	for(;Y0<Y1;Y0++)
	{
   		OLED_DrawDot(X,Y0,Color);
	}
}

//***************************��������***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//X,			�ߵ���ʼX������
//X,			�ߵĽ���X������
//Y0,			�ߵ���ʼY������
//Y1,			�ߵĽ���Y������
//Color,	�ߵ���ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_DrawLine(short int X0, short int Y0, short int X1 ,short int Y1, short int Color)
{
    short int t, distance;      /*������Ļ��С�ı��������(���Ϊint��)*/
    short int x = 0 , y = 0 , delta_x, delta_y ;
    short int incx, incy ;

    delta_x = X1 - X0 ;
    delta_y = Y1 - Y0 ;

    if( delta_x > 0 )
    {
        incx = 1;
    }
    else if( delta_x == 0 )
    {
        OLED_DrawLine_Y( X0, Y0, Y1, Color ) ;
        return ;
    }
    else
    {
        incx = -1 ;
    }
    if( delta_y > 0 )
    {
        incy = 1 ;
    }
    else if(delta_y == 0 )
    {
        OLED_DrawLine_X( X0, X1, Y0, Color ) ;    
        return ;
    }
    else
    {
        incy = -1 ;
    }

    delta_x = abs( delta_x );    
    delta_y = abs( delta_y );
    if( delta_x > delta_y )
    {
        distance = delta_x ;
    }
    else
    {
        distance = delta_y ; 
    }
    OLED_DrawDot( X0, Y0, Color ) ;    
		/* Draw Line*/
    for( t = 0 ; t <= distance+1 ; t++ )
    {
        OLED_DrawDot( X0, Y0, Color ) ;
        x += delta_x ;
        y += delta_y ;
        if( x > distance )
        {
           x -= distance ;
           X0 += incx ;
        }
        if( y > distance )
        {
           y -= distance ;
           Y0 += incy ;
        }
    }
}

//***************************������***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//X0,			���ε����϶˵�X������
//Y0,			���ε����϶˵�Y������
//X1,			���ε����¶˵�X������
//Y1,			���ε����¶˵�Y������
//Color,	���ε���ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_DrawRectangle(unsigned char X0,unsigned char Y0,unsigned char X1,unsigned char Y1,unsigned char Color)//������
{
	if(X0>X1 || Y0>Y1) return;//���겻���ϣ�ֱ�ӷ���
	OLED_DrawLine(X0,Y0,X1,Y0,Color);
	OLED_DrawLine(X0,Y1,X1,Y1,Color);
	OLED_DrawLine(X0,Y0,X0,Y1,Color);
	OLED_DrawLine(X1,Y0,X1,Y1,Color);
}

//***************************��Բ***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//X0,		Բ��X������
//Y0,		Բ��Y������
//R,	  Բ�İ뾶
void OLED_DrawCircle(short int X0,short int Y0,short int R)	  //��Բ
{
	short int aa,bb;
	short int dii;
	if(R>31||R==0) return;
	aa=0;
	bb=R;
	dii=3-2*R;//�ж��¸���λ�õı�־
	while(aa<=bb)
	{
		OLED_DrawDot(X0-bb,Y0-aa,LIGHT);//3
		OLED_DrawDot(X0+bb,Y0-aa,LIGHT);//0
		OLED_DrawDot(X0-aa,Y0+bb,LIGHT);//1
		OLED_DrawDot(X0-bb,Y0-aa,LIGHT);//7
		OLED_DrawDot(X0-aa,Y0-bb,LIGHT);//2
		OLED_DrawDot(X0+bb,Y0+aa,LIGHT);//4
		OLED_DrawDot(X0+aa,Y0-bb,LIGHT);//5
		OLED_DrawDot(X0+aa,Y0+bb,LIGHT);//6
		OLED_DrawDot(X0-bb,Y0+aa,LIGHT);
		aa++;
//******ʹ��bresenham�㷨��Բ****/
		if(dii<0)
			dii+=4*aa+6;
		else
		{
			dii+=10+4*(aa-bb);
			bb--;
		}
		OLED_DrawDot(X0+aa,Y0+bb,LIGHT);
	}
}
//***************************�������***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//X0,			�����������϶˵�X������
//Y0,			�����������϶˵�Y������
//X1,			�����������¶˵�X������
//Y1,			�����������¶˵�Y������
//Color,	����������ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_FillRectangle(unsigned char X0,unsigned char Y0,unsigned char X1,unsigned char Y1,unsigned char Color)//�������
{
	unsigned char i,j;
	if(X0>X1 || Y0>Y1) return;//���겻���ϣ�ֱ�ӷ���
	for(i=X0;i<X1;i++)
	{
		for(j=Y0;j<Y1;j++) 
			OLED_DrawDot(i,j,Color);
	}
}

//***************************����Դ�***************************
//Col,	�������ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_ClearBuffer(unsigned char Col)
{
	unsigned char xxi,yyi;
	for(xxi=0;xxi<8;xxi++)
		for(yyi=0;yyi<128;yyi++)
			OLED_Buffer[xxi][yyi]=Col;
}

//***************************��ʾ6x12��λ����***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//xx,			��ʾ��X������
//yy,			��ʾ��Y������
//Num,		��ʾ�����֣�
//bitlen,	��ʾ�����ֵ�λ����
//Col,		��ʾ����ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_Put6x12Num(unsigned char xx,unsigned char yy,int Num,unsigned char bitlen,u8 Col)
{
	unsigned char String[6],bitx=0;
	if(Num<0)
	{
		Num=-Num;
		String[bitx++]='-';
	}
	if(Num>999) 	String[bitx++]=Num/1000%10+48;//��ֵ��4λ��
	if(Num>99) 		String[bitx++]=Num/100%10+48;	//��ֵ��5λ��
	if(Num>9) 		String[bitx++]=Num/10%10+48;	//��ֵ��2λ��
	String[bitx++]=Num%10+48;										//��ֵ��1λ��
	
	for(;bitx<bitlen;bitx++)
	{
		String[bitx]=' ';
	}
	String[bitx]='\0';
	
	OLED_Put12x12CNstr(xx,yy,String,Col);
}

//***************************��ʾ6x12��1λС���������***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//xx,			��ʾ��X������
//yy,			��ʾ��Y������
//Num,		��ʾ�����֣�
//Col,		��ʾ����ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_Put6x12Num1dot(unsigned char xx,unsigned char yy,int Num,unsigned char Col)
{
	unsigned char String[7],bitx=0;
	if(Num<0)
	{
		Num=-Num;
		String[bitx++]='-';
	}
	if(Num>999) 	String[bitx++]=Num/1000%10+48;	//��ֵ��4λ��
	if(Num>99) 		String[bitx++]=Num/100%10+48;		//��ֵ��5λ��
	String[bitx++]=Num/10%10+48;									//��ֵ��2λ��
	String[bitx++]='.';
	String[bitx++]=Num%10+48;											//��ֵ��1λ��
	
	for(;bitx<5;bitx++)
	{
		String[bitx]=' ';
	}
	String[bitx]='\0';
	
	OLED_Put12x12CNstr(xx,yy,String,Col);
}

//***************************��ʾ5x7��1λС���������***************************
//ע�⣺�ú���ֻ������ʾ��������ݣ�����ֱ������Ļ����ʾ����������������������������
//����OLED_Refresh_AllGDRAM()������ȫ��ˢ�º������ʾ����
//xx,			��ʾ��X������
//yy,			��ʾ��Y������
//Num,		��ʾ�����֣�
//Col,		��ʾ����ɫ��1,��ʾ��ɫ��0,��ʾ��ɫ
void OLED_Put5x7Num1dot(unsigned char xx,unsigned char yy,int Num)
{
	unsigned char String[7],bitx=0;
	if(Num<0)
	{
		Num=-Num;
		String[bitx++]='-';
	}
	if(Num>999) 	String[bitx++]=Num/1000%10+48;	//��ֵ��4λ��
	if(Num>99) 		String[bitx++]=Num/100%10+48;	//��ֵ��5λ��
	String[bitx++]=Num/10%10+48;	//��ֵ��2λ��
	String[bitx++]='.';
	String[bitx++]=Num%10+48;		//��ֵ��1λ��
	
	for(;bitx<4;bitx++)
	{
		String[bitx]=' ';
	}
	String[bitx]='\0';
	
	OLED_Put5x7ENstr(xx,yy,String,LIGHT);
}

/*************************************END************************************/


