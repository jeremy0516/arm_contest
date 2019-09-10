#include "delay.h"
#include "stm32f746xx.h"
#include "helper.h"
#include "timer.h"

void wait_2(float TIME){
	timer_enable(TIM2);
	timer_init(TIM2, 1600, 10000); //set timer to 1us.
	timer_start(TIM2);
	int sec = 0, last = 0;
	while(1){
		if(last!=TIM2->CNT){
			if(TIM2->CNT == 0){
				sec++;
			}
			last = TIM2->CNT;
			FPU_init();
			double now_time = sec + TIM2 -> CNT/10000.0;

			if (now_time >= TIME){      // the time executing the code above already pass through 1us.
				break;
			}
		}
	}
	timer_stop(TIM2);
}

void wait_3(float TIME){
	timer_enable(TIM3);
	timer_init(TIM3, 1600, 10000); //set timer to 1us.
	timer_start(TIM3);
	int sec = 0, last = 0;
	while(1){
		if(last!=TIM3->CNT){
			if(TIM3->CNT == 0){
				sec++;
			}
			last = TIM3->CNT;
			FPU_init();
			double now_time = sec + TIM3 -> CNT/10000.0;

			if (now_time >= TIME){      // the time executing the code above already pass through 1us.
				break;
			}
		}
	}
	timer_stop(TIM3);
}
