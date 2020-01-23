
#include "std_types.h"
#include "softwareDelay.h"
#include "pushButton.h"
#include "led.h"

   uint8_t PressCounter;
   uint16_t DelayCounter;
   uint8_t counterapp = 0;
   
				  

ButtonLedApp(){
  En_buttonStatus_t ButtonStatus = pushButtonGetStatus(BTN_0);
	  if (ButtonStatus == Pressed   )
	     {
		    counterapp++;
		 }
		    while (counterapp)
			{
			counterapp--;
			
			for (uint8_t DelayCounter=0;DelayCounter<20;DelayCounter++)
			{
				softwareDelayMs(50);
				Led_On(LED_0);
				ButtonStatus = pushButtonGetStatus(BTN_0);
				if  ((counterapp == 0) && (ButtonStatus == Pressed ))
				{
					counterapp++;
				}

			}
		}
		
		Led_Off(LED_0);
	}