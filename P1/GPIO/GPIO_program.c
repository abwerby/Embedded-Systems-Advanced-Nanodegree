#include <stdint.h>
#include "GPIO_private.h"
#include "GPIO_interface.h"


/**
	* @brief  Configures the direction of a pin : input, output 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  dir   : dir to be configured
	* @retval None
	*/
void GPIO_configure_pin_dir(GPIO_t *GPIOx, uint8_t pin_no, uint8_t dir)
{
	GPIOx->DIR |= (uint8_t)(dir << pin_no);
}


/**
	* @brief  Configures the output type of a pin  
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  op_type   : output type to be configured with 
	* @retval None
	*/
void GPIO_configure_pin_otype(GPIO_t *GPIOx, uint16_t pin_no, uint32_t op_type)
{
	if (op_type == GPIO_PIN_OPEN_DRAIN)
		GPIOx->ODR |= (op_type << pin_no);
	else if (op_type == GPIO_PIN_PULL_UP)
		GPIOx->PUR |= (op_type << pin_no);
	else if (op_type == GPIO_PIN_PULL_DOWN)
		GPIOx->PDR |= (op_type << pin_no);
}

/**
	* @brief  Set the alternate functionality for the given pin  
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  alt_fun_value   :  alternate function to be configured with 
	* @retval None
	*/
void GPIO_set_alt_function(GPIO_t * GPIOx, uint16_t pin_no, uint16_t alt_fun_value)
{
	GPIOx->AFSEL |= (1 << pin_no);
	GPIOx->PCTL  |= (alt_fun_value << (pin_no << 2));
}	

/**
	* @brief  Initializes the gpio pin 
	* @param  *GPIOx : GPIO Port Base address
	* @param  *gpio_pin_conf :Pointer to the pin conf structure sent by application 
	* @retval None
	*/
void GPIO_Init(GPIO_t * GPIOx, GPIO_Pin_Conf_t * gpio_pin_conf)
{
	GPIO_configure_pin_dir(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->dir);
	if (gpio_pin_conf->set_alternate == GPIO_PIN_ALT_FUN_MODE)
	{
		GPIO_set_alt_function(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->alternate);
	}
	GPIO_configure_pin_otype(GPIOx,gpio_pin_conf->pin, gpio_pin_conf->op_type);
	GPIOx->DEN |= (1 << gpio_pin_conf->pin);
}

/**
	* @brief  Write a value to given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @param  value  : value to be written 
	* @retval None
	*/
void GPIO_Write_Pin(GPIO_t * GPIOx, uint8_t pin_no, uint8_t val)
{
	if (val)
		*(uint32_t *)(((uint32_t) GPIOx) + (0x3FC)) |= (1 << pin_no);
	else
		*(uint32_t *)(((uint32_t) GPIOx) + (0x3FC)) &= ~(1 << pin_no);
}

/**
	* @brief  Write a value to port 
	* @param  *GPIOx : GPIO Port Base address
	* @param  value  : value to be written 
	* @retval None
	*/
void GPIO_Write_Port(GPIO_t * GPIOx, uint8_t val)
{
	*(uint32_t *)(((uint32_t) GPIOx) + (0x3FC)) = val;
}

/**
	* @brief  Read a value from a  given pin number 
	* @param  *GPIOx : GPIO Port Base address
	* @param  pin_no : GPIO pin number 
	* @retval uint8_t: Value read 
	*/
uint8_t GPIO_Read_Pin(GPIO_t * GPIOx,uint8_t pin_no)
{
	
	uint8_t value ; 
	value = (*((uint32_t *)(((uint32_t) GPIOx) + (0x3FC))) & (1 << pin_no)) >> pin_no;
	return value ;
}


/**
	* @brief  Read a value from a  given port 
	* @param  *GPIOx : GPIO Port Base address
	* @retval uint8_t: Value read 
	*/
uint8_t GPIO_Read_Port(GPIO_t * GPIOx)
{
	return*((uint32_t *)(((uint32_t) GPIOx) + (0x3FC)));
}
