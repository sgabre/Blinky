/*
 * PIT.c
 *
 *  Created on: 30 avr. 2014
 *      Author: gsi
 */


#include "BSP/Common/Common.h"

#include  "BSP/MCU/PIT/iPIT.h"
#include  "BSP/MCU/PIT/PIT.h"

#include "BSP/MCU/INT/INT.h"

static void PIT_OnInterruption(void);

void PIT_Setup(uint32 FunctionAddress)
{
   /* PIT Clock  has a frequency of ??? MHz */
   /* Timer #1 creates an interrupt every 5.12 ms */

    SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;

    /* Turn-On PIT */
    PIT_MCR = 0x00;

    /* Timer #1 Setting */

    /* Setup timer #0 for 1 ms at 72 MHz cycles */
    PIT_LDVAL0 = 7200000;// 100 ms
    //PIT_LDVAL0 = 3600000;// 50 ms
    //PIT_LDVAL0 = 1800000// 25 ms

    /* Enable Timer #1 Interrupts */
    PIT_TCTRL0 |= PIT_TCTRL_TIE_MASK;

    /* Start Timer #1 */
    PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK;
    // plug isr into vector table in case not there already    
    if(FunctionAddress != 0)
    {
        Vector_PlugIn(INT_PIT0, FunctionAddress);
    }
    else
    {
        Vector_PlugIn(INT_PIT0, (uint32)PIT_OnInterruption);
    }

    // Enable the ADC and PDB interrupts in NVIC
    //Interrupt_Enable(INT_PIT0-16);   // ready for this interrupt.
}

void PIT_ClearInterruptFlag(void)
{
    PIT_TFLG0  = PIT_TFLG_TIF_MASK;
}

static void PIT_OnInterruption(void)
{
    PIT_ClearInterruptFlag();

}

void PIT_Start(void)
{
    iPIT_EnableDevice(PIT_BASE_PTR, iPIT_CHANNEL_0, iENABLE);
    Interrupt_Enable(INT_PIT0-16);
}

void PIT_Stop(void)
{
    iPIT_EnableDevice(PIT_BASE_PTR, iPIT_CHANNEL_0, iDISABLE);
    Interrupt_Disable(INT_PIT0-16);
}


void PIT_SetPeriod(uint32 period)
{

    iPIT_EnableDevice(PIT_BASE_PTR, iPIT_CHANNEL_0, iDISABLE);
    iPIT_WriteLoadReg(PIT_BASE_PTR, iPIT_CHANNEL_0, period);
    iPIT_EnableDevice(PIT_BASE_PTR, iPIT_CHANNEL_0, iENABLE);
}
