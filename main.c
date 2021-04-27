#include "config.h"
#include "GPIO_HAL.h"

int main(void){
  HAL_GPIO_Init(GPIOB, GPIO_PIN_1, GPIO_OUTPUT); // Set PB1 as output
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_SET); // Set pin PB1
  HAL_GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_OUTPUT);
  while(1){
    __delay_ms(500);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);
  }
  return 0;
}
