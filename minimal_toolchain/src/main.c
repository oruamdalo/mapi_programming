#include "main.h"
unsigned int acceso;

int main(){
  //abilito i clock di AHB(GPIOE) e APB1(TIM6)
  RCC->AHBENR|=RCC_AHBENR_GPIOEEN;
  RCC->APB1ENR|=RCC_APB1ENR_TIM6EN;
  //moderE in output: azzero e metto in output
  GPIOE->MODER &= ~GPIO_MODER_MODER12;
  GPIOE->MODER |= GPIO_MODER_MODER12_0;
  //inizializzo il led
  GPIOE->ODR &= ~GPIO_ODR_12;
  acceso=0;
  //inizializzo il timer
  TIM6->CR1 &= ~TIM_CR1_CEN;
  TIM6->SR &= ~TIM_SR_UIF;
  TIM6->CNT = ~TIM_CNT_CNT;
  TIM6->ARR=0xF424;//62500 5^6*2^2
  TIM6->PSC=0x3F;//63(+1)
  TIM6->CR1 |= TIM_CR1_CEN;
  while(1)
  {
    if(TIM6->SR==TIM_SR_UIF)
    {
      if (!acceso)
        GPIOE->ODR |= GPIO_ODR_12;
      else
        GPIOE->ODR &= ~GPIO_ODR_12;
      
      TIM6->SR &= ~TIM_SR_UIF;
      acceso=(acceso+1)%2;
    }
  }
}