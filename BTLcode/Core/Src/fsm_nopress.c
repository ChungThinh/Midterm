/*
 * fsm_nopress.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Chung Thinh
 */

#include "fsm_nopress.h"

void fsm_nopress_run()
{
	switch(status)
	{
		case NOPRESS:
			if(timer4_flag == 1)
			{
				if(counter != 0)
					display7SEG(counter--);
				else{
					display7SEG(counter);
				}
				setTimer4(250);
			}
			if(timer2_flag == 1)
			{
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
				setTimer2(1000);
			}
			if(isButtonPressed(1)== 1)
			{
				status = INCSTATE;
				if(counter != 0)
				{
					if(counter != 9)
						counter++;
				}
			}
			if(isButtonPressed(2)== 1)
			{
				status = NORMAL;
			}
			break;
		default:
			break;
	}
}
