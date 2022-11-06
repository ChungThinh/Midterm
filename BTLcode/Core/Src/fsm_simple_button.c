/*
 * fsm_simple_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Chung Thinh
 */
#include "fsm_simple_button.h"

void display()
{
	if(timer1_flag == 1)
	{
		display7SEG(counter);
		setTimer1(250);
	}
	if(timer2_flag == 1)
	{
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		setTimer2(1000);
	}
	if(timer3_flag == 1)
	{
		status = NOPRESS;
		setTimer3(10000);
	}
}

void fsm_simple_button_run()
{
	switch(status)
	{
		case INIT:
			display7SEG(counter);
			setTimer1(250);
			setTimer2(1000);
			setTimer3(10000);
			setTimer4(250);
			status = NORMAL;
			break;
		case NORMAL:
			display();
			if(isButtonPressed(0) == 1)
			{
				status = RESETSTATE;
			}
			if(isButtonPressed(1) == 1)
			{
				status = INCSTATE;
			}
			if(isButtonPressed(2) == 1)
			{
				status = DECSTATE;
			}
			break;
		case RESETSTATE:
			setTimer3(10000);
			counter = 0;
			status = NORMAL;
			break;
		case INCSTATE:
			setTimer3(10000);
			if(counter == 9)
				counter = 0;
			else counter ++;
			 status = NORMAL;
			break;
		case DECSTATE:
			setTimer3(10000);
			if(counter == 0)
				counter = 9;
			else counter --;
			status = NORMAL;
			break;
		default:
			break;
	}
}
