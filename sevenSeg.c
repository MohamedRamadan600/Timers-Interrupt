#include "sevenSeg.h"

void sevenSegInit(En_SevenSegId_t a_segment_id)
{
	
	switch (a_segment_id)
	{
	case SEG_0:
		gpioPinDirection(SEG_BCD_GPIO,BIT0|BIT1|BIT2|BIT3,OUTPUT);
		gpioPinDirection(SEG_EN1_GPIO,SEG_EN1_BIT,OUTPUT);
		break;
		
	case SEG_1:
		gpioPinDirection(SEG_BCD_GPIO,BIT0|BIT1|BIT2|BIT3,OUTPUT);
		gpioPinDirection(SEG_EN2_GPIO,SEG_EN2_BIT,OUTPUT);
		break;	
	}
	
}


void sevenSegEnable(En_SevenSegId_t en_segment_id){
	//gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT|SEG_EN2_BIT,HIGH);     //in case no need to play the two segment together and need one of them to be enabled
	switch (en_segment_id)
	{
		case SEG_0:
				gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,HIGH);
				break;
		case SEG_1:
				gpioPinWrite(SEG_EN1_GPIO,SEG_EN2_BIT,HIGH);
				break;		
	}
}

void sevenSegDisable(En_SevenSegId_t en_segment_id){
		switch (en_segment_id)
		{
			case SEG_0:
					gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,LOW);
					break;
			case SEG_1:
					gpioPinWrite(SEG_EN1_GPIO,SEG_EN2_BIT,LOW);
					break;
		}
}

void sevenSegWrite(En_SevenSegId_t en_segment_id, uint8_t u8_number)
{
		switch (u8_number)
		{
			case 0:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);     //set the pins to high due to it's common cathode
					break;
			case 1:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;
			case 2:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;
			case 3:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;
			case 4:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;
			case 5:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;
			case 6:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;
			case 7:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;
			case 8:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;
			case 9:
					gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,HIGH);
					break;							
		}
	
}