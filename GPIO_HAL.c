#include "GPIO_HAL.h"
#include <p24FJ64GA104.h> // Header file for specific PIC24

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