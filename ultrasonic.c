#include "ultrasonic.h"
#include "std_types.h"
#include "util/delay.h"
#include "led.h"
#include "registers.h"


void Ultrasonic_Init(void){
	
	/*set trigger pin in ultrasonic as output pin*/
	//gpioPinDirection(U_S_Trigger_PORT,U_S_Trigger_PIN,OUTPUT);
	PORTB_DIR|=(1<<3);
	/*set echo pin in ultrasonic as input pin __external interrupt2__*/
	//gpioPinDirection(U_S_Echo_PORT,U_S_Echo_PIN,INPUT);
	PORTB_DIR &=~(1<<2);
}





void Ultrasonic_Start(void){
	
	/*write zero on trigger input pin */
	    //gpioPinWrite(U_S_Trigger_PORT,U_S_Trigger_PIN,LOW);
		PORTB_DATA &=~(1<<3);	
	/* wait for 2 micro second*/
	_delay_us(2);
	/*then write One to trigger pin to send wave at 40 KHZ*/
			//gpioPinWrite(U_S_Trigger_PORT,U_S_Trigger_PIN,HIGH);
		PORTB_DATA |=(1<<3);	
	/*wait again for 10 micro seconds*/
	_delay_us(10);
	/*after sending wave by trigger then write 0 to trigger pin again*/
			//gpioPinWrite(U_S_Trigger_PORT,U_S_Trigger_PIN,LOW);
		PORTB_DATA &=~(1<<3);
}