/**********************************************************/
/* Author    : Abdelrhman                                 */
/* Date      : 14 Sep 2022                                */
/* Version   : V01                                        */
/**********************************************************/
#ifndef GPT_INTERFACE_H
#define GPT_INTERFACE_H

#include "GPT_private.h"

typedef struct
{
	uint32_t global_operation;
	uint32_t mode;
	uint32_t count_dir;
	uint32_t init_value;
	uint32_t interrupt_mask;
                    
}GPTIM_Conf_t;




#define GPTIMER_GLOBAL_OPE_CONCAT		0x00
#define GPTIMER_GLOBAL_OPE_RTC			0x01
#define GPTIMER_GLOBAL_OPE_INDI		  0x04

#define GPTIMER_MODE_ONE_SHOT				0x01
#define GPTIMER_MODE_PERIODIC				0x02
#define GPTIMER_MODE_CAPTURE				0x03

#define GPTIMER_COUNT_UP						0x01
#define GPTIMER_COUNT_DOWN					0x00

#define GPTIMER_INT_ENABLE					0x01
#define GPTIMER_INT_DISABLE					0x00


/******************************************************************************/
/*                                                                            */
/*                      Driver exposed APIs                                   */
/*                                                                            */
/******************************************************************************/

// CLK Enable, Disable.
#define _GPT0_ENABLE_CLK()		SCGCTIMER |= (1 << 0) //Enable clock for TIMER0
#define _GPT1_ENABLE_CLK()		SCGCTIMER |= (1 << 1) //Enable clock for TIMER1
#define _GPT2_ENABLE_CLK()		SCGCTIMER |= (1 << 2) //Enable clock for TIMER2
#define _GPT3_ENABLE_CLK()		SCGCTIMER |= (1 << 3) //Enable clock for TIMER3
#define _GPT4_ENABLE_CLK()		SCGCTIMER |= (1 << 4) //Enable clock for TIMER4
#define _GPT5_ENABLE_CLK()		SCGCTIMER |= (1 << 5) //Enable clock for TIMER5

#define _GPT0_WIDE_ENABLE_CLK()		RCGCWTIMER |= (1 << 0) //Enable clock for TIMER0 WIDE
#define _GPT1_WIDE_ENABLE_CLK()		RCGCWTIMER |= (1 << 1) //Enable clock for TIMER1 WIDE
#define _GPT2_WIDE_ENABLE_CLK()		RCGCWTIMER |= (1 << 2) //Enable clock for TIMER2 WIDE
#define _GPT3_WIDE_ENABLE_CLK()		RCGCWTIMER |= (1 << 3) //Enable clock for TIMER3 WIDE
#define _GPT4_WIDE_ENABLE_CLK()		RCGCWTIMER |= (1 << 4) //Enable clock for TIMER4 WIDE
#define _GPT5_WIDE_ENABLE_CLK()		RCGCWTIMER |= (1 << 5) //Enable clock for TIMER5 WIDE


/**
	* @brief  Initializes the timer 
	* @param  *GPTx : timer Base address
	* @param  *GPT_conf_t :Pointer to the timer conf structure sent by application 
	* @retval None
	*/
void GPT_Init(GPTIM_t*, const GPTIM_Conf_t);

/**
	* @brief  Disable the timer ISR
	* @param  *GPTx : timer Base address
	* @param  *GPT_conf_t :Pointer to the timer conf structure sent by application 
	* @retval None
	*/
void GPT_Disable_Int(GPTIM_t*);

/**
	* @brief  Enable the timer interrupt (ISR) 
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Enable_Int(GPTIM_t*);

/**
	* @brief  Start the timer 
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Start_Timer(GPTIM_t*);

/**
	* @brief  Stop the timer 
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Stop_Timer(GPTIM_t*);

/**
	* @brief  Clear interrupt flag 
	* @param  *GPTx : timer Base address
	* @retval None
	*/
void GPT_Clear_Interrupt(GPTIM_t* GPTIMx);
#endif


