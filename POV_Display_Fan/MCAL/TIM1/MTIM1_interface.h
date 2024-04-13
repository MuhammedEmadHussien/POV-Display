#ifndef _MTIM1_INTERFACE_H
#define _MTIM1_INTERFACE_H


/*
Available Clock Sources
*/

enum MTIM1_CLK_SRCs
{
    MTIM1_CLK_NONE,    
    MTIM1_CLK_DIV_1,
    MTIM1_CLK_DIV_8,    
    MTIM1_CLK_DIV_64,    
    MTIM1_CLK_DIV_256,   
    MTIM1_CLK_DIV_1024,  
    MTIM1_CLK_T1_RISING, 
    MTIM1_CLK_T1_FALLING
};

/*
Available WGMs:
*/

enum MTIM1_WGM
{
    MTIM1_WGM_NORMAL,          
    MTIM1_WGM_PWM_PC_8BIT,
    MTIM1_WGM_PWM_PC_9BIT,      
    MTIM1_WGM_PWM_PC_10BIT,      
    MTIM1_WGM_CTC_TOP_OCR1A,     
    MTIM1_WGM_PWM_FAST_8BIT,    
    MTIM1_WGM_PWM_FAST_9BIT,    
    MTIM1_WGM_PWM_FAST_10BIT,    
    MTIM1_WGM_PWM_PFC_TOP_ICR1,  
    MTIM1_WGM_PWM_PFC_TOP_OCR1A, 
    MTIM1_WGM_PWM_PC_TOP_ICR1,
    MTIM1_WGM_PWM_PC_TOP_OCR1A,  
    MTIM1_WGM_CTC_TOP_ICR1,
    RESERVERD,      
    MTIM1_WGM_PWM_FAST_TOP_ICR1,
    MTIM1_WGM_PWM_FAST_TOP_OCR1A
};

/*
Available COMs:
*/

enum MTIM1_COM
{
    MTIM1_COM_OC1AB_DISCONNECTED,
    MTIM1_COM_OC1AB_TOGGLE,
    MTIM1_COM_OC1AB_CLEAR,
    MTIM1_COM_OC1AB_SET
};

/* Used States */
#define ON  1
#define OFF 0

/* 
Function: MTIM1_voidTimer1Init 

Starts timer 1 on given configurations

*/

void MTIM1_voidTimer1Init();

/* 
Function: MTIM1_voidTimer1Init 

stops timer 1

*/

void MTIM1_voidTimer1Deinit();

/*
Function: MTIM1_voidTimer1SetOutputCompareRegister1A

Sets the value of OCR1A

*/

void MTIM1_voidTimer1SetOutputCompareRegister1A(u16 value);

/*
Function: MTIM1_voidTimer1SetOutputCompareRegister1B

Sets the value of OCR1B

*/

void MTIM1_voidTimer1SetOutputCompareRegister1B(u16 value);

/*
Function: MTIM1_voidTimer1GetInputCaptureRegister1

Gets the value of ICR1

*/

u16 MTIM1_voidTimer1GetInputCaptureRegister1(void);

#endif
