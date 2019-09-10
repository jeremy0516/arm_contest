#include "helper.h"

int init_port(GPIO_TypeDef* gpio, int pin){
	// Enable AHB2 Clock
	if(gpio==GPIOA){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	}
	else if(gpio==GPIOB){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	}
	else if(gpio==GPIOC){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	}
	else if(gpio==GPIOF){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	}
	else if(gpio==GPIOG){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	}
	else if(gpio==GPIOH){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	}
	else if(gpio==GPIOI){
	}
	else{
		// Error! Add other cases to suit other GPIO pins
		return -1;
	}

	// Set GPIO pins to output mode (01)
	// First Clear bits(&) then set bits(|)
	gpio->MODER &= ~(0b11 << (2*pin));
	gpio->MODER |= (0b01 << (2*pin));

	return 0;
}

int read_gpio(GPIO_TypeDef* gpio, int pin){
	return (gpio->IDR >> pin) & 1;
}

void set_gpio(GPIO_TypeDef* gpio, int pin){
	gpio->BSRR |= (1 << pin);
}

void reset_gpio(GPIO_TypeDef* gpio, int pin){
	gpio->BSRR |= (1 << (pin+16));
}



void FPU_init(){
	// Setup FPU
	SCB->CPACR |= (0xF << 20);
	__DSB();
	__ISB();
}

int num_digits(int x){
	if(x == 0){
		return 1;
	}
	int res = 0;
	while(x){
		res++;
		x /= 10;
	}
	return res;
}

int init_button(GPIO_TypeDef* gpio, int button_pin){
	// Enable AHB2 Clock
	if(gpio==GPIOC){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	}
	else if(gpio==GPIOB){
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	}
	else{
		// Error! Add other cases to suit other GPIO pins
		return -1;
	}

	// Set GPIO pins to input mode (00)
	// First Clear bits(&) then set bits(|)
	gpio->MODER &= ~(0b11 << (2*button_pin));
	gpio->MODER |= (0b00 << (2*button_pin));

	return 0;
}
