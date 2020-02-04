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
#define F_CPU 16000000UL
#include "ultrasonic.h"
#include "gpio.h"
#include "pushButton.h"
#include "led.h"
#include "SwICU.h"
#include "timers.h"
#include "myinterrupt.h"
#include <util/delay.h>
#include "dcMotor.h"
#include "HwPWM.h"
#include "registers.h"


//#define PulseTime  (4*256)

volatile uint8_t  gu_IC_SW;		//global unsigned input capture pointer 
extern volatile uint8_t Edge_Status_Control;

//#include "avr/interrupt.h"



/*
 InterruptServiceRoutine(TIMER0_OVRF_vect)
{

Led_Toggle(LED_1);
/*if()
gpioPinWrite(T0_SPWM_GPIO,T0_SPWM_BIT,HIGH);*/

	/*OverFlowTicks++;
	Led_On(LED_0);
	softwareDelayMs(1000);
	
	if(OverFlowTicks % 100 == 25){
		gpioPinWrite(T0_SPWM_GPIO,T0_SPWM_BIT,LOW);
		
	}elseif(OverFlowTicks % 100 == 0){
		gpioPinWrite(T0_SPWM_GPIO,T0_SPWM_BIT,HIGH);
		OverFlowTicks=0;
	}*/

//softwareDelayMs(1000);
//}



volatile uint16_t distance = 0;

int main (void)
{
	//initialize led 1	
	Led_Init(LED_0);
	//initialize led 2
	Led_Init(LED_1);
	//initialize led 3
	Led_Init(LED_2);
	//initialize led 4
	Led_Init(LED_3);
	//initialize Hardware PWM
	HwPWMInit();		
	
	//initialize icu
	SwICU_Init(SwICU_EdgeRisiging);
	//Enable ICU
	SwICU_Enable();
	//Initialize ultrasonic
	Ultrasonic_Init();
	//setting Global Interrupt
	SREG|=(1<<7);	
	//initialize timer2
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_256,0,0,T0_POLLING);	
	//MCUCSR|= (1<<6);	
	SwICU_SetCfgEdge(SwICU_EdgeRisiging);
	HwPWMSetDuty(75,250);	
while(1){
	
	//start sending trigger signal 
	Ultrasonic_Start();
	//distance = (uint16_t)(0.272*TCNT0);
	 distance = (uint16_t) ((68*((gu_IC_SW)))/1000);
	 //output the distance on the leds
	 PORTB_DATA |=(distance<<4);
	
}
return 0;
	}

/*
//main testing PWM hardware generation
int main(void){
	Led_Init(LED_0);
	
	HwPWMInit();
	HwPWMSetDuty(75,250);
	
	
	
	while (1)
	{
		
	}
	
	return 0;
}
	*/
InterruptServiceRoutine(EXTERNAL_INTERRUPT2_vect){
	/*check if the trigger is rising edge*/
	//Led_On(LED_0);
	if (Edge_Status_Control == SwICU_EdgeRisiging)
	{
	
		
		//start timer2 counting and prescaling
		timer0Start();
		//writing falling edge on external interrupt
		SwICU_SetCfgEdge(SwICU_EdgeFalling);
		GIFR &=~(1<<5);	
	}
	else if (Edge_Status_Control == SwICU_EdgeFalling)
	{
		//read the counter value in SwICU_Read function
		SwICU_Read(&gu_IC_SW);
		//change the scene control to Rising edge on external interrupt
		SwICU_SetCfgEdge(SwICU_EdgeRisiging);
		//stop timer2
		timer0Stop();
		//reinitialize the counter 0
		TCNT0 = 0;	
	}
}
