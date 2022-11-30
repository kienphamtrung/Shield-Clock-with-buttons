/*
 * button.h
 *
 *  Created on: Nov 24, 2022
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "led_disp.h"

#define NUM_OF_BUTTON 3

#define NORMAL_STATE RESET
#define PRESSED_STATE SET

int isButtonPressed(int index);

void subKeyProcess(int index);;
void getKeyInput();

#endif /* INC_BUTTON_H_ */
