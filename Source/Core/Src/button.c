/*
 * button.c
 *
 *  Created on: Nov 24, 2022
 *      Author: Admin
 */

#include "button.h"

int KeyReg0[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int button_flag[NUM_OF_BUTTON] = {0, 0, 0};

int Button[NUM_OF_BUTTON] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	button_flag[index] = 1;
}

void getKeyInput(){
	for(int index = 0; index < NUM_OF_BUTTON; index++){
		KeyReg2[index] = KeyReg1[index];
		KeyReg1[index] = KeyReg0[index];
		KeyReg0[index] = HAL_GPIO_ReadPin(GPIOA, Button[index]);
		if ((KeyReg1[index] == KeyReg0[index]) && (KeyReg1[index] == KeyReg2[index])){
			if (KeyReg2[index] != KeyReg3[index]){
				KeyReg3[index] = KeyReg2[index];

				if (KeyReg3[index] == PRESSED_STATE) subKeyProcess(index);
			}
		}
	}
}
