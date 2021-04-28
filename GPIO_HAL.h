/* 
 * File:   GPIO_HAL.h
 * Author: Logan
 *
 * Created on 27 April 2021, 6:17 PM
 */

#ifndef GPIO_HAL_H
#define	GPIO_HAL_H

#ifdef __cplusplus
extern "C" {
#endif
  
#include <stdint.h>
  
/** GPIO PORTS. Add more if needed here **/
#define GPIOA 0U
#define GPIOB 1U
#define GPIOC 2U

/** GPIO PINs **/
#define GPIO_PIN_0  0U
#define GPIO_PIN_1  1U
#define GPIO_PIN_2  2U
#define GPIO_PIN_3  3U
#define GPIO_PIN_4  4U
#define GPIO_PIN_5  5U
#define GPIO_PIN_6  6U
#define GPIO_PIN_7  7U
#define GPIO_PIN_8  8U
#define GPIO_PIN_9  9U
#define GPIO_PIN_10 10U
#define GPIO_PIN_11 11U
#define GPIO_PIN_12 12U
#define GPIO_PIN_13 13U
#define GPIO_PIN_14 14U
#define GPIO_PIN_15 15U
  
/** GPIO_PIN states**/  
#define GPIO_SET   1U
#define GPIO_CLEAR 0U

/** GPIO_MODE states **/
#define GPIO_OUTPUT 0U // all pins output
#define GPIO_INPUT  1U // all pins input
  
/** GPIO Function Declarations **/

/**
  * @brief  Initializes the GPIOx peripheral
  * @param  GPIOx: specify which Port to setup
  * @param  GPIO_PIN: specify which Pin to setup
  * @param  GPIO_MODE: specify pin as an Input or Output
  * @retval None
**/  
void HAL_GPIO_Init(uint16_t GPIOx, uint16_t GPIO_PIN, uint16_t GPIO_MODE);

/**
  * @brief  Toggle Pin for the GPIOx peripheral
  * @param  GPIOx: Port to access
  * @param  GPIO_PIN: Pin to toggle  
  * @retval None
**/
void HAL_GPIO_TogglePin(uint16_t GPIOx, uint16_t GPIO_PIN);

/**
  * @brief  Writes to Pin for the GPIOx peripheral
  * @param  GPIOx: Port to access
  * @param  GPIO_PIN: Pin to write 
  * @param  GPIO_STATE: Set or Clear the pin 
  * @retval None
**/
void HAL_GPIO_WritePin(uint16_t GPIOx, uint16_t GPIO_PIN, uint16_t GPIO_STATE);

#ifdef __cplusplus
}
#endif

#endif	/* GPIO_HAL_H */

