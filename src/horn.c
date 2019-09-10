#include "stm32f746xx.h"
#include "helper.h"
#include "timer.h"
#include "definition.h"
#include "horn.h"

// make beeper can buzzer at a specific frequency.
void beep_L(int frequency, int loud){
        // Cause we want to use floating points we need to init FPU
    FPU_init();
    GPIO_init_AF();
    init_port(LHORN_gpio, LHORN_pin);
    timer_enable(TIM13);
    timer_init(TIM13,1,20);
    PWM_channel_init();
    timer_start(TIM13);
    //int freq[7]={523,587,659,698,784,880,988};
    int state=0;

    timer_init(TIM13,40,50000/frequency);
    timer_start(TIM13);

    for(int i=0;i<loud;i++){
        if(TIM13->CNT==0){
            if(state==0){
                set_gpio(LHORN_gpio, LHORN_pin);
            }
            if(state==1){
                reset_gpio(LHORN_gpio, LHORN_pin);
            }
            state=!state;
        }
    }
}


void beep_R(int frequency, int loud){
        // Cause we want to use floating points we need to init FPU
    FPU_init();
    GPIO_init_AF2();
    init_port(RHORN_gpio, RHORN_pin);
    timer_enable(TIM14);
    timer_init(TIM14,1,20);
    PWM_channel_init();
    timer_start(TIM14);
    //int freq[7]={523,587,659,698,784,880,988};
    int state=0;

    timer_init(TIM14,40,50000/frequency);
    timer_start(TIM14);

    for(int i=0;i<loud;i++){
        if(TIM14->CNT==0){
            if(state==0){
                set_gpio(RHORN_gpio, RHORN_pin);
            }
            if(state==1){
                reset_gpio(RHORN_gpio, RHORN_pin);
            }
            state=!state;
        }
    }
}
