/*
 * led_disp.h
 *
 *  Created on: Nov 24, 2022
 *      Author: Admin
 */

#ifndef INC_LED_DISP_H_
#define INC_LED_DISP_H_

#include "main.h"

#define NUM_OF_LED 12

#define ON RESET
#define OFF SET

void clear_All_Clock();
void set_Number_on_Clock(int num);
void clear_Number_on_Clock(int num);

#endif /* INC_LED_DISP_H_ */
