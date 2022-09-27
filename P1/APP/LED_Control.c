#include <stdint.h>
#include "GPIO_interface.h"
#include "GPT_interface.h"
#include "STK_interface.h"
#include "LED_Control.h"

uint32_t led_time = LED_OFF_TIME;
uint32_t pre_led_time = LED_OFF_TIME;
uint8_t state = HIGH;

void System_Init(void)
{
	/* Init Systick timer with 160000 init ticks to fire interrupt every 1 ms at CPU CLK 16 MHz */
	STK_Init(16000UL);
	
	/* Enable GPIOF CLK */
	_GPIOF_ENABLE_CLK();
	
	/* Config pin 3 as output for the led */
	GPIO_Pin_Conf_t pin_confg;
	pin_confg.pin = PIN3;
	pin_confg.dir = GPIO_PIN_DIR_OUTPUT;
	pin_confg.op_type = GPIO_PIN_OPEN_DRAIN;
	pin_confg.set_alternate = 0;
	GPIO_Init(GPIOF_APB, &pin_confg);
	
	/* set the led control callback function */
	STK_Set_CallBack(LED_Control_ISR);
}


void LED_Control_ISR()
{
	if (led_time > 0)
	{
		led_time--;
	}
	else
	{
		GPIO_Write_Pin(GPIOF_APB, PIN3, state);
		state = !state;
		if (pre_led_time == LED_OFF_TIME)
		{
			led_time = LED_ON_TIME;
			pre_led_time = LED_ON_TIME;
		}
		else
		{
			led_time = LED_OFF_TIME;
			pre_led_time = LED_OFF_TIME;
		}
	}
}