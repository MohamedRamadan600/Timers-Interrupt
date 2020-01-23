#include "pushButton.h"

/**
 * Description: Initialize the BTN_x Pin state (where x 0, 1, 2, 3) to Input
 * @param btn_id: The btn to be initialized and it takes
 * 				  one of the enum (En_buttonId) parameters
 *
 */
void pushButtonInit(En_buttonId_t en_butotn_id)
{
	switch (en_butotn_id)
	{
		case BTN_0:
					gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,LOW);
					break;
		case BTN_1:
					gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,LOW);
					break;
		case BTN_2:
					gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,LOW);
					break;	
		case BTN_3:
					gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,LOW);
					break;								
	}
	
}


/**
 * Description: read BTN_x (where x 0, 1, 2, 3) state which is stored in the program
 * 				in the update function
 *
 */
En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id){
	uint8_t button_status;
		switch (en_butotn_id)
		{
			case BTN_0:
					button_status = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);        //our kit has only 2 buttons
					break;
			case BTN_1:
					button_status = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
					break;
		}
		if (button_status==HIGH)
		{	
			softwareDelayMs(50);
			if (button_status==HIGH)
			{
				return Pressed;
			}else
			{
				return Released;
			}
		} 
		else if (button_status==HIGH)
		{
			softwareDelayMs(50);					//detect if the push button still pressed or released
			if (button_status==HIGH)
			{
				return Pressed;
			}else
			{
				return Released;
			}	
		}
}
