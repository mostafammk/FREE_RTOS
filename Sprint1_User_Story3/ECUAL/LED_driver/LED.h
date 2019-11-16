/*
 * LED.h
 *
 *  Created on: Nov 15, 2019
 *      Author: Mostafa-Khalil
 */

#ifndef ECUAL_LED_DRIVER_LED_H_
#define ECUAL_LED_DRIVER_LED_H_

#include "../../mcal/DIO_driver/DIO.h"


void Led_On(uint8 Port_Num,uint8 Pin_Num);
void Led_Off(uint8 Port_Num,uint8 Pin_Num);
void Led_Toggle(uint8 Port_Num,uint8 Pin_Num);

#endif /* ECUAL_LED_DRIVER_LED_H_ */
