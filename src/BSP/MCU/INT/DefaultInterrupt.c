/*
 * DefaultInteruption.c
 *
 *  Created on: 8 sept. 2015
 *      Author: GSI
 */

#include "BSP/Common/Common.h"
#include "BSP/MCU/INT/DefaultInterrupt.h"


void __DefaultInterrupt(void)
{
	#define VECTORNUM                     (*(volatile uint8_t*)(0xE000ED04))
    //TRACE("\n****default_isr entered on vector %d*****\r\n\n", VECTORNUM);

	  __asm( "BKPT 255");

    return;
}
