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
#ifndef __LEDTASK_H
#define __LEDTASK_H
#include "stm32l1xx.h"
#include "MainConfig.h" 




void Creat_LED_Task(void);
void LEDTaskSuspend(void);
void LEDTaskResume(void);
void LEDTaskResume(void);

#endif  /* __LEDTASK_H */


































