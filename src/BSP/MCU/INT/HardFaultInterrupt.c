/*
 * HardFaultInterrupt.c
 *
 *  Created on: 8 sept. 2015
 *      Author: GSI
 */

#include "BSP/Common/Common.h"
#include "BSP/MCU/INT/HardFaultInterrupt.h"


void hard_fault_handler_c(unsigned int * hardfault_args);

/* Exception frame without floating-point storage
 * hard fault handler in C,
 * with stack frame location as input parameter
 */
void __HardFaultInterrupt(void)
{
  /*
    //Exception stack frame
    TRACE("[\nHard fault handler]\n");
    TRACE("BusFault Status Register[BFAR] = %x\n", (*((volatile unsigned long *) (0xE000ED38))));
    TRACE("Configurable Fault Status Register [CFSR] = %x\n", (*((volatile unsigned long *) (0xE000ED28))));
    TRACE("HardFault Status Register [HFSR] = %x\n", (*((volatile unsigned long *) (0xE000ED2C))));
    TRACE("DFSR = %x\n", (*((volatile unsigned long *) (0xE000ED30))));
    TRACE("Auxiliary Fault Status Register [AFSR] = %x\n", (*((volatile unsigned long *) (0xE000ED3C))));
    TRACE("MemManage Fault Address Register [MMAR] = %x\n", (*((volatile unsigned long *) (0xE000ED34))));// GoSi Not able to check if the MMAR register addres is correct
    */
    for(;;);/*infinite loop*/
}
