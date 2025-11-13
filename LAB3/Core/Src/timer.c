/*
 * timer.c
 *
 *  Created on: Oct 29, 2025
 *      Author: Thanh Phong
 */

#include "timer.h"
#include "scheduler.h"

#define MAX_TIMER 10


int timer_counter[MAX_TIMER];
int timer_flag[MAX_TIMER];
int TIMER_CYCLE=10;

void init_timer_system(void){
    for (int i = 0; i < MAX_TIMER; i++){
        timer_counter[i] = 0;
        timer_flag[i] = 0;
    }
}

void setTimer(int index, int duration){
    if(index >= 0 && index < MAX_TIMER){
        timer_counter[index] = duration / TIMER_CYCLE;
        timer_flag[index] = 0;
    }
}
int isTimerExpired(int index){
    if(index >= 0 && index < MAX_TIMER) return timer_flag[index];
    return 0;
}
void clearTimerFlag(int index){
    if(index >= 0 && index < MAX_TIMER)
        timer_flag[index] = 0;
}
void timer_run(){
	for (int i = 0; i < MAX_TIMER; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}

 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
 {
	 if(htim->Instance == TIM2){
		 SCH_Update();
	 }
 }
