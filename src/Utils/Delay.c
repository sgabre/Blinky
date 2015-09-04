/*
 * Delay.c
 *
 *  Created on: 4 sept. 2015
 *      Author: GSI
 */
#include "BSP/Common/Common.h"

#include "Utils/Delay.h"

void Delay(uint32 value)
{
	while(value--)
	{
		asm("NOP");
	}
}
