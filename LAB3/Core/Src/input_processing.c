/*
 * input_processing.c
 *
 *  Created on: Oct 29, 2025
 *      Author: Thanh Phong
 */

  #include "main.h"
  #include "input_reading.h"

  #define N0_OF_BUTTONS 10
  enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED,BUTTON_PRESSED_MORE_THAN_1_SECOND};
  enum ButtonState buttonState[N0_OF_BUTTONS]; // FSM cho từng nút

void fsm_for_input_processing(void){
    for(int i = 0; i < N0_OF_BUTTONS; i++){
        switch(buttonState[i]){
            case BUTTON_RELEASED:
                if(is_button_pressed(i)){
                    buttonState[i] = BUTTON_PRESSED;
                    // Ghi nhận nút i vừa nhấn
                }
                break;

            case BUTTON_PRESSED:
                if(!is_button_pressed(i)){
                    buttonState[i] = BUTTON_RELEASED;
                } else {
                    if(is_button_pressed_1s(i)){
                        buttonState[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                    }
                }
                break;

            case BUTTON_PRESSED_MORE_THAN_1_SECOND:
                if(!is_button_pressed(i)){
                    buttonState[i] = BUTTON_RELEASED;
                }
                break;
        }
    }
}
