/*
 * led7seg.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Chung Thinh
 */
#include "led7seg.h"

void display7SEG(int num)
{
	HAL_GPIO_WritePin ( GPIOB , g_Pin|f_Pin|e_Pin|d_Pin|c_Pin|b_Pin|a_Pin ,RESET );
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin ( GPIOB , g_Pin ,SET );
		break;
	case 1:
		HAL_GPIO_WritePin ( GPIOB , g_Pin|f_Pin|e_Pin|d_Pin|a_Pin ,SET );
		break;
	case 2:
		HAL_GPIO_WritePin ( GPIOB , f_Pin|c_Pin ,SET );
		break;
	case 3:
		HAL_GPIO_WritePin ( GPIOB , f_Pin|e_Pin ,SET );
		break;
	case 4:
		HAL_GPIO_WritePin ( GPIOB , e_Pin|d_Pin|a_Pin ,SET );
		break;
	case 5:
		HAL_GPIO_WritePin ( GPIOB , e_Pin|b_Pin ,SET );
		break;
	case 6:
		HAL_GPIO_WritePin ( GPIOB , b_Pin ,SET );
		break;
	case 7:
		HAL_GPIO_WritePin ( GPIOB , g_Pin|f_Pin|e_Pin|d_Pin ,SET );
		break;
	case 8:
		break;
	case 9:
		HAL_GPIO_WritePin ( GPIOB , e_Pin ,SET );
		break;
	}
}
