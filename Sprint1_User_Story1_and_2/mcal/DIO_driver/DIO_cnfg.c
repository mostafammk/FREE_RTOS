/*
 * DIO_cnfg.c
 *
 * Created:  23 , 9 , 2019
 *  Author: Peter
 */
#include "../DIO_driver/DIO.h"
extern DIO_cnfg_pin DIO_cnfg_arr[NUM_OF_PINS];

DIO_cnfg_pin DIO_cnfg_arr [NUM_OF_PINS] =
{
	{PORT_A,PIN1,OUTPUT,NA,EXTRES},
	{PORT_A,PIN2,OUTPUT,NA,EXTRES},
	{PORT_A,PIN3,OUTPUT,NA,EXTRES},
	{PORT_A,PIN4,OUTPUT,NA,EXTRES},
	{PORT_A,PIN5,OUTPUT,NA,EXTRES},
	{PORT_A,PIN6,OUTPUT,NA,EXTRES},
	{PORT_A,PIN7,OUTPUT,NA,EXTRES},
	{PORT_B,PIN7,OUTPUT,NA,EXTRES},
	{PORT_B,PIN6,OUTPUT,NA,EXTRES},
	{PORT_B,PIN5,OUTPUT,NA,EXTRES},
	{PORT_B,PIN4,OUTPUT,NA,EXTRES}
};