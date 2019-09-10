#ifndef SERVO_H
#define SERVO_H

#include "main.h"
#include "definition.h"

void servo(void);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM2_Init(void);

#endif
