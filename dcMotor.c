#include "dcMotor.h"
#include "HwPWM.h"

//Initialize the DC motor Pins

void MotorDC_Init(En_motorType_t en_motor_number){

gpioPinDirection(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,OUTPUT);
gpioPinDirection(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,OUTPUT);
gpioPinDirection(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,OUTPUT);

//Initialize Motor 2

gpioPinDirection(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,OUTPUT);
gpioPinDirection(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,OUTPUT);
gpioPinDirection(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,OUTPUT);

}

void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir){
	switch (en_motor_number)
	{
	case MOT_1:
		switch (en_motor_dir)
		{
		case STOP:
			 gpioPinWrite(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, LOW);
			 gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, LOW);
			 gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, LOW);
		break;
		
		case FORWARD:
			 gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, HIGH);
			 gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, LOW);
		break;
		
		case BACKWARD:
			 gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT,LOW);
			 gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, HIGH);
		break;		
		}
		break;
	
	case MOT_2:
		switch (en_motor_dir)
		{
			
			case STOP:
				 gpioPinWrite(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, LOW);
				 gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, LOW);
				 gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, LOW);
			break;
			
			case FORWARD:
				 gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, HIGH);
				 gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, LOW);
			break;
			
			case BACKWARD:
				 gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, LOW);
				 gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, HIGH);
			break;
			
		}
		break;
	}
}


void MotorDC_Speed_PollingWithT0(uint8_t u8_motor_speed){
	
			for (counter_motor_speed=1;counter_motor_speed<u8_motor_speed;counter_motor_speed++)
			{
				timer0SwPWM(counter_motor_speed,250);
				timer2DelayMs(50);
			}
			
			timer2DelayMs(100);
			
			for (counter_motor_speed=u8_motor_speed;counter_motor_speed;counter_motor_speed--)
			{
				timer0SwPWM(counter_motor_speed,250);
				timer2DelayMs(50);
			}
		
	}
	
void MotorDC_Speed_HwPWM(uint8_t u8_motor_speed){
	
	//move the motor of certain speed 
	HwPWMSetDuty(u8_motor_speed,250);
	
}