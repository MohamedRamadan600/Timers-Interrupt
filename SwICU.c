#include "extint.h"
#include "SwICU.h"
#include "util/delay.h"
#include "led.h"



extern volatile uint8_t *gu_IC_SW;
volatile uint8_t Edge_Status_Control=0;



//InterruptServiceRoutine(EXTERNAL_INTERRUPT2_vect){
	




void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge){
		
		switch (a_en_inputCaptureEdge)
		{
			/* case falling edge*/
		case SwICU_EdgeFalling:
			/*Trigger external interrupt at falling edge*/
			EINT2_Falling_Edge();
			break;
			/* case falling edge*/
		case SwICU_EdgeRisiging:
			/*Trigger external interrupt at rising edge*/
			EINT2_R_s_Edge();
			break;	
		}

}



EN_SwICU_Edge_t SwICU_GetCfgEdge(void){
	
	if (MCUCSR & (1<<BIT6))
	{	/*ISC2 = 1 , that mean external interrupt is on rising edge*/
		return SwICU_EdgeRisiging;
	} 
	else
	{	/*ISC2 = 0 , that mean external interrupt is on falling edge*/
		return SwICU_EdgeFalling;
	}

}

void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdgeedge){
	
	//Disable External Interrupt as per data sheet
		EINT2_Disable(); 
	 //store the external int2 scence control
	 Edge_Status_Control = a_en_inputCaptureEdgeedge;
	 //set the triggering status rising or falling
		 switch (a_en_inputCaptureEdgeedge)
		 {
		 case SwICU_EdgeFalling:
			/*clear the ICS2 pin in MCUCSR for falling edge*/
			EINT2_Falling_Edge();
	 		break;
		 case SwICU_EdgeRisiging:
			/*set the ICS2 pin in MCUCSR for rising edge*/
			EINT2_R_s_Edge();
			break;	 
		 }
		 
		//Enable External Interrupt
		EINT2_Enable();		 

}

void SwICU_Read(uint8_t * a_pu8_capt){
	//storing counter value in a_pu8_capt variable 
	*a_pu8_capt = timer0Read();
}


void SwICU_Stop(void){

	//disable int2
	EINT2_Disable();
}

void SwICU_Start(void){
	//enable int2
	EINT2_Enable();
}

void SwICU_Enable(void){
	//enable external interrupt 
	EINT2_Enable();	

}

void SwICU_Disable(void){
	//Disable external interrupt
	EINT2_Disable();

}