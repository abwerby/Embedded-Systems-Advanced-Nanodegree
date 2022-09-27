/**********************************************************/
/* Author    : Abdelrhman                                 */
/* Date      : 14 Sep 2022                                */
/* Version   : V01                                        */
/**********************************************************/

#ifndef GPT_PRIVATE_H
#define GPT_PRIVATE_H

typedef struct {                                 
  volatile uint32_t  CFG;                               
  volatile uint32_t  TAMR;                             
  volatile uint32_t  TBMR;                              
  volatile uint32_t  CTL;                              
  volatile uint32_t  SYNC;                              
  volatile uint32_t  RESERVED;
  volatile uint32_t  IMR;                              
  volatile uint32_t  RIS;                               
  volatile uint32_t  MIS;                              
  volatile uint32_t  ICR;                              
  volatile uint32_t  TAILR;                            
  volatile uint32_t  TBILR;                           
  volatile uint32_t  TAMATCHR;                    
  volatile uint32_t  TBMATCHR;
  volatile uint32_t  TAPR;
  volatile uint32_t  TBPR;                              
  volatile uint32_t  TBPMR;                             
  volatile uint32_t  TAR;                               
  volatile uint32_t  TBR;                               
  volatile uint32_t  TAV;                              
  volatile uint32_t  TBV;                               
  volatile uint32_t  RTCPD;                             
  volatile uint32_t  TAPS;                              
  volatile uint32_t  TBPS;                              
  volatile uint32_t  TAPV;                              
  volatile uint32_t  TBPV;                             
  volatile  uint32_t  RESERVED1[981];
  volatile uint32_t  PP;                                
} GPTIM_t;


#define TIMER0			((GPTIM_t *)0x40030000)
#define TIMER1			((GPTIM_t *)0x40031000)
#define TIMER2			((GPTIM_t *)0x40032000)
#define TIMER3			((GPTIM_t *)0x40033000)
#define TIMER4		  ((GPTIM_t *)0x40034000)
#define TIMER5		  ((GPTIM_t *)0x40035000)

#define WIDE_TIMER0		 ((GPTIM_t *)0x40036000)
#define WIDE_TIMER1		 ((GPTIM_t *)0x40037000)
#define WIDE_TIMER2		 ((GPTIM_t *)0x4004C000)
#define WIDE_TIMER3		 ((GPTIM_t *)0x4004D000)
#define WIDE_TIMER4		 ((GPTIM_t *)0x4004E000)
#define WIDE_TIMER5		 ((GPTIM_t *)0x4004F000)

#define SCGCTIMER  	(*(( volatile uint32_t *) 0x400FE604))
#define RCGCWTIMER 	(*(( volatile uint32_t *)0x400FE65C))


#endif

