/*
 * automatic.h
 *
 *  Created on: Oct 31, 2025
 *      Author: Thanh Phong
 */

#ifndef INC_AUTOMATIC_H_
#define INC_AUTOMATIC_H_

#include "global.h"

extern int counter0;  // Đếm thời gian cho đèn đỏ đường A
extern int counter1 ;  // Đếm thời gian cho đèn xanh đường A

extern int time_red ;    // Thời gian đèn đỏ (6 giây)
extern int time_green ;  // Thời gian đèn xanh (4 giây)
extern int time_yellow ; // Thời gian đèn vàng (2 giây)
void fsm_automatic_run();

#endif /* INC_AUTOMATIC_H_ */
