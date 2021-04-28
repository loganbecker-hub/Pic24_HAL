#include "ADC_HAL.h"
#include <p24fj64ga104.h> // Header file for specific  PIC24
#define FCY 8000000UL // Clock frequency 8MHZ
#include <libpic30.h>
#include <p24FJ64GA104.h> // define FCY xxxxxUL before this in config.h otherwise error will occur

void HAL_ADC_Init(uint16_t channel){
  /** Selects channel as Analog mode to use for the ADC **/
  AD1PCFG &= ~(1U << channel);
  /** Polling setup using SAMP bit for sampling, but timers can also be used here **/
  AD1CON1 = 0x0000;
  /** Channel input select on MUX A **/
  AD1CHS = channel << 0; // positive input channel 
  AD1CHSbits.CH0NA = 0; // negative input VR-
  /** Conversion Clock Period using system clock **/
  AD1CON3bits.ADRC = 0; // Clock derived from system clock 
  AD1CON3 |=  0x1F << 8; // 31 TAD
  AD1CON3 |= (64-1) << 0; // 64 * Tcy
  /** MUX A with no scanning channels enabled**/
  AD1CON2 = 0x0000;
  AD1CON1bits.ADON = 1; // ADC module turn ON
}
void HAL_ADC_Start(void){
  AD1CON1bits.SAMP = 1; // starts sampling
  __delay_ms(1); // time to sample the value
  AD1CON1bits.SAMP = 0; // ends sampling and starts conversion
}

void HAL_ADC_Stop(void){
  /** Disables the ADC **/
  AD1CON1bits.ADON = 0; 
}

bool HAL_ADC_PollForConversion(uint16_t timeout){
  __delay_ms(timeout); // Wait time before checking for conversion status
  if(AD1CON1bits.DONE){
    return true;
  }
  else{
    return false;
  }
}

uint16_t HAL_ADC_GetValue(void){
  return (uint16_t)ADC1BUF0;
}
