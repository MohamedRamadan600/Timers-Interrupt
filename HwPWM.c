#include "HwPWM.h"
#include "timers.h"
#include "led.h"


void HwPWMInit(void){
	//OC0 pin for PWm on timer0
	gpioPinDirection(T0_PWM_GPIO,T0_PWM_BIT,OUTPUT);
	//OC1A pin for PWm on timer1
	gpioPinDirection(T1A_PWM_GPIO,T1A_PWM_BIT,OUTPUT);
	//OC1B pin for PWm on timer1
	gpioPinDirection(T1B_PWM_GPIO,T1B_PWM_BIT,OUTPUT);
	//OC2 pin for PWm on timer2
	gpioPinDirection(T2_PWM_GPIO,T2_PWM_BIT,OUTPUT);
	//initialize timer1
	timer1Init(T1_FAST_PWM_MODE_ICR1_TOP,T1_OC1A_CLEAR | T1_OC1B_CLEAR,T1_PRESCALER_1024,
				0,0,0,0,T1_POLLING);
	
	
}



void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency){
	uint8_t value = 0;
	 //calculate the value of the period of PWM signal
	value=(uint8_t)(F_CPU/((2*1024*a_u32_frequency)))-1;
	ICR1 = value;
	//set duty cycle of the first generated signal
	OCR1A=(uint8_t)value*((float)a_u8_duty/100.0); 
	//set duty cycle of the second generated signal
	OCR1B=(uint8_t)value*((float)a_u8_duty/100.0);
	
	
}

