#include "registers.h"
#include "gpio.h"
/*===========================PORT Control===============================*/
/**
 * Description: set port direction (which is DDR register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param direction: set the port direction and takes the following values
 * 				- 0x00 -> Input
 * 				- 0xff -> Output
 */

void gpioPortDirection(uint8_t u8_port, uint8_t u8_direction){
				
				switch (u8_port)
				{
					case GPIOA:
										PORTA_DIR= u8_direction;  
										break;
					case GPIOB:
										PORTB_DIR= u8_direction;
										break;
					case GPIOC:
										PORTC_DIR= u8_direction;
										break;
					case GPIOD:
										PORTD_DIR= u8_direction;
										break;
				}

}
/**
 * Description: set the port value (which is PORT register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value: set the port value and takes the following values
 * 				- 0x00 -> Low
 * 				- 0xff -> High
 */
void gpioPortWrite(uint8_t u8_port, uint8_t u8_value){
			
				switch (u8_port)
				{
					case GPIOA:
										PORTA_DATA= u8_value;
										break;
					case GPIOB:
										PORTB_DATA= u8_value;
										break;
					case GPIOC:
										PORTB_DATA= u8_value;
										break;
					case GPIOD:
										PORTB_DATA= u8_value;
										break;
				}
}

/**
 * Description: toggle the port value (which is PORT register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 */

void gpioPortToggle(uint8_t u8_port){
				
				switch (u8_port)
				{
					case GPIOA:
									PORTA_DATA ^= OUTPUT;
									break;
					case GPIOB:
									PORTB_DATA ^= OUTPUT;
									break;
					case GPIOC:
									PORTC_DATA ^= OUTPUT;
									break;
					case GPIOD:
									PORTD_DATA ^= OUTPUT;
									break;				
				}
}


/**
 * Description: read the current port value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */

uint8_t gpioPortRead(uint8_t u8_port){
	uint8_t byte_reg1;
				switch (u8_port)
				{
					case GPIOA:
								PORTA_PIN &= OUTPUT;
								break;
					case GPIOB:
								PORTB_PIN &= OUTPUT;
								break;
					case GPIOC:
								PORTC_PIN &= OUTPUT;
								break;
					case GPIOD:
								PORTD_PIN &= OUTPUT;
								break;
				}
	
return byte_reg1;	
}

/*===========================PIN Control===============================*/
/**
 * Description: set selected pins (more than one pin [ORed]) direction
 *
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pins the user need to set its direction and takes
 * 				any member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 *
 * @param direction: set the pins direction and takes the following values
 * 				- 0x00 -> Input
 * 				- 0xff -> Output
 */
void gpioPinDirection(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_direction){
	
		switch (u8_port)
		{
			case GPIOA:
								if(u8_direction==OUTPUT){
								PORTA_DIR |= u8_pins;
								}else if (u8_direction==INPUT)
								{
								PORTA_DIR &=~u8_pins;	
								}
								break;
			case GPIOB:
								if(u8_direction==OUTPUT){
									PORTB_DIR |= u8_pins;
								}else if (u8_direction==INPUT)
								{
									PORTB_DIR &=~u8_pins;
								}
								break;
			case GPIOC:
								if(u8_direction==OUTPUT){
									PORTC_DIR |= u8_pins;
								}else if (u8_direction==INPUT)
								{
									PORTC_DIR &=~u8_pins;
								}
								break;
			
			case GPIOD:
								if(u8_direction==OUTPUT){
									PORTD_DIR |= u8_pins;
								}else if (u8_direction==INPUT)
								{
									PORTD_DIR &=~u8_pins;
								}
								break;
		}
	
}

/**
 * Description: set selected pins (more than one pin [ORed]) values
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pins the user need to write its values and takes
 * 				any member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 * @param value
 */
void gpioPinWrite(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_value){
	
				switch (u8_port)
				{
					case GPIOA:
								if(u8_value==HIGH){
									PORTA_DATA |= u8_pins;
								}else if (u8_value==LOW)
								{
									PORTA_DATA &=~u8_pins;
								}
								break;
					case GPIOB:
								if(u8_value==HIGH){
									PORTB_DATA |= u8_pins;
								}else if (u8_value==LOW)
								{
									PORTB_DATA &=~u8_pins;
								}
								break;
					case GPIOC:
								if(u8_value==HIGH){
									PORTC_DATA |= u8_pins;
								}else if (u8_value==LOW)
								{
									PORTC_DATA &=~u8_pins;
								}
								break;
					
					case GPIOD:
								if(u8_value==HIGH){
									PORTD_DATA |= u8_pins;
								}else if (u8_value==LOW)
								{
									PORTD_DATA &=~u8_pins;
								}
								break;
				}
					
}

/**
 * Description: toggle selected pin (only one pin) direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pin the user need to toggle it's value and takes
 * 				only one member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 */
void gpioPinToggle(uint8_t u8_port, uint8_t u8_pins)
{
	switch (u8_port)
	{
						case GPIOA:
								PORTA_DATA ^= u8_pins;
								break;
						case GPIOB:
								PORTB_DATA ^= u8_pins;
								break;
						case GPIOC:
								PORTC_DATA ^= u8_pins;
								break;
						case GPIOD:
								PORTD_DATA ^= u8_pins;
								break;
	}
	
}

/**
 * Description: read selected pin (only one pin) direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param pin: the selected pin the user need to read it's value and takes
 * 				only one member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 * @return
 */

uint8_t gpioPinRead(uint8_t u8_port, uint8_t u8_pin)
{
			uint8_t byte_reg;		
					switch (u8_port)
					{
						case GPIOA:
								byte_reg = (PORTA_PIN & u8_pin)? 1:0;
								break;
						case GPIOB:
								byte_reg = (PORTB_PIN & u8_pin)? 1:0;
								break;
						case GPIOC:
								byte_reg = (PORTC_PIN & u8_pin)? 1:0;
								break;
						case GPIOD:
								byte_reg = (PORTD_PIN & u8_pin)? 1:0 ;
								break;
					}
	return byte_reg;
}



