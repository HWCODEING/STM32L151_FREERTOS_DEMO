/************************************************************************
* Copyright (C) 2020 Nercita
*
* �ļ����ƣ� MainConfig.h
* �ļ���ʶ��
* ����ժҪ�� MainConfig��غ�������
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
#ifndef __MAINCONFIG_H_
#define __MAINCONFIG_H_
#include "stm32l1xx.h"
/*****************************************
 * FREERTOS��ͷ�ļ�
 *****************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/*****************************************
 * String����ͷ�ļ�
 *****************************************/
#include "stdio.h"
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"

/*****************************************
 * System ͷ�ļ�
 *****************************************/
#include "common.h"
#include "delay.h"

/***********************************     �汾����    **************************************/
#define  STM32_VERSION "Nercita 2020/09/07 @ v1.0"

/***********************************    �����豸��   **************************************/
#define DEBUG_LOG_PRINTF 1  //����(1)/�ر�(0) ����log��ӡ 




/*********************************** ���� DEBUG ���� **************************************/
#ifdef DEBUG_LOG_PRINTF
#define DEBUG_LOG_PRF(fmt, args...)   \
        do{ \
			printf("DEBUG:(%s-%d)" fmt "\r\n", __func__, __LINE__, ##args); \
        }while(0)
#endif

/*********************************** ������غ꣨���ȼ��� **************************************/
//����FreeRTOSConfig.h�ĺ�configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY ���õ�ֵȷ��FreeRTOS�ܹ����������ȼ�
//NVIC�ж����ȼ�����ֵԽС�����ȼ�Խ�ߡ� �� FreeRTOS ���������ȼ��ǣ��������ȼ���ֵԽС���������ȼ�Խ�͡�
//������ʼ����
#define START_TASK_PRIO		     1          //�������ȼ�
#define START_STK_SIZE 		     256        //�����ջ��С
extern  TaskHandle_t StartTask_Handler;		//������


//��������1  ����״ָ̬ʾ������
#define Runing_State_PRIO		 5            //�������ȼ�
#define Runing_State_STK_SIZE    128         //�����ջ��С	
extern TaskHandle_t Runing_State_Handler;    //������

		
		
/*********************************** BSP��NVIC���ȼ� ���� **************************************/
//#define USART1_PRIO				14			//���ȼ�

		
		
/***********************************   ȫ�ֵ�������/����  **************************************/
extern volatile uint8_t chipid[13];  //STM32L151 ΨһID ��������




#endif  /* __MAINCONFIG_H_ */



































