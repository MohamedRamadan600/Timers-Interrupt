#include "gpio.h"
#include "sevenSeg.h"
#include "softwareDelay.h"
#include "std_types.h"

SevenSegmentApp(){
   sevenSegInit(SEG_0);
   sevenSegInit(SEG_1);
      for(uint8_t count1=0;count1<100;count1++)
	     {
		    for(uint8_t DelayCounter = 0; DelayCounter < 40; DelayCounter++)
			   {
			      sevenSegEnable(SEG_0);
				  sevenSegWrite(SEG_0,count1%10);
				  sevenSegEnable(SEG_1);
				  sevenSegWrite(SEG_1,count1/10);
				  softwareDelayMs(50);
				}
		}
				}

