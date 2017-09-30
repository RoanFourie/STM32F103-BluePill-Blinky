/***************************************************************
* File     : rf_stm32f1_led.c
***************************************************************/

#include "rf_stm32f1_led.h"

/***************************************************************
* All LEDs on Stm32f1 discovery board
***************************************************************/
LED_struct LED[] = {
  //Name, PORT , PIN       , CLOCK            , Init
  {LED_1,GPIOC,GPIO_Pin_13,RCC_APB2Periph_GPIOC,LED_OFF},    // PC13 = On Board User LED
  {LED_2,GPIOB,GPIO_Pin_8,RCC_APB2Periph_GPIOB,LED_OFF},    // PB8 = External configured LED (i.e. on Breadboard
};

/***************************************************************
* Initialize all LEDs
***************************************************************/
void FM_Led_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  LED_NAME led_name;

  for(led_name=0;led_name<TOTAL_LED;led_name++) {
    // Clock Enable
    RCC_APB2PeriphClockCmd(LED[led_name].LED_CLK, ENABLE);

    // Config as digital output
    GPIO_InitStructure.GPIO_Pin = LED[led_name].LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED[led_name].LED_PORT, &GPIO_InitStructure);
  }
}

/***************************************************************
* LED off
***************************************************************/
void FM_Led_Off(LED_NAME led_name)
{
  GPIO_WriteBit(LED[led_name].LED_PORT,LED[led_name].LED_PIN, Bit_SET);
}

/***************************************************************
* LED on
***************************************************************/
void FM_Led_On(LED_NAME led_name)
{
  GPIO_WriteBit(LED[led_name].LED_PORT,LED[led_name].LED_PIN, Bit_RESET);
}

/***************************************************************
* LED toggle
***************************************************************/
void FM_Led_Toggle(LED_NAME led_name)
{
  LED[led_name].LED_PORT->ODR ^= LED[led_name].LED_PIN;
}
