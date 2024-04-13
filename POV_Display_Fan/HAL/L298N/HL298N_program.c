#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/MDIO_interface.h"
#include "../../MCAL/TIM1/MTIM1_interface.h"
#include "HL298N_private.h"
#include "HL298N_config.h"
#include "HL298N_interface.h"

/*

Function:

    HL298N_voidL298NChannelAInit

    Initializes pins used for Channel A on the L298N module

*/

void HL298N_voidL298NChannelAInit (u8 *pins, u8 pinNo)
{
    /* Initialize pins to output */

    for (int i = 0; i < pinNo; i++)
    {
        MDIO_voidSetPinDirection(HL298N_PORT, pins[i], OUTPUT);
    }

    /* Initialize timer with initial PWM 0 */

    MTIM1_voidTimer1Init();
}

/*

Function:

    HL298N_voidRotateClockwise

    Actuates the motor Clockwise with given PWM speed

*/

void HL298N_voidRotateClockwise (u8* pins, u8 pinNo, u16 speed)
{
    /* Initialize pins to output */

    for (int i = 0; i < pinNo; i++)
    {
        if (i % 2 == 0)
        {
            MDIO_voidSetPinValue(HL298N_PORT, pins[i], HIGH);
        }
        else
        {
            MDIO_voidSetPinValue(HL298N_PORT, pins[i], LOW);
        }
    }

    MTIM1_voidTimer1SetOutputCompareRegister1A(speed);
}

/*

Function: 

    HL298N_voidCounterClockwise

    Actuates the motor Counter Clockwise with given PWM Speed

*/

void HL298N_voidCounterRotateClockwise (u8* pins, u8 pinNo, u16 speed)
{
    /* Initialize pins to output */

    for (int i = 0; i < pinNo; i++)
    {
        if (i % 2 == 0)
        {
            MDIO_voidSetPinValue(HL298N_PORT, pins[i], LOW);
        }
        else
        {
            MDIO_voidSetPinValue(HL298N_PORT, pins[i], HIGH);
        }
    }

    MTIM1_voidTimer1SetOutputCompareRegister1A(speed);
}
