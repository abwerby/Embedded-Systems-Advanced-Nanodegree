/**********************************************************/
/* Author    : Abdelrhman                                 */
/* Date      : 14 Sep 2022                                */
/* Version   : V01                                        */
/**********************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct 
{
	volatile uint32_t EN[5];
	uint32_t RESEVD0[27];
	volatile uint32_t DIS[5];
	uint32_t RESEVD1[27];
	volatile uint32_t PEND[5];
	uint32_t RESEVD2[27];
	volatile uint32_t UNPEND[5];
	uint32_t RESEVD3[27];
	volatile uint32_t ACTIVE[5];
	uint32_t RESEVD4[59];
	volatile uint8_t  PRI[136];
	uint32_t RESEVD5[669];
	volatile uint32_t SWTRIG;

}NVIC_t;


#define NVIC ((volatile NVIC_t*)(0xE000E100))

#define SCB_APINT  *((volatile uint32_t*)(0xE000E000 + 0xD0C))

#define NVIC_GROUP_3_SUB_0      0x04
#define NVIC_GROUP_2_SUB_1      0x05
#define NVIC_GROUP_1_SUB_2      0x06
#define NVIC_GROUP_0_SUB_3      0x07


#define APINT_KEY				0x5FAUL

#endif

