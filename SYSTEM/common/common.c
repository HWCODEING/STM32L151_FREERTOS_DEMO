/************************************************************************
* Copyright (C) 2020 Nercita
*
* �ļ����ƣ� common.c
* �ļ���ʶ��
* ����ժҪ�� common��غ�������
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
#include "common.h"
#include "MainConfig.h"


//STM32L151 ΨһID �������� ���һByteҪ�����ַ�����0X00��β����Ϊdebug��ӡʹ��
volatile uint8_t chipid[13];

/**************************************************************************
* ��������: GET_STM32_ID
* ��������: ��ȡ96λID
* �������: ��
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
static void GET_STM32_ID(uint8_t *idnum)
{
    for(uint8_t i = 0; i < 12; i++)  idnum[i] = *(uint8_t *)(CHIPID_STM32L1 + i);
}
/**************************************************************************
* ��������: get_chip_id
* ��������: ��ȡCHIP ID���浽ȫ������
* �������: ��
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
void get_chip_id(void)
{
    GET_STM32_ID((uint8_t *)chipid);					//��ȡΨһID
#if DEBUG_LOG_PRINTF
    DEBUG_LOG_PRF("CHIPID:");  							//���ڴ�ӡCHIPID
    for(uint8_t i = 0; i < 12; i++) printf("%02x", chipid[i]);
    printf("\r\n");
#endif
}

/**************************************************************************
* ��������: PreSleepProcessing
* ��������: ����͹���ģʽǰ��Ҫ���������,���Document˵��
* �������: ulExpectedIdleTime���͹���ģʽ����ʱ��
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
void vPreSleepProcessing(uint32_t ulExpectedIdleTime)
{
#if DEBUG_LOG_PRINTF
	//DEBUG_LOG_PRF("pre:%d",ulExpectedIdleTime);
#endif
    // ���Կ����ڴ˴�����ر�����ʱ������һ�����͹��� 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,DISABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,DISABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,DISABLE);	
	
	PWR_EnterSleepMode( PWR_Regulator_LowPower, PWR_SLEEPEntry_WFI ); //�͹���˯��ģʽ
}

/**************************************************************************
* ��������: PostSleepProcessing
* ��������: �˳��͹���ģʽ�Ժ���Ҫ���������
* �������: ulExpectedIdleTime���͹���ģʽ����ʱ��
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
void vPostSleepProcessing(uint32_t ulExpectedIdleTime)
{
#if DEBUG_LOG_PRINTF
	//DEBUG_LOG_PRF("post:%d",ulExpectedIdleTime);
#endif
	//�˳��͹���ģʽ�Ժ����Щ���رյ�����ʱ�ӣ��˴�ֻ����ʾ�Դ���
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);
}







