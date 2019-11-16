#include "FREE_RTOS_Files/FreeRTOS.h"
#include "FREE_RTOS_Files/task.h"
#include "mcal/DIO_driver/DIO.h"
#include "ECUAL/LCD_driver/LCD.h"
#include "ECUAL/LED_driver/LED.h"
#include "ECUAL/KeyPad_driver/keypad.h"

#define DISABLE 0
#define ENABLE 1
#define NOT_INIT_YET 0
#define INIT_DONE 1
#define WRONG_PASS 10
#define CORRECT_PASS 11

static volatile uint8 g_initFlag = NOT_INIT_YET;
static volatile uint8 g_keyPad_Enable = ENABLE;
static volatile uint8 g_LCD_charDisplayRequest=0;
static volatile uint8 g_LCD_dispData=0;
static volatile uint8 const g_Password[6]={2,2,4,4,6,6};

TaskHandle_t xHandle_toggleLED = NULL;
TaskHandle_t xHandle_systemInit = NULL;
TaskHandle_t xHandle_LCD = NULL;
TaskHandle_t xHandle_keypad = NULL;


void TASK_systemInit(void * argumentPtr);
void TASK_toggleLED(void * argumentPtr);
void TASK_LCD(void * argumentPtr);
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
			TASK_LCD,
			"LCD",
			85,
			NULL,
			3,
			&xHandle_LCD);
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
	static uint8 LCD_init_status = NOT_INIT_YET;

	while(1)
	{
		if(g_initFlag == NOT_INIT_YET)
		{
			if(DIO_init_status != INIT_DONE)
			{
				DIO_init();
				DIO_init_status = INIT_DONE;
			}

			if(LCD_init_status != INIT_DONE)
			{
				LCD_init_status = LCD_init(LCD_ptrConfig);
				if(LCD_init_status == LCD_DONE)
				{
					LCD_init_status = INIT_DONE;
					g_initFlag = INIT_DONE;
				}
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
		Led_Toggle(PORT_B,PINB6);
		vTaskDelay(1000);
	}

}

void TASK_LCD(void * argumentPtr)
{
	static volatile uint8 taskDelay=1;
	static volatile uint8 LCD_dispFuncStatus=0;
	static volatile uint8 LOC_dispData;
	static volatile uint8 busyFlag=0;
	static const uint8 dispChar[10] = {
			'0',
			'1',
			'2',
			'3',
			'4',
			'5',
			'6',
			'7',
			'8',
			'9',
	};

	while(1)
	{
		if(g_initFlag == INIT_DONE)
		{
			if(g_LCD_charDisplayRequest == 1)
			{
				g_keyPad_Enable = DISABLE;
				if(busyFlag == 0)
				{
					if(g_LCD_dispData < 9)
					{
						LOC_dispData = g_LCD_dispData;
					}
					else
					{
						LOC_dispData = 9;
					}
					busyFlag =1;
				}

				if(LOC_dispData < 9)
				{
					LCD_dispFuncStatus = LCD_displayChar(dispChar[g_LCD_dispData]);
				}
				else if(LOC_dispData == 9)
				{
					LCD_dispFuncStatus = LCD_clear();
				}
				else if(LOC_dispData == 10)
				{
					LCD_dispFuncStatus = LCD_displayString("WRONG PASS");
				}
				else if(LOC_dispData == 11)
				{
					LCD_dispFuncStatus = LCD_displayString("CORRECT PASS");
				}

				if(LCD_dispFuncStatus == LCD_STR_COMPELET)
				{
					g_LCD_dispData=9;
					busyFlag=0;
					taskDelay=2;
				}
				else if(LCD_dispFuncStatus == LCD_DONE)
				{
					if(g_LCD_dispData > 9)
					{
						LOC_dispData = g_LCD_dispData;
					}
					else
					{
						g_LCD_charDisplayRequest =0;
						busyFlag=0;
						g_keyPad_Enable = ENABLE;
					}
				}
			}
		}

		if(taskDelay != 1)
		{
			taskDelay = 1;
			vTaskDelay(2000);
		}
		else
			vTaskDelay(1);
	}
}

uint8 PassCheck(uint8*passBuffer)
{
	uint8 returnVal=CORRECT_PASS;
	uint8 indx;

	for(indx=0 ; indx<6 ; indx++)
	{
		if(passBuffer[indx] != g_Password[indx])
		{
			returnVal = WRONG_PASS;
		}
	}

	return returnVal;
}

void TASK_keypad(void * argumentPtr)
{
	uint8 data;
	uint8 output;
	static uint8 prevKey = NO_KEY_PRESSED;
	static uint8 passBuffer[16];
	static uint8 digitsCount=0;

	while(1)
	{
		output = KeyPad_getPressedKey(&data);
		if((output == KEYPAD_DONE) && (g_keyPad_Enable==ENABLE))
		{
			if(prevKey != data)
			{
				prevKey = data;

				if(data == 7)
				{
					if(digitsCount != 6)
					{
						g_LCD_dispData = WRONG_PASS;
					}
					else
					{
						output = PassCheck(passBuffer);
						if(output == WRONG_PASS)
						{
							g_LCD_dispData = WRONG_PASS;
						}
						else if(output == CORRECT_PASS)
						{
							g_LCD_dispData = CORRECT_PASS;
						}
					}
					digitsCount=0;
				}
				else if(data == 9)
				{
					g_LCD_dispData=data;
					digitsCount=0;
				}
				else
				{
					g_LCD_dispData=data;
					passBuffer[digitsCount]=data;
					digitsCount++;

				}
				g_LCD_charDisplayRequest=1;

			}
		}
		else if(output == NO_KEY_PRESSED)
		{
			prevKey = NO_KEY_PRESSED;
		}
		vTaskDelay(30);
	}
}
