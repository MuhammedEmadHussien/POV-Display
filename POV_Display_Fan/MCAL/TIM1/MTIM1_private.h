#ifndef _MTIM1_PRIVATE_H
#define _MTIM1_PRIVATE_H


/* Timer/Counter1 Channels */
#define OC1A	5
#define OC1B	4
#define ICP		6

/* Timer/Counter Interrupt Mask register Bits */
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2

/* Timer/Counter Interrupt Flag Register Bits */
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV     2

/* Timer/Counter1 Control Register B Bits */
#define ICNC1   7
#define ICES1   6
#define RES     5
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* Timer/Counter1 Control Register A Bits */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* Status Register Bits */
#define GIE     7

#define SREG    *((volatile u8 *)0x5F)

#define TCCR1A	*((volatile u8 *)0x4F)
#define TCCR1B	*((volatile u8 *)0x4E)

#define TCNT1	*((volatile u16 *)0x4D)
#define TCNT1H	*((volatile u8 *)0x4D)
#define TCNT1L	*((volatile u8 *)0x4C)

#define OCR1A   *((volatile u16 *)0x4A)
#define OCR1AH  *((volatile u8 *)0x4B)
#define OCR1AL  *((volatile u8 *)0x4A)

#define OCR1B   *((volatile u16 *)0x4B)
#define OCR1BH  *((volatile u8 *)0x49)
#define OCR1BL  *((volatile u8 *)0x48)

#define ICR1    *((volatile u16 *)0x46)
#define ICR1H   *((volatile u8 *)0x47)
#define ICR1L   *((volatile u8 *)0x46)

#define TIFR    *((volatile u8 *)0x58)
#define TIMSK   *((volatile u8 *)0x59)


#endif
