
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "gpio.h"


#define U_S_Trigger_PORT   GPIOB
#define U_S_Trigger_PIN    BIT3			//pin 3 for trigger ultrasonic signal

#define U_S_Echo_PORT   GPIOB			
#define U_S_Echo_PIN    BIT2			//pin 2 for echo ultrasonic signal


/*Initialize the ultrasonic sensor*/
void Ultrasonic_Init(void);


/*start sending the trigger of ultrasonic*/
void Ultrasonic_Start(void);


#endif