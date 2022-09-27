/*****************************************/
/* Author  :  Abdelrhman werby           */
/* Version :  V01                        */
/* Date    : 26 August 2022              */
/*****************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H



/**
	* @brief  Initializes the Systick.
	* @param  init_ticks : initial ticks to preload to the timer (to control the interrupt).
	* @retval None
	*/
void STK_Init(uint32_t init_ticks);

/**
	* @brief  Initializes the Systick.
	* @param  amount : amount of delay time in miliseconds.
	* @retval None
	*/
void STK_DelayMs(uint32_t amount);

/**
	* @brief  Stop the Systick timer.
	* @retval None
	*/
void STK_Stop(void);

/**
	* @brief  set callback function for the Systick interrupt.
	* @param  Fptr : Pointer to function.
	* @retval None
	*/
void STK_Set_CallBack(void (* Fptr) (void));

/**
	* @brief  return time elapsed since the Systick initilized.
	* @retval None
	*/
uint32_t STK_Millis(void);

#endif
