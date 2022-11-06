/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Chung Thinh
 */
#include "button.h"

int KeyReg0[NUMBER_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[NUMBER_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[NUMBER_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[NUMBER_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeForKeyPress[NUMBER_OF_BUTTON]={300,300,300};
int button_flag[NUMBER_OF_BUTTON]={};

int isButtonPressed(int index){
	if(button_flag[index] == 1)
	{
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	button_flag[index] = 1;
}

void getKeyInput(){
	for(int i = 0;i < NUMBER_OF_BUTTON; i++)
	{
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		switch(i)
		{
			case 0:
			 KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
			 break;
			case 1:
			 KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
			 break;
			case 2:
			 KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
			 break;
		}
		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
		  if (KeyReg3[i] != KeyReg2[i]){
			  KeyReg3[i] = KeyReg2[i];

			  if (KeyReg2[i] == PRESSED_STATE){
				  TimeForKeyPress[i] = 300;
				  subKeyProcess(i);
			  }
		  }else{
			  TimeForKeyPress[i] --;
			  if (TimeForKeyPress[i] == 0){
				  if (KeyReg2[i] == PRESSED_STATE){
					  subKeyProcess(i);
				  }
				  TimeForKeyPress[i] = 100;
			  }

		  }
		}
	}
}
