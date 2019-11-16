/*
 * LED.c
 *
 *  Created on: Nov 15, 2019
 *      Author: Mostafa-Khalil
 */


#include "../LED_driver/LED.h"

#define LED_ON 1
#define LED_OFF 0

static uint8 led_Status = LED_OFF;


void Led_Off(uint8 Port_Num,uint8 Pin_Num)
{

	DIO_write_pin_value(Port_Num,Pin_Num,0);
	led_Status = LED_OFF;
}
void Led_On(uint8 Port_Num,uint8 Pin_Num)
{

	DIO_write_pin_value(Port_Num,Pin_Num,1);
	led_Status = LED_ON;

}

void Led_Toggle(uint8 Port_Num,uint8 Pin_Num)
{

	if(led_Status == LED_ON)
	{
		DIO_write_pin_value(Port_Num,Pin_Num,0);
		led_Status = LED_OFF;

	}
	else if(led_Status == LED_OFF)
	{

		DIO_write_pin_value(Port_Num,Pin_Num,1);
		led_Status = LED_ON;

	}


}
