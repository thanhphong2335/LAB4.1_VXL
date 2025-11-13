/*
 * fsm_traffic.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */


#include "main.h"
#include "timer.h"
#include "button.h"

int mode=1;
void fsm_traffic_light(void){
    switch(mode){
        case 1:
            // LED0 sáng (tượng trưng cho đèn đỏ)
        	 HAL_GPIO_WritePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_B_GPIO_Port, LED_GREEN_B_Pin, GPIO_PIN_SET);

            // Nhấn nút MODE (button 0) → chuyển sang mode 2
            if(isbuttonpressed(0)){
                mode = 2;
            }
            if(isbuttonlongpressed(0)){
			   mode = 2;
		    }
            break;

        case 2:

        	 HAL_GPIO_WritePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin, GPIO_PIN_SET);
        	            HAL_GPIO_WritePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin, GPIO_PIN_SET);
        	            HAL_GPIO_WritePin(LED_GREEN_B_GPIO_Port, LED_GREEN_B_Pin, GPIO_PIN_RESET);

            if(isbuttonpressed(0)){
                mode = 3;

            }
            if(isbuttonlongpressed(0)){
			   mode = 3;

		    }
            break;

        case 3:

            HAL_GPIO_WritePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(LED_GREEN_B_GPIO_Port, LED_GREEN_B_Pin, GPIO_PIN_SET);

            if(isbuttonpressed(0)){
                mode = 4;

            }
            if(isbuttonlongpressed(0)){
			   mode = 4;

		    }
            break;

        case 4:
            // Tất cả tắt
        	 HAL_GPIO_WritePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin, GPIO_PIN_SET);
        	            HAL_GPIO_WritePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin, GPIO_PIN_SET);
        	            HAL_GPIO_WritePin(LED_GREEN_B_GPIO_Port, LED_GREEN_B_Pin, GPIO_PIN_SET);

            if(isbuttonpressed(0)){
                mode = 1; // Quay lại mode 1

            }
            if(isbuttonlongpressed(0)){
			   mode = 0;

		    }
            break;

        default:
            mode = 1;
            break;
    }
}
