/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   AUTHOR:          Roan Fourie
   DATE CREATED:    2017-Week-39
   DATE CHANGED:    2017-Week-39

**********************************************************************/
#include "stm32f10x_conf.h"
#include "rf_stm32f1_led.h"
#include "rf_stm32f1_delay.h"

static void button_setup(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

	// Clock Enable
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // Configure as digital input
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

int main(void)
{
    // initialize the system frequency
    SystemInit();
    // Delay initialize
    delay_init();
    // all LED initialize
    FM_Led_Init();
    // Initialize the button
    button_setup();

  while(1)
  {
      if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15))
      {
        FM_Led_Toggle(LED_1);
        FM_Led_Toggle(LED_2);
      } else {
        FM_Led_Off(LED_2);
        FM_Led_Off(LED_1);
      }
        // Delay for half second
       delay_ms(500);
  }
}
