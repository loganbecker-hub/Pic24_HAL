#include "GPIO_HAL.h"
#include <p24FJ64GA104.h> // Header file for specific PIC24

/**
  * @brief  Initializes the GPIOx peripheral
  * @param  GPIOx: specify which Port to setup
  * @param  GPIO_PIN: specify which Pin to setup
  * @param  GPIO_MODE: specify pin as an Input or Output
  * @retval None
**/
void HAL_GPIO_Init(uint16_t GPIOx, uint16_t GPIO_PIN, uint16_t GPIO_MODE){
  /** OUTPUT MODE **/
  if(GPIO_MODE == 0U){  
    if(GPIOx == 0U){ // Port select
      TRISA &= ~(1U<<GPIO_PIN);
      LATA &= ~(1U<<GPIO_PIN); 
    }
    else if(GPIOx == 1U){
      TRISB &= ~(1U<<GPIO_PIN);
      LATB &= ~(1U<<GPIO_PIN);
    }
    else if(GPIOx == 2U){
      TRISC &= ~(1U<<GPIO_PIN);
      LATC &= ~(1U<<GPIO_PIN);
    }
  }
  /** INPUT MODE **/
  else if(GPIO_MODE == 1U){
    if(GPIOx == GPIOA){ // Port select
      TRISA |= (1U<<GPIO_PIN);
    }
    else if(GPIOx == GPIOB){
      TRISB |= (1U<<GPIO_PIN);
    }
    else if(GPIOx == GPIOC){
      TRISC |= (1U<<GPIO_PIN);
    }
  }
}

/**
  * @brief  Toggle Pin for the GPIOx peripheral
  * @param  GPIOx: Port to access
  * @param  GPIO_PIN: Pin to toggle  
  * @retval None
**/
void HAL_GPIO_TogglePin(uint16_t GPIOx, uint16_t GPIO_PIN){
  if(GPIOx == 0U){
    LATA ^= 1U<<GPIO_PIN; 
  }
  else if(GPIOx == 1U){
    LATB ^= 1U<<GPIO_PIN;
  }
  else if(GPIOx == 2U){
    LATC ^= 1U<<GPIO_PIN;
  }
}

/**
  * @brief  Writes to Pin for the GPIOx peripheral
  * @param  GPIOx: Port to access
  * @param  GPIO_PIN: Pin to write 
  * @param  GPIO_STATE: Set or Clear the pin 
  * @retval None
**/
void HAL_GPIO_WritePin(uint16_t GPIOx, uint16_t GPIO_PIN, uint16_t GPIO_STATE){
  /** Set the Pin **/
  if(GPIO_STATE == 1U){ 
    if(GPIOx == 0U){
      LATA |= 1U<<GPIO_PIN; 
    }
    else if(GPIOx == 1U){
      LATB |= 1U<<GPIO_PIN;
    }
    else if(GPIOx == 2U){
      LATC |= 1U<<GPIO_PIN;
    }
  }
  /** Clear the Pin **/
  else if(GPIO_STATE == 0U){
    if(GPIOx == 0U){
      LATA &= ~(1U<<GPIO_PIN); 
    }
    else if(GPIOx == 1U){
      LATB &= ~(1U<<GPIO_PIN);
    }
    else if(GPIOx == 2U){
      LATC &= ~(1U<<GPIO_PIN);
    }
  }
   
}