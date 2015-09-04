/*
 * CPU.c
 *
 *  Created on: 8 janv. 2015
 *      Author: gsi
 */
#include "BSP/Common/Common.h"

#include "BSP/MCU/CPU/CPU.h"
#include "BSP/MCU/MCG/MCG.h"

void CPU_Setup(void)
{
	MCG_Setup();
}
