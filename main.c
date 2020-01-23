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

/*
#include "avr/interrupt.h"
*/
extern uint16_t OverFlowTicks;


int main (void)
{
		

	/* Insert system clock initialization code here (sysclk_init()). */
				/*Testing GPIO Functions*/
	gpioPinDirection(LED_0_GPIO,LED_0_BIT|LED_1_BIT|LED_2_BIT|LED_3_BIT,OUTPUT);
	gpioPinDirection(BTN_0_GPIO,BTN_0_BIT|BTN_1_BIT,INPUT);
	gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
	Led_Init(LED_0);
	//SREG |= (1<<7);
	Set_Bit(SREG,7);						//set Global interrupt
	timer0Init(T0_NORMAL_MODE, T0_OC0_DIS,T0_PRESCALER_64,0,0,T0_POLLING);
	timer1Init(T1_COMP_MODE_OCR1A_TOP,T1_OC1_DIS,T1_PRESCALER_64,0, 250, 0,0,T1_POLLING);
    timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_64,0,0,0,T2_POLLING);

	
				
				/*Testing LED Driver Functions*/
while(1){	
	Led_On(LED_0);
	timer2DelayMs(1000);
	Led_Off(LED_0);
	timer2DelayMs(1000);
}
	
return 0;	
}
