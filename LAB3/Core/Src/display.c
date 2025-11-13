/*
 * display.c
 *
 *  Created on: Oct 30, 2025
 *      Author: Thanh Phong
 */
#include "display.h"
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index){
	 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);

	    switch (index) {
	        case 0:
	            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);  // Kích hoạt EN0
	            display7SEG(led_buffer[0]);
	            break;
	        case 1:
	            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);  // Kích hoạt EN1
	            display7SEG(led_buffer[1]);
	            break;
	        case 2:
	            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);  // Kích hoạt EN2
	            display7SEG(led_buffer[2]);
	            break;
	        case 3:
	            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);  // Kích hoạt EN3
	            display7SEG(led_buffer[3]);
	            break;
	        default:
	            break;
	    }
}

void display7SEG(int num) {
			HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
		    switch(num) {
		        case 0:
		            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		            break;

		        case 1:
		            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            break;

		        case 2:
		        	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		            break;

		        case 3:
		            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		            break;

		        case 4:
		            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		            break;

		        case 5:
		            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		            break;

		        case 6:
		            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		            break;

		        case 7:
		            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            break;

		        case 8:
		            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		            break;

		        case 9:
		            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		            HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		            break;
		    }
		}



void updateLEDBuffer(int time1, int time2) {
	if(time1 < 0) time1 = 0;
	    if(time2 < 0) time2 = 0;
    led_buffer[0] = time1 / 10;
    led_buffer[1] = time1 % 10;
    led_buffer[2] = time2 / 10;
    led_buffer[3] = time2 % 10;
}
void turnoffled(){
	HAL_GPIO_WritePin(LED_RED_A_GPIO_Port, LED_RED_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_A_GPIO_Port, LED_YELLOW_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_A_GPIO_Port, LED_GREEN_A_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_B_GPIO_Port,LED_GREEN_B_Pin, GPIO_PIN_SET);
}
//road A=0 road B =1
void setred(int road){
	if(road ==0){
		HAL_GPIO_WritePin(LED_RED_A_GPIO_Port, LED_RED_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW_A_GPIO_Port, LED_YELLOW_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_A_GPIO_Port, LED_GREEN_A_Pin, GPIO_PIN_SET);
	}
	if(road ==1){
		HAL_GPIO_WritePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_B_GPIO_Port,LED_GREEN_B_Pin, GPIO_PIN_SET);
	}
}


void setgreen(int road){
	if(road ==0){
		HAL_GPIO_WritePin(LED_RED_A_GPIO_Port, LED_RED_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_A_GPIO_Port, LED_YELLOW_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_A_GPIO_Port, LED_GREEN_A_Pin, GPIO_PIN_RESET);
	}
	if(road ==1){
		HAL_GPIO_WritePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_B_GPIO_Port,LED_GREEN_B_Pin, GPIO_PIN_RESET);
	}
}


void setyellow(int road){
	if(road ==0){
		HAL_GPIO_WritePin(LED_RED_A_GPIO_Port, LED_RED_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_A_GPIO_Port, LED_YELLOW_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_A_GPIO_Port, LED_GREEN_A_Pin, GPIO_PIN_SET);
	}
	if(road ==1){
		HAL_GPIO_WritePin(LED_RED_B_GPIO_Port, LED_RED_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_B_GPIO_Port, LED_YELLOW_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_B_GPIO_Port,LED_GREEN_B_Pin, GPIO_PIN_SET);
	}
}

void printled(){
    	update7SEG(index_led);
        index_led++;
		if (index_led >= MAX_LED) index_led = 0;
}
