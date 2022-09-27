/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#include <stdint.h>
#include "BIT_MATH.h"
#include "STK_private.h"
#include "STK_config.h"
#include "STK_interface.h"

 /* Variable to store millisecond ticks */
volatile uint32_t msTicks = 0;       
                      
void (* STK_CallBack) (void) = NULL;


/**
	* @brief  Initializes the Systick.
	* @param  init_ticks : initial ticks to preload to the timer (to control the interrupt).
	* @retval None
	*/
void STK_Init(uint32_t tTicks)
{
    #if SYSTICK_STATE  == STK_ENABLE
        /* Load ticks value */
        STK_LOAD = tTicks - 1;
        /* Clear current value */
        STK_VAL = 0;

        SET_BIT(STK_CTRL, 0);
        #if SYSTICK_INTERRUPT == STK_INT_ENABLE
            SET_BIT(STK_CTRL, 1);
        #endif
        #if SYSTICK_CLK_SOURCE == SYSCLK
            SET_BIT(STK_CTRL, 2);
        #elif SYSTICK_CLK_SOURCE == PIOSC
            CLR_BIT(STK_CTRL, 2);
        #endif
    #endif
}

/**
	* @brief  Initializes the Systick.
	* @param  amount : amount of delay time in miliseconds.
	* @retval None
	*/
void STK_DelayMs(uint32_t t)
{
    uint32_t start, end;
    start = STK_Millis();
    end = start + t;
    if (start < end)
     { 
        while ((STK_Millis() >= start) && (STK_Millis() < end))
        { 
        // do nothing 
        } 
    } 
    else 
    { 
        while ((STK_Millis() >= start) || (STK_Millis() < end))
        {
        // do nothing
        };
    }
}

/**
	* @brief  return time elapsed since the Systick initilized.
	* @retval None
	*/
uint32_t STK_Millis(void)
{
    return msTicks;
}


/**
	* @brief  Stop the Systick timer.
	* @retval None
	*/
void STK_Stop(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK_CTRL, 1);
	
	/* Stop Timer */
	SET_BIT(STK_CTRL, 0);
	STK_LOAD = 0;
	STK_VAL  = 0;
}


/**
	* @brief  set callback function for the Systick interrupt.
	* @param  Fptr : Pointer to function.
	* @retval None
	*/
void STK_Set_CallBack(void (* Fptr) (void))
{
	STK_CallBack = Fptr;
}

/* SysTick interrupt Handler. */
void SysTick_Handler(void)  
{
	msTicks++;
	if (STK_CallBack != NULL)
	{
			STK_CallBack();
	}
}
