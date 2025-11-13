/*
 * automatic.c
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */

#include "automatic.h"

int counter0 = 0;  // Đếm thời gian cho đèn đỏ đường A
int counter1 = 0;  // Đếm thời gian cho đèn xanh đường A

int time_red = 6;    // Thời gian đèn đỏ (6 giây)
int time_green = 4;  // Thời gian đèn xanh (4 giây)
int time_yellow = 2; // Thời gian đèn vàng (2 giây)

void fsm_automatic_run() {

    switch (status) {
        case INIT:
            // Khởi tạo: Tắt tất cả các LED và thiết lập thời gian cho các đèn

            turnoffled();  // Hàm tắt tất cả các LED
            counter0 = time_red;
            counter1 = time_green;
            status = AUTO_RED_GREEN;  // Chuyển sang chế độ AUTO_RED_GREEN
            setTimer(1, time_green * 1000);  // Đặt timer cho đèn đỏ đường A
            setTimer(0, 1000);  // Đặt timer chung cho các chế độ
            break;

        case AUTO_RED_GREEN:

            setred(0);
            setgreen(1);

            if (isTimerExpired(0)) {
                counter0--;  // Giảm thời gian đèn đỏ đường A
                counter1--;  // Giảm thời gian đèn xanh đường B
                updateLEDBuffer(counter0, counter1);  // Cập nhật LED 7-segment
                setTimer(0, 1000);  // Đặt lại timer cho đèn đỏ đường A
            }

            // Sau khi đếm hết thời gian đèn đỏ và đèn xanh, chuyển sang chế độ AUTO_YELLOW
            if (isTimerExpired(1)) {
                setyellow(1);
                counter0 = time_red-time_green;  // Đặt lại thời gian cho đèn vàng
                counter1 = time_yellow;
                setTimer(1, time_yellow * 1000);  // Đặt timer cho đèn vàng
                status = AUTO_RED_YELLOW;  // Chuyển sang chế độ AUTO_YELLOW
                updateLEDBuffer(counter0, counter1);
                setTimer(0, 1000);

            }
            break;

        case AUTO_RED_YELLOW:

            // Chế độ đèn vàng sáng trên cả hai đường
            setred(0);  // Đèn đỏ tắt

            setyellow(1);  // Đèn vàng sáng
            if (isTimerExpired(0)) {
				counter0--;  // Giảm thời gian đèn xanh đường A
				counter1--;  // Giảm thời gian đèn đỏ đường B
				updateLEDBuffer(counter0, counter1);  // Cập nhật LED 7-segment
				setTimer(0, 1000);  // Đặt lại timer cho đèn xanh đường A
			}
            // Sau khi đếm hết thời gian đèn vàng, chuyển sang chế độ AUTO_GREEN_RED
            if (isTimerExpired(1)) {
                counter0 = time_green;  // Đặt thời gian cho đèn xanh đường A
                counter1 = time_red;    // Đặt thời gian cho đèn đỏ đường B
                setTimer(1, time_green * 1000);  // Đặt timer cho đèn xanh đường A
                setTimer(0, 1000);
                status = AUTO_GREEN_RED;  // Chuyển sang chế độ AUTO_GREEN_RED
                updateLEDBuffer(counter0, counter1);
            }
            break;

        case AUTO_GREEN_RED:

            // Chế độ đèn xanh đường A và đèn đỏ đường B sáng
            setred(1);  // Đèn đỏ đường A sáng
            setgreen(0);  // Đèn xanh đường A sáng


            if (isTimerExpired(0)) {
                counter0--;  // Giảm thời gian đèn xanh đường A
                counter1--;  // Giảm thời gian đèn đỏ đường B
                updateLEDBuffer(counter0, counter1);  // Cập nhật LED 7-segment
                setTimer(0, 1000);  // Đặt lại timer cho đèn xanh đường A
            }

            // Sau khi đếm hết thời gian đèn xanh và đèn đỏ, quay lại chế độ AUTO_RED_GREEN
            if (isTimerExpired(1)) {
            	counter0 = time_yellow;
            	counter1 = time_red;
                setTimer(0, 1000);  // Đặt lại timer cho đèn đỏ đường A
                setTimer(1, time_red * 1000);  // Đặt lại timer cho đèn đỏ đường B
                status = AUTO_YELLOW_RED;  // Quay lại chế độ AUTO_RED_GREEN
                updateLEDBuffer(counter0, counter1);
                setTimer(0, 1000);
            }
            break;
        case AUTO_YELLOW_RED:

			setyellow(0);
			setred(1);

			if (isTimerExpired(0) == 1) {
				counter0--;
				counter1--;
				updateLEDBuffer(counter0, counter1);
				setTimer(0, 1000);
			}

			if (isTimerExpired(1) == 1){
				status = AUTO_RED_GREEN;
				counter0 = time_red;
				counter1= time_green;
				setTimer(1, time_green * 1000);
				updateLEDBuffer(counter0, counter1);
				setTimer(0, 1000);
			}
			break;

        default:
            status = AUTO_RED_GREEN;  // Quay lại chế độ AUTO_RED_GREEN nếu có lỗi
            break;
    }
}
