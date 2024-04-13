/*
 * main.c
 *
 *  Created on: Feb 17, 2024
 *      Author: muham
 */
#include "avr/interrupt.h"
#include "LIB/STD_TYPES.h"
#include "util/delay.h"
#include "MCAL/DIO/MDIO_interface.h"
#include "MCAL/TIM1/MTIM1_interface.h"

#define F_CPU	16e6U

/* Space Value */
#define POV_LETTER_SPACE_TIME		0.1

enum leds {
	LED1 = 0b10000000,
	LED7 = 0b01000010,
	LED6 = 0b00100100,
	LED5 = 0b00001000,
	LED4 = 0b00010000,
	LED3_2 = 0b01100000
};

volatile f64 ticks = 0;
volatile f64 t1 = 0;
volatile f64 t2 = 0;
volatile f64 dt = 0;
volatile f64 tmp = 0;

void printI (void);
void printM (void);
void printT (void);

void main (void)
{
	MDIO_voidSetPortDirection(C, OUTPUT);


	MDIO_voidSetPinDirection(D,6, INPUT);
	while(1)
	{
		MDIO_voidSetPortValue(C, 0);
		_delay_us(88888);

		 printI ();
		_delay_us(5000);
		 printM ();
		_delay_us(5000);
		 printT ();
		_delay_us(5000);


	}
}

void printI (void)
{

	MDIO_voidSetPortValue(C, LED7 | LED1);
	_delay_us(4000);

	MDIO_voidSetPortValue(C, 255);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, 0);
	MDIO_voidSetPortValue(C, LED7 | LED1);
	_delay_us(4000);
}

void printM (void)
{
	MDIO_voidSetPortValue(C, LED7);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED6);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED5);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED4);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED3_2);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED1);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED3_2);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED4);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED5);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED4);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED3_2);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED1);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED3_2);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED4);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED5);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED6);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, LED7);
	_delay_us(2000);
}

void printT (void)
{
	MDIO_voidSetPortValue(C, LED1);
	_delay_us(4000);

	MDIO_voidSetPortValue(C, 255);
	_delay_us(2000);

	MDIO_voidSetPortValue(C, 0);
	MDIO_voidSetPortValue(C, LED1);
	_delay_us(4000);

}
