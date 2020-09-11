/************************************************************************
* Copyright (C) 2020 Nercita
*
* 文件名称： app.c
* 文件标识：
* 内容摘要： ledtask相关函数定义
* 其它说明：
* 当前版本：
* 作    者： woody
* 完成日期： 2020.09.07
*
* 修改记录1：
*    修改日期：
*    版 本 号：
*    修 改 人：
*    修改内容：
* 修改记录2：…
************************************************************************/
#include "app.h"
/*   BSP 驱动头文件  */
#include "led.h"

/*   app 任务头文件  */
#include "ledtask.h"

/**************************************************************************
* 函数名称: bsp_Init
* 功能描述: 初始化所有的硬件设备。该函数配置 CPU 寄存器和外设的寄存器并初始化一些全局变量。只需要调用一次
* 输入参数: 无
* 输出参数: 无
* 返 回 值: 无
* -----------------------------------------------
* 2020/09/07       V1.0      woody         创建
**************************************************************************/
void bsp_Init(void)
{
	get_chip_id();				 //获取CHIP id
    bsp_InitLED(); 				 //LED I/O初始化
}

/**************************************************************************
* 函数名称: app_Init
* 功能描述:
* 输入参数: 无
* 输出参数: 无
* 返 回 值: 无
* -----------------------------------------------
* 2020/09/07       V1.0      woody         创建
**************************************************************************/
void app_Init(void)
{
    Creat_LED_Task();			//创建LED任务
	//
	//
}
















