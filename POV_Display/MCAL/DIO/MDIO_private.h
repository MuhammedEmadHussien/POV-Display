/*
 * DIO_Private.h
 *
 *  Created on: Oct 14, 2023
 *      Author: muham
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_


//volatile means: always when sees DDRA for ex. then goes into that address, we point at and look for the value and bring it down (every single time)

#define DDRA	*((volatile char *)0x3A)
#define DDRB	*((volatile char *)0x37)
#define DDRC	*((volatile char *)0x34)
#define DDRD	*((volatile char *)0x31)

#define PORTA	*((volatile char *)0x3B)
#define PORTB	*((volatile char *)0x38)
#define PORTC	*((volatile char *)0x35)
#define PORTD	*((volatile char *)0x32)

#define PINA	*((volatile char *)0x39)
#define PINB	*((volatile char *)0x36)
#define PINC	*((volatile char *)0x33)
#define PIND	*((volatile char *)0x30)


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
