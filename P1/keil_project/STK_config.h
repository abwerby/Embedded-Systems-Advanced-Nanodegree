/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2022              */
/*****************************************/

#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/*
    Options:
        STK_ENABLE
        STK_DISABLE
*/
#define SYSTICK_STATE           STK_ENABLE
/*
Enable or disable interrupt:
    Options:
        STK_INT_ENABLE
        STK_INT_DISABLE
*/
#if SYSTICK_STATE == STK_ENABLE    
    #define SYSTICK_INTERRUPT       STK_INT_ENABLE
#endif
/*
SysTick clock source:
    Options:
        PIOSC
        SYSCLK
*/
#if SYSTICK_STATE == STK_ENABLE   
    #define SYSTICK_CLK_SOURCE      PIOSC
#endif


#endif

