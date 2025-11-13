/*
 * button.h
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKeyInput();
#define MAX_BUTTON 5

int isbuttonpressed (int index);
int isbuttonlongpressed (int index);
extern int button_flag[MAX_BUTTON];
extern int button_long_flag[MAX_BUTTON];

#endif /* INC_BUTTON_H_ */
