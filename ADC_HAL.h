/* 
 * File:   ADC_HAL.h
 * Author: Logan
 *
 * Created on 28 April 2021, 9:48 AM
 */

#ifndef ADC_HAL_H
#define	ADC_HAL_H

#ifdef	__cplusplus
extern "C" {
#endif
  
#include <stdint.h>
#include <stdbool.h>

/** ADC Channel PINs **/
#define channel_0  0U
#define channel_1  1U
#define channel_2  2U
#define channel_3  3U
#define channel_4  4U
#define channel_5  5U
#define channel_6  6U
#define channel_7  7U
#define channel_8  8U
#define channel_9  9U
#define channel_10 10U
#define channel_11 11U
#define channel_12 12U
#define channel_13 13U
#define channel_14 14U
#define channel_15 15U
  
/** ADC Function Declarations for Polling **/

/**
  * @brief  Initializes the ADC1 peripheral
  * @param  channel : Specify which ANx pin to use
  * @retval None
**/  
void HAL_ADC_Init(uint16_t channel);

/**
  * @brief  Turns on ADC module 
  * @retval None
**/ 
void HAL_ADC_Start(void);

/**
  * @brief  Turns off the ADC module
  * @retval None
**/ 
void HAL_ADC_Stop(void);

/**
  * @brief  Checks if the ADC completed a conversion
  * @param  timeout : The time to wait for the ADC to do a conversion
  * @retval Returns True or False for a conversion
**/ 
bool HAL_ADC_PollForConversion(uint16_t timeout);

/**
  * @brief  Gets the value of the Conversion
  * @retval Returns the ADC Result
**/ 
uint16_t HAL_ADC_GetValue(void);

/** ADC Function Declarations for Interrupts **/
void HAL_ADC_Start_IT(void);
void HAL_ADC_Stop_IT(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_HAL_H */
