
#include "FREE_RTOS_Files/FreeRTOS.h"
#include "FREE_RTOS_Files/task.h"
#include "mcal/DIO_driver/DIO.h"
#include "ECUAL/LCD_driver/LCD.h"
#include "ECUAL/LED_driver/LED.h"
#include "ECUAL/KeyPad_driver/keypad.h"


#define DISABLE 8
#define ENABLE_withFOUR_HUND_MILLIS 1
#define ENABLE_withONE_HUND_MILLIS 2
#define NOT_INIT_YET 0
#define INIT_DONE 1


static volatile uint8 g_initFlag = NOT_INIT_YET;
static volatile uint8 g_Led_Request = DISABLE;
/*static volatile uint8 g_keyPad_Enable = ENABLE;*/


TaskHandle_t xHandle_toggleLED = NULL;
TaskHandle_t xHandle_systemInit = NULL;
TaskHandle_t xHandle_keypad = NULL;


void TASK_systemInit(void * argumentPtr);
void TASK_toggleLED(void * argumentPtr);
void TASK_keypad(void * argumentPtr);


void main(void)
{
	xTaskCreate(
			TASK_toggleLED,
			"TOGGLE",
			85,
			NULL,
			3,
			&xHandle_toggleLED);

	xTaskCreate(
			TASK_systemInit,
			"INIT",
			85,
			NULL,
			3,
			&xHandle_systemInit);

	xTaskCreate(
			TASK_keypad,
			"KEYPAD",
			85,
			NULL,
			3,
			&xHandle_keypad);
	/* Start Scheduler */
	vTaskStartScheduler();

	while(1)
	{

	}
}

void TASK_systemInit(void * argumentPtr)
{
	static uint8 DIO_init_status = NOT_INIT_YET;

	while(1)
	{
		if(g_initFlag == NOT_INIT_YET)
		{
			if(DIO_init_status != INIT_DONE)
			{
				DIO_init();
				DIO_init_status = INIT_DONE;
				g_initFlag = INIT_DONE;
			}
		}
		if(g_initFlag == NOT_INIT_YET)
		{
			vTaskDelay(1);
		}
		else if(g_initFlag == INIT_DONE)
		{
			vTaskSuspend(xHandle_systemInit);
		}
	}
}

void TASK_toggleLED(void * argumentPtr)
{
	while(1)
	{
		if(g_Led_Request != DISABLE)
		{
			Led_Toggle(PORT_B,PINB6);
			if(g_Led_Request == ENABLE_withONE_HUND_MILLIS)
			{
				vTaskDelay(100);
			}
			else if(g_Led_Request == ENABLE_withFOUR_HUND_MILLIS)
			{
				vTaskDelay(400);
			}
		}
		else
		{
			Led_Off(PORT_B,PINB6);
			vTaskDelay(30);
		}
	}
}

void TASK_keypad(void * argumentPtr)
{
	uint8 data;
	uint8 output;
	static uint8 prevKey = NO_KEY_PRESSED;
	static uint8 timeCount=0;

	while(1)
	{
		output = KeyPad_getPressedKey(&data);
		if(output == KEYPAD_DONE)
		{
			timeCount++;
			if(timeCount>150)
			{
				timeCount=150;
			}
			if(prevKey != data)
			{
				prevKey = data;
			}
		}
		else if(output == NO_KEY_PRESSED)
		{
			if(prevKey != NO_KEY_PRESSED)
			{
				if(timeCount > 134)
				{
					g_Led_Request = ENABLE_withONE_HUND_MILLIS;
				}
				else if(timeCount > 67)
				{
					g_Led_Request = ENABLE_withFOUR_HUND_MILLIS;
				}
				else
				{
					g_Led_Request = DISABLE;
				}
				timeCount=0;
				prevKey = NO_KEY_PRESSED;
			}
		}
		vTaskDelay(30);
	}
}
