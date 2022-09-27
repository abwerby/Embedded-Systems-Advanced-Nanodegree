/**********************************************************/
/* Author    : Abdelrhman                                 */
/* Date      : 14 Sep 2022                                */
/* Version   : V01                                        */
/**********************************************************/
#include <stdint.h>
#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"


/**
	* @brief  Init NVIC with configiration in the config file 
	* @retval None
	*/
void NVIC_Init(void)
{
	// set preemption priority and sub priroty
	uint32_t temp_val = SCB_APINT;
	temp_val &= ~((uint32_t)((0xFFFFUL << 16UL)|(7UL << 8UL))); 
	temp_val |= ((uint32_t)APINT_KEY << 16) | (NVIC_GROUP_SUB_DISTRIBUTION << 8); 
	SCB_APINT = temp_val;
}

/**
	* @brief  Set interrupt priority 
  * @param  IRQ_id: interrupt id  
  * @param  priority: 
	* @retval None
	*/
void NVIC_SetPriority(IRQn_Type IRQ_id, uint32_t priority)
{
	NVIC->PRI[(uint32_t) IRQ_id] = (uint8_t)((priority << (5)));
}

/**
	* @brief  Enable interrupt  
  * @param  IRQ_id: interrupt id  
	* @retval None
	*/
void NVIC_EnableInterrupt (IRQn_Type IRQ_id)
{
	NVIC->EN[(uint32_t)(IRQ_id >> 5)] |= ((uint32_t)(1 << (IRQ_id & 31)));
}


/**
	* @brief  Disable interrupt  
  * @param  IRQ_id: interrupt id  
	* @retval None
	*/
void NVIC_DisableInterrupt (IRQn_Type IRQ_id)
{
	NVIC->DIS[(uint32_t)(IRQ_id >> 5)] |= ((uint32_t)(1 << (IRQ_id & 31)));
}

/**
	* @brief  Set pending flag   
  * @param  IRQ_id: interrupt id  
	* @retval None
	*/
void NVIC_SetPendingFlag(IRQn_Type IRQ_id)
{
	NVIC->PEND[(uint32_t)(IRQ_id >> 5)] |= ((uint32_t)(1 << (IRQ_id & 31)));
}

/**
	* @brief  Clear pending flag   
  * @param  IRQ_id: interrupt id  
	* @retval None
	*/
void NVIC_ClearPendingFlag(IRQn_Type IRQ_id)
{
	NVIC->UNPEND[(uint32_t)(IRQ_id >> 5)] |= ((uint32_t)(1 << (IRQ_id & 31)));
}

/**
	* @brief  Get active flag   
  * @param  IRQ_id: interrupt id  
	* @retval FLag status
	*/
uint8_t NVIC_GetActiveFlag(IRQn_Type IRQ_id)
{
	return ((uint32_t)(NVIC->ACTIVE[(uint32_t)(IRQ_id >> 5)] & ((uint32_t)(1 << (IRQ_id & 31)))));
}

