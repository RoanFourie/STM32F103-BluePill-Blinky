/***************************************************************
* File     : rf_stm32f1_led.h
***************************************************************/

/***************************************************************
// Header Files Includes
***************************************************************/
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

/***************************************************************
* List of All LEDs
***************************************************************/
typedef enum
{
  LED_1 = 0,
  LED_2 = 1,
  //LED_3 = 2,
  //LED_4 = 3
}LED_NAME;

#define  TOTAL_LED   2 // total LEDs LED_NAME_t

/***************************************************************
* Status of LEDs
***************************************************************/
typedef enum {
  LED_OFF = 0,  // LED OFF
  LED_ON        // LED ON
}LED_STATUS;

/***************************************************************
* Structure of  LED
***************************************************************/
typedef struct {
  LED_NAME LED_NAME;        // Name
  GPIO_TypeDef* LED_PORT;   // Port
  const uint16_t LED_PIN;   // Pin
  const uint32_t LED_CLK;   // Clock
  LED_STATUS LED_INIT;      // status
}LED_struct;

/***************************************************************
* Global Function
***************************************************************/
void FM_Led_Init(void);
void FM_Led_Off(LED_NAME led_name);
void FM_Led_On(LED_NAME led_name);
void FM_Led_Toggle(LED_NAME led_name);

/***************************************************************/
