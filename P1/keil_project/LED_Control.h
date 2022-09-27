/**********************************************************/
/* Author    : Abdelrhman                                 */
/* Date      : 18 Sep 2022                                */
/* Version   : V01                                        */
/**********************************************************/


#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#define LED_ON_TIME				  1000
#define LED_OFF_TIME				3000


void System_Init(void);
void LED_Control_ISR(void);


#endif 

