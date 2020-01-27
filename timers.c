#include "timers.h"
#include "led.h"
#include "pushButton.h"
#include "myinterrupt.h"
#include "dcMotor.h"

#define F_CPU  16000000								//16MHZ
uint16_t TickTime=0;	
uint16_t prescaler_Timer0;						//global variable to store the time of the clock
												//cycle after prescaling in timer0
uint16_t prescaler_Timer1;						//global variable to store the time of the clock 
												//cycle after prescaling in timer1
uint16_t prescaler_Timer2;						//global variable to store the time of the clock
												//cycle after prescaling in timer1
uint16_t tick_time = 0;
uint16_t OverFlowTicksReq=0;

volatile uint8_t OverFlowTicks=0;				//global variable to check the number of over flows to match the time delay
uint8_t PWM1DC=0;            
uint8_t SPWM_Flag=0;


InterruptServiceRoutine(TIMER0_OVRF_vect)
{
SPWM_Flag++;
if(SPWM_Flag==PWM1DC){
gpioPinWrite(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,LOW);
gpioPinWrite(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,LOW);

}
if(SPWM_Flag==100){
	gpioPinWrite(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,HIGH);
	gpioPinWrite(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,HIGH);
SPWM_Flag=0;
}
timer0Set(176);

}

//initialize timer0
void timer0Init(En_timer0Mode_t en_mode,En_timer0OC_t en_OC0,En_timer0perscaler_t en_prescal, 
				uint8_t u8_initialValue,uint8_t u8_outputCompare, En_timer0Interrupt_t en_interruptMask)
				{  
				   uint16_t base_rate = 0;
				   TCCR0|=(1<<7);
			       TCCR0|=en_mode;				//set the timer0 mode
				   TCCR0|=en_OC0;			    //set the output compare pin mode in timer0
				   TCCR0|=en_prescal;			//set the prescaling value of the timer0
				   TCNT0=u8_initialValue;		//set the initial value of the timer0		
				   OCR0 =u8_outputCompare;	    //set the compare value 
				   TIMSK|=en_interruptMask;	
				   prescaler_Timer0 =en_prescal;
					
}


//set the timer0			
void timer0Set(uint8_t u8_value){
			      	TCNT0 = u8_value;		      //set the value to start from it
								}	
								
//read the timer0 value
uint8_t timer0Read(void){
					uint8_t TimerReadValue=0;
					TimerReadValue |= TCNT0;	 //read the value of the timer0 from TCNT0 register
						}	
//start the timer
void timer0Start(void){
				     	TCCR0|=prescaler_Timer0;
						}

//stop the timer
void timer0Stop(void){
						Clr_Bit(TCCR0,BIT0);
						Clr_Bit(TCCR0,BIT1);
						Clr_Bit(TCCR0,BIT2);	 //No clocking so the timer is stopped
						TCNT0=0x00;
					}
					
//Delay using the timer
void timer0DelayMs(uint16_t u16_delay_in_ms){
					uint16_t overflowcounter =0;
					uint32_t No_of_Ticks = 0;
					uint16_t No_of_Overflows = 0;	
							//OverFlowTicksReq = (u16_delay_in_ms*1000)/TickTime;
							//Led_Off(LED_0);
							//timer0Start();
							while(u16_delay_in_ms--){
							timer0Start();
							timer0Set(6);
							while (! (TIFR & (1<<0)));	
							TIFR |= (1<<0);	
							timer0Stop();	
											        }		
											 }

void timer0DelayUs(uint32_t u32_delay_in_us){
							/*OverFlowTicksReq = u32_delay_in_us/TickTime;
							while(OverFlowTicks!=OverFlowTicksReq){}*/
							
							
						/*	while(u32_delay_in_us--){
								timer0Start();

								timer0Set(6);
								while (! (TIFR & (1<<0)));
								TIFR |= (1<<0);
								timer0Stop();
							}*/	

											
											}

void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency){
	
	PWM1DC=u8_dutyCycle;
	timer0Set(176);
}



/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t en_mode,En_timer1OC_t en_OC,En_timer1perscaler_t en_prescal,
			    uint16_t u16_initialValue, uint16_t u16_outputCompareA, uint16_t u16_outputCompareB,
				uint16_t u16_inputCapture, En_timer1Interrupt_t en_interruptMask)
				{
				    TCCR1|=en_mode;
					OCR1A|=en_OC;
					TCCR1|=en_prescal;
					TCNT1|=u16_initialValue;
					OCR1A|=u16_outputCompareA;
					OCR1B|=u16_outputCompareB;
					ICR1|=u16_inputCapture;
					TIMSK|=en_interruptMask;
					prescaler_Timer1=en_prescal;
	
				}


void timer1Set(uint16_t u16_value){
	
									TCNT1 = u16_value;
								  }
uint16_t timer1Read(void){
							uint16_t TimerReadValue=0;
							TimerReadValue |= TCNT1;
						 }
void timer1Start(void){
						 TCCR1|=prescaler_Timer1;
						}	

void timer1Stop(void){
						Clr_Bit(TCCR1B,BIT0);
						Clr_Bit(TCCR1B,BIT1);
						Clr_Bit(TCCR1B,BIT2);			//No clocking so the timer is stopped
						TCNT1=0;
						}	

void timer1DelayMs(uint16_t u16_delay_in_ms){
	//uint16_t counter_timer1=0;
									while (u16_delay_in_ms--)
										{
											timer1Start();
											timer1Set(1);
											while (!(TIFR & (1<<4)));
											Set_Bit(TIFR,4);
											timer1Stop();
										}

											}	
/*void timer1SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency){
	
	uint16_t No_Of_Ticks=0; 
	
	No_Of_Ticks = F_CPU/(100*prescaler_Timer1*u8_frequency);
	
	timer1Init(T1_COMP_MODE_OCR1A_TOP,T1_OC1_DIS,T1_PRESCALER_64,
				0,No_Of_Ticks,0,0,T1_INTERRUPT_CMP_1A);
	
	if(OverFlowTicks>=u8_dutyCycle){
		gpioPinWrite(T1_SPWM_GPIO,T1_SPWM_BIT,LOW);
		OverFlowTicks=0;
	}else if(OverFlowTicks<u8_dutyCycle){
		gpioPinWrite(T1_SPWM_GPIO,T1_SPWM_BIT,HIGH);
	}
	
}*/


//void timer1DelayUs(uint32_t u32_delay_in_us);



		


//Initialize the timer2

void timer2Init(En_timer2Mode_t en_mode,En_timer2OC_t en_OC,En_timer2perscaler_t en_prescal, 
				uint8_t u8_initialValue, uint8_t u8_outputCompare, uint8_t u8_assynchronous, 
				En_timer2Interrupt_t en_interruptMask)
				{
					TCCR2|=en_mode;					 //set the timer2 mode
					TCCR2|=en_OC;				     //set the output compare pin mode in timer2
					TCCR2|=en_prescal;			     //set the prescaling value of the timer2
					TCNT2|=u8_initialValue;			 //set the initial value of the timer2
					OCR2 |=u8_outputCompare;	     //set the compare value
					ASSR |=u8_assynchronous;        
					TIMSK|=en_interruptMask;
					prescaler_Timer2=en_prescal;
				}


void timer2Set(uint8_t u8_a_value){
									TCNT2 = u8_a_value;
								   }


uint8_t timer2Read(void){
					uint8_t Timer2ReadValue=0;
					Timer2ReadValue |= TCNT2;   //read the value of the timer2 from TCNT2 register
						}

void timer2Start(void){
						TCCR2|=prescaler_Timer2;
					  }

void timer2Stop(void){
						Clr_Bit(TCCR2,BIT0);
						Clr_Bit(TCCR2,BIT1);
						Clr_Bit(TCCR2,BIT2);			//No clocking so the timer is stopped
						TCNT2=0x00;	
					 }

void timer2DelayMs(uint16_t u16_delay_in_ms){
					
											while(u16_delay_in_ms--){
												timer2Start();
												timer2Set(6);
												while (! (TIFR & (1<<6)));
												TIFR |= (1<<6);
												timer2Stop();
																	}	
											  }

