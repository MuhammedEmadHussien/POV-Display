#ifndef _HL298N_INTERFACE_H

#define _HL298N_INTERFACE_H


/*

Function:

    HL298N_voidL298NChannelAInit

    Initializes pins used for Channel A on the L298N module

*/

void HL298N_voidL298NChannelAInit (u8 *pins, u8 pinNo);

/*

Function:

    HL298N_voidRotateClockwise

    Actuates the motor Clockwise with given PWM speed

*/

void HL298N_voidRotateClockwise (u8* pins, u8 pinNo, u16 speed);

/*

Function: 

    HL298N_voidCounterClockwise

    Actuates the motor Counter Clockwise with given PWM Speed

*/

void HL298N_voidCounterRotateClockwise (u8* pins, u8 pinNo, u16 speed);


#endif
