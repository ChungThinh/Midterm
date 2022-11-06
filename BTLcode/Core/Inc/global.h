/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Chung Thinh
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "main.h"
#include "led7seg.h"
#include "button.h"

#define INIT		1
#define NORMAL		2
#define RESETSTATE	3
#define INCSTATE	4
#define DECSTATE		5
#define NOPRESS		6

extern int status;
extern int counter;

#endif /* INC_GLOBAL_H_ */
