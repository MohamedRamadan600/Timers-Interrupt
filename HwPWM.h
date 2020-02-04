/*
 * HwPWM.h
 *
 *  Created on: Oct 28, 2019
 *      Author: Think
 */

#ifndef HWPWM_H_
#define HWPWM_H_

#include "registers.h"
#include "gpio.h"
#define F_CPU 16000000UL

#define T0_PWM_GPIO		GPIOB
#define T0_PWM_BIT		BIT3

#define T1A_PWM_GPIO	GPIOD
#define T1A_PWM_BIT		BIT4

#define T1B_PWM_GPIO	GPIOD
#define T1B_PWM_BIT		BIT5

#define T2_PWM_GPIO		GPIOD
#define T2_PWM_BIT		BIT7

void HwPWMInit(void);
void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency);
#endif /* HWPWM_H_ */
