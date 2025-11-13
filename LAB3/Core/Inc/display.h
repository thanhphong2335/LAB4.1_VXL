/*
 * display.h
 *
 *  Created on: Oct 30, 2025
 *      Author: Thanh Phong
 */
#include "main.h"
#include "timer.h"

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

void update7SEG(int index);
void display7SEG(int num) ;
extern int led_buffer[4];
void turnoffled();
void updateLEDBuffer();
void printled();

void setred(int road);    // Hàm điều khiển LED đỏ
void setgreen(int road);  // Hàm điều khiển LED xanh
void setyellow(int road); // Hàm điều khiển LED vàng
#endif /* INC_DISPLAY_H_ */
