/************************************************************************
* Copyright (C) 2020 Nercita
*
* �ļ����ƣ� delay.h
* �ļ���ʶ��
* ����ժҪ�� delay��غ�������
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
#ifndef __DELAY_H
#define __DELAY_H 			   
#include "stm32l1xx.h"





void delay_init(void);
void delay_ms(uint32_t nms);
void delay_us(uint32_t nus);
void delay_xms(uint32_t nms);
void xPortSysTickHandler(void);

#endif  /* __DELAY_H */





























