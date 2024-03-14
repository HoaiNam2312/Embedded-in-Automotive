#include "stm32f10x_rcc.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void delay(uint32_t time){ 
	for(unsigned int i=0; i<time; i++){}
}

void rccConfig(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
}
void gpioConfig(){
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
int main()
{
	rccConfig();
	gpioConfig();
	while(1){
		uint16_t statusLed= 0x0080;
		for(int i =0; i<3; i++)
		{
			statusLed = statusLed<<1;
			GPIO_Write(GPIOB, statusLed);
			delay(2000);
		}
	
	}
}