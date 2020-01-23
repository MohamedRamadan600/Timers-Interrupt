/*
*interrupt.h
***/

#ifndef MYINTERRUPT_H_
#define MYINTERRUPT_H_

#define EXTERNAL_INTERRUPT0_vect			__vector_1
#define EXTERNAL_INTERRUPT1_vect			__vector_2  
#define EXTERNAL_INTERRUPT2_vect			__vector_3
#define TIMER2_COMPARE_vect   				__vector_4 
#define TIMER2_OVF_vect   					__vector_5
#define TIMER1_CAPTURE_vect    				__vector_6
#define TIMER1_COMPARE_A_vect   			__vector_7
#define TIMER1_COMPARE_B_vect   			__vector_8
#define TIMER1_OVF_vect     				__vector_9
#define TIMER0_COMPARE_vect    				__vector_10
#define TIMER0_OVF_vect     				__vector_11
#define SERIAL_TRANSFER_COMPLETE_vect		__vector_12
#define USART_RX_COMPLETE_vect				__vector_13
#define USART_DATA_REGISTER_EMPTY_vect		__vector_14
#define USART_TX_COMPLETE_vect				__vector_15
#define ADC_CONVERSION_vect		            __vector_16
#define	EEPROM_READY_vect					__vector_17
#define	ANALOG_COMPARATOR_vect				__vector_18
#define	TWI_vect							__vector_19
#define	SPM_RDY_INTERRUPT_vect				__vector_20

void EXTERNAL_INTERRUPT0_vect(void) __attribute__((signal,interrupt));						//address $002
void EXTERNAL_INTERRUPT1_vect(void) __attribute__((signal,interrupt));						//address $004
void EXTERNAL_INTERRUPT2_vect(void) __attribute__((signal,interrupt));						//address $006
void TIMER2_COMPARE_vect(void) __attribute__((signal,interrupt));							//address $008
void TIMER2_OVF_vect(void) __attribute__((signal,interrupt));								//address $00A
void TIMER1_CAPTURE_vect(void) __attribute__((signal,interrupt));							//address $00C
void TIMER1_COMPARE_A_vect(void) __attribute__((signal,interrupt));							//address $00E
void TIMER1_COMPARE_B_vect(void) __attribute__((signal,interrupt));							//address $010
void TIMER1_OVF_vect(void) __attribute__((signal,interrupt));								//address $012
void TIMER0_COMPARE_vect(void) __attribute__((signal,interrupt));							//address $014
void TIMER0_OVF_vect(void) __attribute__((signal,interrupt));								//address $016
void SERIAL_TRANSFER_COMPLETE_vect(void) __attribute__((signal,interrupt));					//address $018
void USART_RX_COMPLETE_vect(void) __attribute__((signal,interrupt));						//address $01A
void USART_DATA_REGISTER_EMPTY_vect(void) __attribute__((signal,interrupt));				//address $01C
void USART_TX_COMPLETE_vect(void) __attribute__((signal,interrupt));						//address $01E
void ADC_CONVERSION_vect(void) __attribute__((signal,interrupt));							//address $020
void EEPROM_READY_vect(void) __attribute__((signal,interrupt));								//address $022
void ANALOG_COMPARATOR_vect(void) __attribute__((signal,interrupt));						//address $024
void TWI_vect(void) __attribute__((signal,interrupt));										//address $026
void SPM_RDY_INTERRUPT_vect(void) __attribute__((signal,interrupt));						//address $028









#endif   /*interrupt.h*/