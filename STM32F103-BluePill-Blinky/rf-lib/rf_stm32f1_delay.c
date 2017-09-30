/***************************************************************
* File     : rf_stm32f1_delay.c
***************************************************************/

#include "rf_stm32f1_delay.h"

static u8  fac_us=0;  // micro second count
static u16 fac_ms=0;  // mili second count

/***************************************************************
* delay Initialize
***************************************************************/
void delay_init()
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//HSI  HCLK/8
    fac_us=SystemCoreClock/8000000;						//SYSCLK/8
	fac_ms=(u16)fac_us*1000;
}

/***************************************************************
* delay in micro second
***************************************************************/
void delay_us(u32 micro_sec)
{
	u32 temp;
	SysTick->LOAD=micro_sec*fac_us; //Load
	SysTick->VAL=0x00;        		//Clear
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL =0X00;
}

/***************************************************************
* Delay in mili second
***************************************************************/
void delay_ms(u16 mili_sec)
{
	u32 temp;
	SysTick->LOAD=(u32)mili_sec*fac_ms;
	SysTick->VAL =0x00;
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL =0X00;
}
