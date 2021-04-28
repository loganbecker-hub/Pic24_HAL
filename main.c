#include "config.h"
#include "GPIO_HAL.h"
#include "ADC_HAL.h"

int main(void){  
  uint16_t adc = 0;
  HAL_GPIO_Init(GPIOB, GPIO_PIN_2, GPIO_OUTPUT);
  HAL_ADC_Init(channel_1);

  while(1){
    HAL_ADC_Start(); // Start the conversion 
    if(HAL_ADC_PollForConversion(100) == 1){
      adc = HAL_ADC_GetValue(); // Get the adc value
    }
    else{
      HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
      __delay_ms(100);
    }
  }
  return 0;
}
