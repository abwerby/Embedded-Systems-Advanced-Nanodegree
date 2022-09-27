#include <stdint.h>
#include "GPT_private.h"
#include "GPT_interface.h"
#include "BIT_MATH.h"


/**
	* @brief  Initializes the timer 
	* @param  *GPTx : timer Base address
	* @param  GPT_conf_t :timer conf structure sent by application 
	* @retval None
	*/
void GPT_Init(GPTIM_t * GPTIMx, const GPTIM_Conf_t gptim_config_t)
{
	if (GET_BIT(GPTIMx->CTL, 8) == 0)
	{
		// config global operation (concat, individual).
		GPTIMx->CFG = gptim_config_t.global_operation;
		// config timer mode (one-shot, periodic, capture).
		GPTIMx->TAMR |= gptim_config_t.mode;
		// config count direction (down, up).
		GPTIMx->TAMR |= (gptim_config_t.count_dir << 4);
		// set start value.
		GPTIMx->TAILR = gptim_config_t.init_value;
		// config interrupt.
		GPTIMx->ICR = 0x1;
		GPTIMx->IMR |= gptim_config_t.interrupt_mask;
	}
	else
	{
		// report error, the timer already enabled
	}
}

/**
	* @brief  Disable the timer ISR
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Disable_Int(GPTIM_t* GPTIMx)
{
	CLR_BIT(GPTIMx->IMR, 0);
}

/**
	* @brief  Enable the timer interrupt (ISR) 
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Enable_Int(GPTIM_t* GPTIMx)
{
	SET_BIT(GPTIMx->IMR, 0);
}

/**
	* @brief  Start the timer 
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Start_Timer(GPTIM_t* GPTIMx)
{
	SET_BIT(GPTIMx->CTL, 0);
}

/**
	* @brief  Stop the timer 
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Stop_Timer(GPTIM_t* GPTIMx)
{
	CLR_BIT(GPTIMx->CTL, 0);
}


/**
	* @brief  Clear interrupt flag 
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Clear_Interrupt(GPTIM_t* GPTIMx)
{
	GPTIMx->ICR = 0x1;
}