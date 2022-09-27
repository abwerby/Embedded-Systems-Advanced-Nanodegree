/*********************************************************************************/
/* Author    : Abdelrhman                                                        */
/* Version   : V01                                                               */
/* Date      : 12 Sep 2022                                                       */
/*********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include <stdint.h>

/**
  * @brief General Purpose I/O register
  */

typedef struct {                                    
  volatile uint32_t  RESERVED[255];
  volatile uint32_t  DATA;                              
  volatile uint32_t  DIR;                              
  volatile uint32_t  IS;                               
  volatile uint32_t  IBE;                               
  volatile uint32_t  IEV;                              
  volatile uint32_t  IM;                                
  volatile uint32_t  RIS;                               
  volatile uint32_t  MIS;                               
  volatile uint32_t  ICR;                              
  volatile uint32_t  AFSEL;                             
  volatile uint32_t  RESERVED1[55];
  volatile uint32_t  DR2R;                             
  volatile uint32_t  DR4R;                             
  volatile uint32_t  DR8R;                              
  volatile uint32_t  ODR;                              
  volatile uint32_t  PUR;                               
  volatile uint32_t  PDR;                               
  volatile uint32_t  SLR;                               
  volatile uint32_t  DEN;                              
  volatile uint32_t  LOCK;                              
  volatile uint32_t  CR;                                
  volatile uint32_t  AMSEL;                            
  volatile uint32_t  PCTL;                             
  volatile uint32_t  ADCCTL;                           
  volatile uint32_t  DMACTL;                            
} GPIO_t;

// Address CLK control register
#define RCGCGPIO (*(( volatile uint32_t *)0x400FE608))

// GPIO Address in AHB Bus.
#define GPIOA        ((GPIO_t *)0x40058000)            // define the boundary address of GPIO port A
#define GPIOB        ((GPIO_t *)0x40059000)            // define the boundary address of GPIO port B
#define GPIOC        ((GPIO_t *)0x4005A000)            // define the boundary address of GPIO port C
#define GPIOD        ((GPIO_t *)0x4005B000)            // define the boundary address of GPIO port D
#define GPIOE        ((GPIO_t *)0x4005C000)            // define the boundary address of GPIO port E
#define GPIOF        ((GPIO_t *)0x4005D000)            // define the boundary address of GPIO port F

// GPIO Address in APB Bus.
#define GPIOA_APB        ((GPIO_t *)0x40004000)            // define the boundary address of GPIO port A
#define GPIOB_APB        ((GPIO_t *)0x40005000)            // define the boundary address of GPIO port B
#define GPIOC_APB        ((GPIO_t *)0x4005A000)            // define the boundary address of GPIO port C
#define GPIOD_APB        ((GPIO_t *)0x40006000)            // define the boundary address of GPIO port D
#define GPIOE_APB        ((GPIO_t *)0x40007000)            // define the boundary address of GPIO port E
#define GPIOF_APB        ((GPIO_t *)0x40025000)            // define the boundary address of GPIO port F

#endif
