/************************************************************************
* Copyright (C) 2020 Nercita
*
* �ļ����ƣ� led.c
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
#include "led.h"


/**************************************************************************
* ��������: LED_Init
* ��������: LED I/O��ʼ������
* �������: ��
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
void bsp_InitLED(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHBPeriphClockCmd(LED_AHBPeriph_PORT, ENABLE);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_400KHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN;

    GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);
}

/**************************************************************************
* ��������: LED_Control
* ��������: ����LED�������
* �������: 1 / 0
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
void LED_Control(uint8_t valed)
{
    if(valed == 1)	GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);  	//�����
    if(valed == 0)	GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);	//�����
}

/**************************************************************************
* ��������: Reversal_LED
* ��������: GPIO��ת
* �������: ��
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
void Reversal_LED(void)
{
    LED_RED = !LED_RED;
}












