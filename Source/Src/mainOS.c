#include "mainOS.h"
#include "cmsis_os.h"
#include "buttons.h"


extern TIM_HandleTypeDef htim10;


static void vPWMTask(void * param);
static void vButtonTask(void * param);

QueueHandle_t xJosticQueue = NULL;
QueueHandle_t xPWMQueue = NULL;




void createAllTask()
{
	(void) xTaskCreate(vPWMTask, "PWMTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY , NULL);
	(void) xTaskCreate(vButtonTask, "ButtonTask", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY , NULL);


	xJosticQueue = xQueueCreate(5,sizeof(Joystick));
	xPWMQueue = xQueueCreate(5,sizeof(int));
}


void vPWMTask(void * param)
{
    HAL_TIM_PWM_Start(&htim10, TIM_CHANNEL_1);

    int PWMValue = 0;
	while(1)
	{
		xQueueReceive(xPWMQueue, &PWMValue, portMAX_DELAY);
		TIM10->CCR1 = PWMValue * 100;
	}
}


static void vButtonTask(void * param)
{
	Joystick joystick = {0};
	while(1)
	{
		if(getJoystickState(&joystick))
		{
			xQueueSend(xJosticQueue,&joystick,portMAX_DELAY);
		}
		vTaskDelay(100);
	}
}
