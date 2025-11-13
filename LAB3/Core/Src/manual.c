/*
 * manual.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */

#include "manual.h"
#include "global.h"
#include "automatic.h"
int temp_red = 1;
int temp_green = 1;
int temp_yellow = 1;
void fsm_manual_run(){
	switch(status){
		case MAN_RED:
			updateLEDBuffer(2, temp_red);

			if(isbuttonpressed(0)){
				status=MAN_YELLOW;
				turnoffled(); // Tắt đèn đỏ trước khi chuyển sang vàng
				setTimer(4, 500);
			}
			if(isbuttonpressed(1)){
				temp_red++;
				updateLEDBuffer(2, temp_red); // Cập nhật hiển thị ngay
			}
			if(isbuttonpressed(2)){
				check();
				time_red = temp_red;
				time_green = temp_green;
				time_yellow = temp_yellow;
				status = INIT;
				turnoffled(); // Tắt tất cả đèn trước khi về AUTO
				counter0 = time_red;
				counter1 = time_green;
				setTimer(0, 1000);
				setTimer(1, counter1*1000);
				updateLEDBuffer(counter0, counter1);
			}
			if(isTimerExpired(4)){
				// Chỉ toggle đèn đỏ
				HAL_GPIO_TogglePin(LED_RED_A_GPIO_Port, LED_RED_A_Pin);
				HAL_GPIO_TogglePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin);
				setTimer(4, 500);
			}
			break;

		case MAN_YELLOW:
		    updateLEDBuffer(3, temp_yellow);

		    if(isbuttonpressed(0)){
		    	status = MAN_GREEN;
		    	turnoffled(); // Tắt đèn vàng trước khi chuyển sang xanh
		    	setTimer(4, 500);
		    }
		    if(isbuttonpressed(1)){
		    	temp_yellow++;
		    	updateLEDBuffer(3, temp_yellow); // Cập nhật hiển thị ngay
		    }
		    if(isbuttonpressed(2)){
		    	check();
		        time_red = temp_red;
		        time_green = temp_green;
		        time_yellow = temp_yellow;
		        status = INIT;
		        turnoffled(); // Tắt tất cả đèn trước khi về AUTO
		        counter0 = time_red;
		        counter1 = time_green;
		        setTimer(0, 1000);
		        setTimer(1, counter1*1000);
		        updateLEDBuffer(counter0, counter1);
		    }
		    if(isTimerExpired(4)){
		        // Chỉ toggle đèn vàng
		        HAL_GPIO_TogglePin(LED_YELLOW_A_GPIO_Port, LED_YELLOW_A_Pin);
		        HAL_GPIO_TogglePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin);
		        setTimer(4, 500);
		    }
		    break;

		case MAN_GREEN:
		    updateLEDBuffer(4, temp_green);

		    if(isbuttonpressed(0)){
		    	status = INIT; // Quay về AUTO mode
		    	turnoffled(); // Tắt tất cả đèn
		    }
		    if(isbuttonpressed(1)){
		    	temp_green++;
		    	updateLEDBuffer(4, temp_green); // Cập nhật hiển thị ngay
		    }
		    if(isbuttonpressed(2)){
		    	check();
		        time_red = temp_red;
		        time_green = temp_green;
		        time_yellow = temp_yellow;

		        status = INIT;
		        turnoffled(); // Tắt tất cả đèn trước khi về AUTO
		        counter0 = time_red;
		        counter1 = time_green;
		        setTimer(0, 1000);
		        setTimer(1, counter1*1000);
		        updateLEDBuffer(counter0, counter1);
		    }
		    if(isTimerExpired(4)){
		        // Chỉ toggle đèn xanh
		        HAL_GPIO_TogglePin(LED_GREEN_A_GPIO_Port, LED_GREEN_A_Pin);
		        HAL_GPIO_TogglePin(LED_GREEN_B_GPIO_Port, LED_GREEN_B_Pin);
		        setTimer(4, 500);
		    }
		    break;
	}
}
