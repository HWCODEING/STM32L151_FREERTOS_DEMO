/************************************************************************
* Copyright (C) 2020 Nercita
*
* �ļ����ƣ� led.h
* �ļ���ʶ��
* ����ժҪ�� led��غ�������
* ����˵����
* ��ǰ�汾��
* ��    �ߣ� woody
* ������ڣ� 2020.09.07
*
* �޸ļ�¼1��
*    �޸����ڣ�
*    �� �� �ţ�
*    �� �� �ˣ�
*    �޸����ݣ�
* �޸ļ�¼2����
************************************************************************/
#ifndef __LED_H
#define __LED_H
#include "MainConfig.h" 

#define  LED_AHBPeriph_PORT		RCC_AHBPeriph_GPIOA
#define  LED_GPIO_PORT			GPIOA
#define  LED_GPIO_PIN			GPIO_Pin_0

#define LED_RED PAout(0)// PA0	

void bsp_InitLED(void);//��ʼ��
void LED_Control(uint8_t valed);
void Reversal_LED(void);

#endif  /* _LED_H */

























