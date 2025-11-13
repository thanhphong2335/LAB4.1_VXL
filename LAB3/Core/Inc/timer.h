/*
 * timer.h
 *
 *  Created on: Oct 29, 2025
 *      Author: Thanh Phong
 */
#include "main.h"
#include "button.h"

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

void init_timer_system(void);
void setTimer(int index, int duration);
int isTimerExpired(int index);
void clearTimerFlag(int index);
void timer_run();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_TIMER_H_ */
