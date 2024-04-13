#ifndef _MTIM1_CONFIG_H
#define _MTIM1_CONFIG_H

/*
Available Clock Sources:

    MTIM1_CLK_NONE      ->  Stopped Timer (No Clock)
    MTIM1_CLK_DIV_1     ->  Clock/1 (same as MCU)
    MTIM1_CLK_DIV_8     ->  Clock/8
    MTIM1_CLK_DIV_64    ->  Clock/64
    MTIM1_CLK_DIV_256   ->  Clock/256
    MTIM1_CLK_DIV_1024  ->  Clock/1024
    MTIM1_CLK_T1_RISING ->  Clock from T1 Pin, on rising edge
    MTIM1_CLK_T1_FALLING->  Clock from T1 Pin, on falling edge
*/

#define MTIM1_CLK_SRC   MTIM1_CLK_DIV_64

/*
Available Wave Generation Modes:

    MTIM1_WGM_NORMAL                ->      Normal Timer Operation
    MTIM1_WGM_PWM_PC_8BIT           ->      Phase Correct PWM , 8 Bit Resolution
    MTIM1_WGM_PWM_PC_9BIT           ->      Phase Correct PWM , 9 Bit Resolution
    MTIM1_WGM_PWM_PC_10BIT          ->      Phase Correct PWM , 10 Bit Resolution
    MTIM1_WGM_CTC_TOP_OCR1A         ->      Clear Timer on Compare, With TCNT top would be OCR1A
    MTIM1_WGM_PWM_FAST_8BIT         ->      Fast PWM, 8 Bit Resolution
    MTIM1_WGM_PWM_FAST_9BIT         ->      Fast PWM, 9 Bit Resolution
    MTIM1_WGM_PWM_FAST_10BIT        ->      Fast PWM, 10 Bit Resolution 
    MTIM1_WGM_PWM_PFC_TOP_ICR1      ->      Phase and Frequency Correct PWM, with TCNT top would be ICR1
    MTIM1_WGM_PWM_PFC_TOP_OCR1A     ->      Phase and Frequency Correct PWM, with TCNT top would be OCR1A
    MTIM1_WGM_PWM_PC_TOP_ICR1       ->      Phase Correct PWM, with TCNT top would be ICR1
    MTIM1_WGM_PWM_PC_TOP_OCR1A      ->      Phase Correct PWM, with TCNT top would be OCR1A
    MTIM1_WGM_CTC_TOP_ICR1          ->      Clear Timer on Compare, With TCNT top would be ICR1
    MTIM1_WGM_PWM_FAST_TOP_ICR1     ->      Fast PWM, with TCNT top would be ICR1
    MTIM1_WGM_PWM_FAST_TOP_OCR1A    ->      Fast PWM, with TCNT top would be OCR1A
*/

#define MTIM1_WGM   MTIM1_WGM_PWM_FAST_10BIT

/*
Available Compare Output Modes (Using External Pins OC1A/B):

    MTIM1_COM_OC1AB_DISCONNECTED:
        
        On Non-PWM WGM Modes:                                                                       ->      Normal I/O Port Operation, OC1A/B Disconnected
        On Fast PWM WGM Modes:                                                                      ->      Normal I/O Port Operation, OC1A/B Disconnected
        On Phase Correct and Phase and Frequency Correct PWM WGM Modes:                             ->      Normal I/O Port Operation, OC1A/B Disconnected
        
    MTIM1_COM_OC1AB_TOGGLE:
        On Non-PWM WGM Modes:                                                                       ->      Toggle OC1A/OC1B on compare match

        On Fast PWM WGM Modes:
            On Fast PWM WGM Mode MTIM1_WGM_PWM_FAST_TOP_OCR1A:                                      ->      Toggle OC1A on Compare Match, OC1B Disconnected ( Normal Port Operation )
            On any other Fast PWM WGM Mode:                                                         ->      Normal I/O Port Operation, OC1A/B Disconnected

        On Phase Correct and Phase and Frequency Correct PWM WGM Modes:
            On MTIM1_WGM_PWM_PFC_TOP_OCR1A and MTIM1_WGM_PWM_FAST_TOP_ICR1:                         ->      Toggle OC1A on Compare Match, OC1B Disconnected ( Normal Port Operation )
            On any other PC PWM WGM Mode:                                                           ->      Normal I/O Port Operation, OC1A/B Disconnected

    MTIM1_COM_OC1AB_CLEAR:
        On Non-PWM WGM Modes:                                                                       ->      Clear OC1A/B On Compare Match (Set to Low level)
        On Fast PWM WGM Modes:                                                                      ->      Clear OC1A/B On Compare Match, Set OC1A/B On TOP
        On Phase Correct and Phase and Frequency Correct PWM WGM Modes:                             ->      Clear OC1A/B on compare match when upcounting. Set OC1A/B on compare match when downcounting.

    MTIM1_COM_OC1AB_SET:
        On Non-PWM WGM Modes:                                                                       ->      Set OC1A/B on compare match (Set output to high level)
        On Fast PWM WGM Modes:                                                                      ->      Set OC1A/B on compare match, clear OC1A/B at TOP
        On Phase Correct and Phase and Frequency Correct PWM WGM Modes:                             ->      Set OC1A/B on compare match when upcounting. Clear OC1A/B on compare match when downcounting.
*/

#define MTIM1_OC1A_COM   MTIM1_COM_OC1AB_CLEAR
#define MTIM1_OC1B_COM   MTIM1_COM_OC1AB_DISCONNECTED

/* 

Enable Force Output Compare for OC1A:

    ON      -> Enable Force Output Compare for pin OC1A
    OFF     -> Disable Force Output Compare for pin OC1A

*/

#define MTIM1_FOC_OC1A  OFF

/* 
Force Output Compare for OC1B:

    ON      -> Enable Force Output Compare for pin OC1B
    OFF     -> Disable Force Output Compare for pin OC1B

*/

#define MTIM1_FOC_OC1B  OFF

/*
Input Capture Noise Canceler:

    ON      -> Enable Input Capture Noise Canceler
    OFF     -> Disable Input Capture Noise Canceler

*/

#define MTIM1_ICNC  OFF

/*
Input Capture Edge Select:

    MTIM1_IC_TRIGGER_FALLING        ->      Input Capture will trigger on Falling Edge
    MTIM1_IC_TRIGGER_RISING        ->      Input Capture will trigger on Rising Edge
    
*/

#define MTIM1_IC_TRIGGER    MTIM1_IC_TRIGGER_FALLING

/*
Input Capture Interrupt Enable:

    ON      -> Enable Input Capture Interrupt
    OFF     -> Disable Input Capture Interrupt
*/

#define MTIM1_IC_IRQ    OFF

/*
Output Compare A Match Interrupt Enable:

    ON      -> Enable Output Compare A Match Interrupt
    OFF     -> Disable Output Compare A Match Interrupt
*/

#define MTIM1_OCA_IRQ   OFF

/*
Output Compare B Match Interrupt Enable:

    ON      -> Enable Output Compare B Match Interrupt
    OFF     -> Disable Output Compare B Match Interrupt
*/

#define MTIM1_OCB_IRQ   OFF

/*
Overflow Interrupt Enable:

    ON      -> Enable Overflow Interrupt Enable
    OFF     -> Disable Overflow Interrupt Enable

*/

#define MTIM1_OVF_IRQ   OFF

#endif
