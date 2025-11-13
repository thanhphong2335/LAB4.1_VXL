/*
 * button.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */
#include "button.h"
#include "main.h"

GPIO_TypeDef* ButtonPort[MAX_BUTTON] = {BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port, BUTTON_3_GPIO_Port};
uint16_t      ButtonPin[MAX_BUTTON]  = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};

int KeyReg0[MAX_BUTTON] = {NORMAL_STATE};
int KeyReg1[MAX_BUTTON] = {NORMAL_STATE};
int KeyReg2[MAX_BUTTON] = {NORMAL_STATE};
int KeyReg3[MAX_BUTTON] = {NORMAL_STATE};
int timerforkeypress[MAX_BUTTON]={200};

int button_flag[MAX_BUTTON] = {0};
int button_long_flag[MAX_BUTTON] = {0};

int isbuttonpressed (int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isbuttonlongpressed (int index) {
	if (button_long_flag[index] == 1) {
		button_long_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subkeyprocess (int index) {
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	button_flag[index] = 1;
}
void getKeyInput() {
    for(int i = 0; i < MAX_BUTTON; i++) {
        KeyReg0[i] = KeyReg1[i];
        KeyReg1[i] = KeyReg2[i];
        KeyReg2[i] = HAL_GPIO_ReadPin(ButtonPort[i], ButtonPin[i]);

        if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
            // Nếu giá trị ổn định
            if(KeyReg3[i] != KeyReg2[i]) {
                KeyReg3[i] = KeyReg2[i];

                // Khi vừa nhấn xuống
                if(KeyReg2[i] == PRESSED_STATE) {
                    timerforkeypress[i] = 200; // ~2s nếu timer 10ms
                } else {
                    // Khi nhả ra
                    if(timerforkeypress[i] > 0 && button_long_flag[i] == 0) {
                        // Nhả ra trước khi hết 2s → là nhấn ngắn
                        button_flag[i] = 1;
                    }
                    timerforkeypress[i] = 0;
                    button_long_flag[i] = 0;
                }
            } else {
                // Nếu đang giữ nút
                if(KeyReg2[i] == PRESSED_STATE) {
                    if(timerforkeypress[i] > 0) {
                        timerforkeypress[i]--;
                        if(timerforkeypress[i] == 0) {
                            // Hết 2s mà vẫn giữ → là nhấn đè
                            button_long_flag[i] = 1;
                        }
                    }
                }
            }
        }
    }
}

