#include "registers.h"
#include "gpio.h"
#include "extint.h"


void EINT2_Enable(void){
	//GICR|=(1<<BIT5);		//set the INT2 in GICR Register to enable external interrupt module
	GICR|=(1<<5);

}


void EINT2_Disable(void){
	GICR &=~(1<<BIT5);		//clear the INT2 in GICR Register to disable external interrupt module
}


void EINT2_R_s_Edge(void){
	//MCUCSR|= (1<<BIT6);		//set the ISC2 in MCUCSR Register to set ext as rising edge	
	MCUCSR|= (1<<6);
}

void EINT2_Falling_Edge(void){
	MCUCSR &= ~(1<<6);		//clear the ISC2 in MCUCSR Register to set ext as falling edge	

}

