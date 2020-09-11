/************************************************************************
* Copyright (C) Copyright 2014-2015,Nercita,Beijing,China
*
* �ļ����ƣ� main.c
* �ļ���ʶ��
* ����ժҪ�� main��غ�������
* ����˵���� https://github.com/woody5418/STM32L151_FREERTOS_DEMO
* ��ǰ�汾�� V1.0
* ��    �ߣ� woody   QQ��2490006131
* ������ڣ� 2020.09.07
*	< STM32L151ZET6 >
			FLASH SIZE	:512Kbytes
			RAM SIZE	:80Kbytes
			EEPROM  	:16K
* �޸ļ�¼1��
*    �޸����ڣ�
*    �� �� �ţ�
*    �� �� �ˣ�
*    �޸����ݣ�
* �޸ļ�¼2����
************************************************************************/
#include "MainConfig.h"
#include "usart.h"
#include "app.h"


TaskHandle_t StartTask_Handler;  //������ ������������

/**************************************************************************
* ��������: start_task
* ��������: ��������Ҳ����������ȼ�������������������������
* �������: pvParameters ���ڴ���������ʱ���ݵ��β�
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();      					//�����ٽ���
    app_Init();									//���񴴽�����
    vTaskDelete(StartTask_Handler);             //ɾ����ʼ����
    taskEXIT_CRITICAL();       					//�˳��ٽ���
}


/**************************************************************************
* ��������: main
* ��������: ������
* �������: ��
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
int main(void)
{
	/* ����������ǰ��Ϊ�˷�ֹ��ʼ�� STM32 ����ʱ���жϷ������ִ�У������ֹȫ���ж� ���� NMI �� HardFault) ��
	�������ĺô��ǣ�
	1. ��ִֹ�е��жϷ���������� FreeRTOS �� API ������
	2. ��֤ϵͳ������������ �ܱ���ж�Ӱ�졣
	3. �����Ƿ�ر�ȫ���жϣ���Ҹ����Լ���ʵ��������ü��ɡ�
	����ֲ�ļ� port.c �еĺ��� prvStartFirstTask �л����¿���ȫ���жϡ�ͨ��ָ�� cpsie i ������ ��__set_PRIMASK(
	�� cpsie i �ǵ�Ч�ġ�*/
	__set_PRIMASK(1);

    /* ��֤˯��ģʽ�µ�����������������ʹ�� */
    DBGMCU_Config(DBGMCU_SLEEP, ENABLE);

    /*	���� ST �̼���������ļ��Ѿ�ִ���� CPU ϵͳʱ�ӵĳ�ʼ�������Բ����ٴ��ظ�����ϵͳʱ�ӡ�
    	�����ļ������� CPU ��ʱ��Ƶ�ʡ��ڲ� Flash �����ٶȺͿ�ѡ���ⲿ SRAM FSMC ��ʼ����
    	ϵͳʱ��ȱʡ����Ϊ 32MHz �������Ҫ���ģ������޸� system_stm32l1xx.c �ļ�*/
    /* ���ȼ���������Ϊ 4 �������� 0~15 ����ռʽ���ȼ��� 0 �������ȼ����������������ȼ���*/
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
    delay_init();			//��ʱ��ʼ������
#if DEBUG_LOG_PRINTF
    USART1_Init(115200);
#endif
    bsp_Init();				//����Ӳ���̼���ʼ��
#if DEBUG_LOG_PRINTF
    DEBUG_LOG_PRF(STM32_VERSION);
#endif	
	
    /* �������� */
    xTaskCreate((TaskFunction_t	)start_task,		  	//������
                (const char* 	)"start_task",		  	//��������
                (uint16_t 		)START_STK_SIZE,	  	//�����ջ��С
                (void* 		  	)NULL,				  	//���ݸ��������Ĳ���
                (UBaseType_t 	)START_TASK_PRIO, 	  	//�������ȼ�
                (TaskHandle_t*  )&StartTask_Handler); 	//������

    vTaskStartScheduler();    							//�����������
    /*
     ���ϵͳ���������ǲ������е�����ģ����е����Ｋ�п��������ڶ�ʱ��������߿��������
     heap �ռ䲻����ɴ���ʧ�ܣ���Ҫ�Ӵ� FreeRTOSConfig.h �ļ��ж���� heap ��С��
     #define configTOTAL_HEAP_SIZE ( ( size_t ) ( 8 * 1024 ) )
    */
    while(1);
}


/***************************************************************************************************/

void vApplicationTickHook(void)
{
    /* This function will be called by each tick interrupt if
    configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
    added here, but the tick hook is called from an interrupt context, so
    code must not attempt to block, and only the interrupt safe FreeRTOS API
    functions can be used (those that end in FromISR()).  */

}

void vApplicationIdleHook(void)
{
    /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
    to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
    task.  It is essential that code added to this hook function never attempts
    to block in any way (for example, call xQueueReceive() with a block time
    specified, or call vTaskDelay()).  If the application makes use of the
    vTaskDelete() API function (as this demo application does) then it is also
    important that vApplicationIdleHook() is permitted to return to its calling
    function, because it is the responsibility of the idle task to clean up
    memory allocated by the kernel to any task that has since been deleted. */
}

void vApplicationMallocFailedHook(void)
{
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
    function that will get called if a call to pvPortMalloc() fails.
    pvPortMalloc() is called internally by the kernel whenever a task, queue,
    timer or semaphore is created.  It is also called by various parts of the
    demo application.  If heap_1.c or heap_2.c are used, then the size of the
    heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
    FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
    to query the size of free heap space that remains (although it does not
    provide information on how the remaining heap might be fragmented). */
    taskDISABLE_INTERRUPTS();
    for(;;);
}
























