#ifndef __beeper__H__
#define __beeper__H__

#include "stm32f746xx.h"
#include "definition.h"
void beep_L(int frequency, int loud);
void beep_R(int frequency, int loud);

#endif
