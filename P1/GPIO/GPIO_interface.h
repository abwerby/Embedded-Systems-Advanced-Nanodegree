/*********************************************************************************/
/* Author    : Abdelrhamn Werby                                                  */
/* Version   : V01                                                               */
/* Date      : 12 Sep 2022                                                       */
/*********************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_private.h"


// Macros for pin state.
#define HIGH    1
#define LOW     0

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7


/* GPIO Dir Settings values */
#define GPIO_PIN_DIR_INPUT                             (0x00)
#define GPIO_PIN_DIR_OUTPUT                            (0x01)

// to set pin to altr function.
#define GPIO_PIN_ALT_FUN_MODE                          (0x01)

/* GPIO pull up/pull dwn  selection values */
#define GPIO_PIN_OPEN_DRAIN                    		   (0x01)
#define GPIO_PIN_PULL_UP                               (0x01)
#define GPIO_PIN_PULL_DOWN                             (0x02)

typedef struct
{
	uint32_t pin;            /*Specifies the GPIO pins to be configured */

	uint32_t dir;           /*Specifies the operating mode for the selected pins */
													
	uint32_t op_type;        /*Specifies the output type for the selected pins*/
	
	uint32_t set_alternate;  /* ste to one to config to alter function */
	
	uint32_t alternate;      /*Specifies the alternate function value, 
							  if the mode is set for alt function mode */                      
}GPIO_Pin_Conf_t;





/******************************************************************************/
/*                                                                            */
/*                      Driver exposed APIs                                   */
/*                                                                            */
/******************************************************************************/

// GPIO CLK Enable, Disable function.
#define _GPIOA_ENABLE_CLK()		RCGCGPIO |= (1 << 0) //Enable clock for PORTA
#define _GPIOB_ENABLE_CLK()		RCGCGPIO |= (1 << 1) //Enable clock for PORTB
#define _GPIOC_ENABLE_CLK()		RCGCGPIO |= (1 << 2) //Enable clock for PORTC
#define _GPIOD_ENABLE_CLK()		RCGCGPIO |= (1 << 3) //Enable clock for PORTD
#define _GPIOE_ENABLE_CLK()		RCGCGPIO |= (1 << 4) //Enable clock for PORTE
#define _GPIOF_ENABLE_CLK()		RCGCGPIO |= (1 << 5) //Enable clock for PORTF


/**
	* @brief  Initializes the gpio pin 
	* @param  *GPIOx : GPIO Port Base address
	* @param  *gpio_pin_conf :Pointer to the pin conf structure sent by application 
	* @retval None
	*/
void GPIO_Init(GPIO_t * GPIOx, GPIO_Pin_Conf_t * gpio_pin_conf);

/**
	* @brief  Read a value from a  given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @retval uint8_t: Value read 
	*/
uint8_t GPIO_Read_Pin(GPIO_t * GPIOx,uint8_t pin_no);

/**
	* @brief  Write a value to given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  value   : value to be written 
	* @retval None
	*/
void GPIO_Write_Pin(GPIO_t * GPIOx, uint8_t pin_no, uint8_t val);

/**
	* @brief  Write a value to port 
	* @param  *GPIOx : GPIO Port Base address
	* @param  value   : value to be written 
	* @retval None
	*/
void GPIO_Write_Port(GPIO_t * GPIOx, uint8_t val);

/**
	* @brief  Set the alternate functionality for the given pin  
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  alt_fun_value   :  alternate function to be configured with 
	* @retval None
	*/
void GPIO_set_alt_function(GPIO_t * GPIOx, uint16_t pin_no, uint16_t alt_fun_value);

/**
	* @brief  Read a value from a  given port 
	* @param  *GPIOx : GPIO Port Base address
	* @retval uint8_t: Value read 
	*/
uint8_t GPIO_Read_Port(GPIO_t * GPIOx);

#endif

