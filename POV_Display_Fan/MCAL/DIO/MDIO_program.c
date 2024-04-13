#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_config.h"
#include "MDIO_interface.h"



void MDIO_voidSetPinDirection (u8 port, u8 pin, u8 dir)
{
    switch (port)
    {
        case A:
            switch (dir)
            {
                case OUTPUT:    SET_BIT(DDRA,pin); break;
                case INPUT:     RESET_BIT(DDRA,pin); break;
                default: break;
            }
            break;
        case B:
            switch (dir)
            {
                case OUTPUT:    SET_BIT(DDRB,pin); break;
                case INPUT:     RESET_BIT(DDRB,pin); break;
                default: break;
            }
            break;
        case C:
            switch (dir)
            {
                case OUTPUT:    SET_BIT(DDRC,pin); break;
                case INPUT:     RESET_BIT(DDRC,pin); break;
                default: break;
            }
            break;
        case D:
            switch (dir)
            {
                case OUTPUT:    SET_BIT(DDRD,pin); break;
                case INPUT:     RESET_BIT(DDRD,pin); break;
                default: break;
            }
            break;
        default: break;
    }
}

void MDIO_voidSetPinValue (u8 port, u8 pin, u8 val)
{
    switch (port)
    {
        case A:
            switch (val)
            {
                case HIGH:    SET_BIT(PORTA,pin); break;
                case LOW:     RESET_BIT(PORTA,pin); break;
                default: break;
            }
            break;
        case B:
            switch (val)
            {
                case HIGH:    SET_BIT(PORTB,pin); break;
                case LOW:     RESET_BIT(PORTB,pin); break;
                default: break;
            }
            break;
        case C:
            switch (val)
            {
                case HIGH:    SET_BIT(PORTC,pin); break;
                case LOW:     RESET_BIT(PORTC,pin); break;
                default: break;
            }
            break;
        case D:
            switch (val)
            {
                case HIGH:    SET_BIT(PORTD,pin); break;
                case LOW:     RESET_BIT(PORTD,pin); break;
                default: break;
            }
            break;
        default: break;
    }
}

void MDIO_voidSetPortDirection (u8 port, u8 dir)
{
    switch (port)
    {
        case A:
            switch (dir)
            {
                case OUTPUT:    DDRA = 255; break;
                case INPUT:     DDRA = 0;   break;
                default: break;
            }
            break;
        case B:
            switch (dir)
            {
                case OUTPUT:    DDRB = 255; break;
                case INPUT:     DDRB = 0;   break;
                default: break;
            }
            break;
        case C:
            switch (dir)
            {
                case OUTPUT:    DDRC = 255; break;
                case INPUT:     DDRC = 0;   break;
                default: break;
            }
            break;
        case D:
            switch (dir)
            {
                case OUTPUT:    DDRD = 255; break;
                case INPUT:     DDRD = 0;   break;
                default: break;
            }
            break;
        default: break;
    }
}

void MDIO_voidSetPortValue (u8 port, u8 val)
{
    switch (port)
    {
        case A: PORTA = val; break;

        case B:	PORTB = val; break;
        case C: PORTC = val; break;
        case D:	PORTD = val; break;

        default: break;
    }
}

u8   MDIO_u8GetPinValue   (u8 port, u8 pin)
{
    switch (port)
    {
        case A: return PINA;
        case B: return PINB;
        case C: return PINC;
        case D: return PIND;
        default: return 0;
    }
}
