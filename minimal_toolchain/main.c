/*
DEMO PROJECT: blinking LED on board - PA5 (pin 21)
*/

#include "main.h"


int main(void){
    
    // Enable GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Set output mode for GPIOA
    GPIOA->MODER |= GPIO_MODER_MODER5_0;

    while (1){
        GPIOA -> ODR ^= GPIO_ODR_ODR_5;
        for(volatile unsigned x = 0; x < 500000; x++);
    }
}