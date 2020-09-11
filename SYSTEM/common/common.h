/************************************************************************
* Copyright (C) 2020 Nercita
*
* �ļ����ƣ� common.h
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
#ifndef __COMMON_H
#define __COMMON_H
#include "stm32l1xx.h"
#include "delay.h"

/*********************************** ��ȡSTM32 ID ��ַ **************************************/
#define CHIPID_STM32L1		0x1FF80050   //L1 ϵ�е�CHIP ID  ��ַ
#define CHIPID_STM32F1		0x1FFFF7E8   //F1 ϵ�е�CHIP ID  ��ַ
/***********************************  STM32 GPIOλ������   **************************************/
//λ������,ʵ��51���Ƶ�GPIO���ƹ���
//����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).
//IO�ڲ����궨��
#define BITBAND(addr, bitnum)   ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)  MEM_ADDR(BITBAND(addr, bitnum)) 
//IO�ڵ�ַӳ��  �ο��ֲ�190ҳ
#define GPIOA_ODR_Addr  (GPIOA_BASE+0x14)
#define GPIOB_ODR_Addr  (GPIOB_BASE+0x14)
#define GPIOC_ODR_Addr  (GPIOC_BASE+0x14)
#define GPIOD_ODR_Addr  (GPIOD_BASE+0x14)
#define GPIOE_ODR_Addr  (GPIOE_BASE+0x14)
#define GPIOF_ODR_Addr  (GPIOF_BASE+0x14)
#define GPIOG_ODR_Addr  (GPIOG_BASE+0x14)
 
#define GPIOA_IDR_Addr  (GPIOA_BASE+0x10)
#define GPIOB_IDR_Addr  (GPIOB_BASE+0x10)
#define GPIOC_IDR_Addr  (GPIOC_BASE+0x10)
#define GPIOD_IDR_Addr  (GPIOD_BASE+0x10)
#define GPIOE_IDR_Addr  (GPIOE_BASE+0x10)
#define GPIOF_IDR_Addr  (GPIOF_BASE+0x10)
#define GPIOG_IDR_Addr  (GPIOG_BASE+0x10)
 
//IO�ڲ���,ֻ�Ե�һ��IO��!
//ȷ��n��ֵС��16!
#define PAout(n)        BIT_ADDR(GPIOA_ODR_Addr,n)  //��� 
#define PAin(n)         BIT_ADDR(GPIOA_IDR_Addr,n)  //���� 

#define PBout(n)        BIT_ADDR(GPIOB_ODR_Addr,n)  //��� 
#define PBin(n)         BIT_ADDR(GPIOB_IDR_Addr,n)  //���� 

#define PCout(n)        BIT_ADDR(GPIOC_ODR_Addr,n)  //��� 
#define PCin(n)         BIT_ADDR(GPIOC_IDR_Addr,n)  //���� 

#define PDout(n)        BIT_ADDR(GPIOD_ODR_Addr,n)  //��� 
#define PDin(n)         BIT_ADDR(GPIOD_IDR_Addr,n)  //���� 

#define PEout(n)        BIT_ADDR(GPIOE_ODR_Addr,n)  //��� 
#define PEin(n)         BIT_ADDR(GPIOE_IDR_Addr,n)  //����

#define PFout(n)        BIT_ADDR(GPIOF_ODR_Addr,n)  //��� 
#define PFin(n)         BIT_ADDR(GPIOF_IDR_Addr,n)  //����

#define PGout(n)        BIT_ADDR(GPIOG_ODR_Addr,n)  //��� 
#define PGin(n)         BIT_ADDR(GPIOG_IDR_Addr,n)  //����


void get_chip_id(void);

#endif   /* __COMMON_H */
























