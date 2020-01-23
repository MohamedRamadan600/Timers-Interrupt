#include "softwareDelay.h"

/**
 * Description: this delay function operate in a polling manner
 * 				don't use it with RTOSs
 * @param a_delay_in_ms: the milli-seconds
 */
void softwareDelayMs(uint32_t u32_delay_in_ms)
{
	uint32_t i =0;
	for(;i<u32_delay_in_ms;i++)
	{
		;
	}
}
