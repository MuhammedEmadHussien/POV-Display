#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/MDIO_interface.h"
#include "MTIM1_private.h"
#include "MTIM1_interface.h"
#include "MTIM1_config.h"

void MTIM1_voidTimer1Init (void)
{
    /* Define Wave Generation Mode */
    TCCR1A |= (u8) MTIM1_WGM & 0b11;
    TCCR1B |= ((u8) MTIM1_WGM & 0b1100) << 1;

    /* Define Compare Output Mode */
    TCCR1A |= ((u8)MTIM1_OC1A_COM << COM1A0) | ((u8)MTIM1_OC1B_COM << COM1B0);

    /* Configure Force Output Compare for OC1A/B */
    #if MTIM1_FOC_OC1A == ON

        SET_BIT(TCCR1A, FOC1A);

    #else

        RESET_BIT(TCCR1A, FOC1A);

    #endif

    #if MTIM1_FOC_OC1B == ON

        SET_BIT(TCCR1A, FOC1B);

    #else

        RESET_BIT(TCCR1A, FOC1B);

    #endif

    /* Configure Input Capture Noise Canceler */
    #if MTIM1_ICNC == ON

        SET_BIT(TCCR1B, ICNC1);

    #else

        RESET_BIT(TCCR1B, ICNC1);

    #endif

    /* Configure Input Capture Edge Select */
    #if MTIM1_IC_TRIGGER == MTIM1_IC_TRIGGER_FALLING

        RESET_BIT(TCCR1B, ICES1);

    #else

        SET_BIT(TCCR1B, ICES1);

    #endif

    /* Configure Input Capture Interrupt */
    #if MTIM1_IC_IRQ == ON

        SET_BIT(SREG, GIE);
        SET_BIT(TIMSK, TICIE1);

    #else

        RESET_BIT(TIMSK, TICIE1);

    #endif

    /* Configure Output Compare A Match Interrupt */
    #if MTIM1_OCA_IRQ == ON

        SET_BIT(SREG, GIE);
        SET_BIT(TIMSK, OCIE1A);

    #else

        RESET_BIT(TIMSK, OCIE1A);

    #endif

    /* Configure Output Compare B Match Interrupt */
    #if MTIM1_OCB_IRQ == ON

        SET_BIT(SREG, GIE);
        SET_BIT(TIMSK, OCIE1B);

    #else

        RESET_BIT(TIMSK, OCIE1B);

    #endif

    /* Configure Output Compare B Match Interrupt */
    #if MTIM1_OVF_IRQ == ON

        SET_BIT(SREG, GIE);
        SET_BIT(TIMSK, TOIE1);

    #else

        RESET_BIT(TIMSK, TOIE1);

    #endif

    /* Enable Port Direction for Selected Channels */
	if (MTIM1_OC1A_COM != MTIM1_COM_OC1AB_DISCONNECTED)
	{
		MDIO_voidSetPinDirection(D, OC1A, OUTPUT);
	}
	else if (
				MTIM1_OC1B_COM != MTIM1_COM_OC1AB_DISCONNECTED &&
				(
					MTIM1_WGM != MTIM1_WGM_PWM_FAST_TOP_OCR1A ||
					MTIM1_WGM != MTIM1_WGM_PWM_PFC_TOP_OCR1A  ||
					MTIM1_WGM != MTIM1_WGM_PWM_FAST_TOP_ICR1
				)
			)
	{
		MDIO_voidSetPinDirection(D, OC1B, OUTPUT);
	}

	/* Define Clock Source (Start timer) */
	TCCR1B |= MTIM1_CLK_SRC;
}


void MTIM1_voidTimer1Deinit (void)
{
    /* Freeze Clock */
    TCCR1B |= MTIM1_CLK_NONE;

    /* Reset TCNT1 */
    TCNT1 = 0;

}

void MTIM1_voidTimer1SetOutputCompareRegister1A(u16 value)
{
    OCR1A = value;
}

void MTIM1_voidTimer1SetOutputCompareRegister1B(u16 value)
{
    OCR1B = value;
}

