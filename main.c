/*
 * main.c
 *
 * Created: 1/20/2020 8:11:42 PM
 *  Author: Mohamed Ramadan
 */ 
/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
//#include <asf.h>
#include "gpio.h"
#include "pushButton.h"
#include "led.h"
#include "timers.h"
#include "myinterrupt.h"
#include <util/delay.h>
#include "dcMotor.h"


int main (void)
{
	
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8,0,0,T0_INTERRUPT_NORMAL);
	timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_64,0,0,0,T2_POLLING);
	MotorDC_Init(MOT_1);
	MotorDC_Init(MOT_2);
	
	SREG |= (1<<7);							//enable Global interrupt
			
				/*Testing LED Driver Functions*/
				
//Moving Forward for 5 seconds
		MotorDC_Dir(MOT_1,FORWARD);
		MotorDC_Dir(MOT_2,FORWARD);
		MotorDC_Speed_PollingWithT0(50);
		MotorDC_Dir(MOT_1,STOP);
		MotorDC_Dir(MOT_2,STOP);
		
//moving Backward for 5 seconds
		MotorDC_Dir(MOT_1,BACKWARD);
		MotorDC_Dir(MOT_2,BACKWARD);
		MotorDC_Speed_PollingWithT0(50);
		MotorDC_Dir(MOT_1,STOP);
		MotorDC_Dir(MOT_2,STOP);
		timer0Stop();
//Roate By 90 degree		
		MotorDC_Dir(MOT_1,FORWARD);
		MotorDC_Dir(MOT_2,STOP);
		gpioPinWrite(GPIOD,BIT4,HIGH);
		timer2DelayMs(100);
		MotorDC_Dir(MOT_1,STOP);
		MotorDC_Dir(MOT_2,STOP);
				
		while(1){
	
		}
	
	return 0;	
		}
