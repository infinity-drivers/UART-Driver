#include "stm32f4xx_hal.h"

#define TXPort GPIOA
#define TXPin GPIO_PIN_5

void usart_init(void);

UART_HandleTypeDef huart;
char message[20]="I'm Batman...\r\n";

int main(){


	HAL_Init();
	 usart_init();



	while(1){
		HAL_UART_Transmit(&huart,(uint8_t *) message, 20, 100);
		HAL_Delay(10);
	    }


	}


void SysTick_Handler(void){
	HAL_IncTick();
}

void usart_init(void){


	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init={0};
	gpio_init.Pin=GPIO_PIN_2 | GPIO_PIN_3;
	gpio_init.Mode=GPIO_MODE_AF_PP;
	gpio_init.Alternate=GPIO_AF7_USART2;
	gpio_init.Pull=GPIO_NOPULL;
	gpio_init.Speed=GPIO_SPEED_FREQ_VERY_HIGH;

	HAL_GPIO_Init(GPIOA, &gpio_init);

	huart.Instance=USART2;
	huart.Init.BaudRate=115200;
	huart.Init.WordLength=UART_WORDLENGTH_8B;
	huart.Init.StopBits=UART_STOPBITS_1;
	huart.Init.Parity=UART_PARITY_NONE;
	huart.Init.Mode=UART_MODE_TX;
	huart.Init.HwFlowCtl=UART_HWCONTROL_NONE;
	huart.Init.OverSampling=UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart);

}
