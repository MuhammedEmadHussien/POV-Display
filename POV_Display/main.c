/*
 * main.c
 *
 *  Created on: Feb 17, 2024
 *      Author: muham
 */
#include "LIB/STD_TYPES.h"
#include "util/delay.h"
#include "avr/io.h"
#include "HAL/L298N/HL298N_interface.h"
#include "MCAL/DIO/MDIO_interface.h"

#define PINS_NO		6

void ADC_Init()
{
	DDRA=0x0;			/* Make ADC port as input */
	ADCSRA = 0x87;			/* Enable ADC, fr/128  */
	ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */

}

int ADC_Read(char channel)
{
	int Ain,AinLow;

	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */

	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and
					Multiply with weight */
	Ain = Ain + AinLow;
	return(Ain);			/* Return digital value*/
}

void main (void)
{
	u8 pins [] = {0, 1, 2, 3, 4, 5};

	HL298N_voidL298NChannelAInit(pins, PINS_NO);
	ADC_Init();

	while (1)
	{
		u16 reading = ADC_Read(0);


		u8 speed = (0.097751 * reading);
		HL298N_voidRotateClockwise(pins, PINS_NO, speed);

	}


}





