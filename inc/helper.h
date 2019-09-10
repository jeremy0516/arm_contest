#ifndef __led_button__H__
#define __led_button__H__

#include "stm32f746xx.h"
#include "definition.h"
int init_port(GPIO_TypeDef* gpio, int pin);
void set_gpio(GPIO_TypeDef* gpio, int pin);
void reset_gpio(GPIO_TypeDef* gpio, int pin);
void FPU_init();
int num_digits(int x);
int read_gpio(GPIO_TypeDef* gpio, int pin);
int init_button(GPIO_TypeDef* gpio, int button_pin);
#endif
