/*!
 * \file Blinky.c
 *
 * \brief It contains the Entry point use to executed the Blinky software.
 *
 */
#include "BSP/Common/Common.h"

#include "BSP/MCU/CPU/CPU.h"
#include "BSP/MCU/PIT/PIT.h"

#include "BSP/Drivers/LED/LED.h"
#include "Utils/Delay.h"
#ifdef SPY_ON
#include "Application/Spy/Spy.h"
#endif

/*! \brief When the interruption occurs, it is running the entire set of tasks in turn. */
static void OnInterrupt(void)
{
    PIT_ClearInterruptFlag();
    Interrupt_Disable(INT_PIT0-16);
	Led_Blink(eBlue);//eRed
    Interrupt_Enable(INT_PIT0-16);
    PIT_ClearInterruptFlag();
}

/*!  \brief It establishes the overall logic of the code. */
void main (void)
{
	CPU_Setup();

	#ifdef TRACE_ON
    Trace_Setup();
	TRACE("Blinky Software\n");
	#endif
	
    #ifdef SPY_ON
    Spy_Setup();
	#endif
    
    
    Led_Setup();
	PIT_Setup((uint32) OnInterrupt);
	PIT_Start();

	while(1)
    {
		#ifndef SPY_ON
    	Led_Blink(eGreen);
    	Delay(500*_MS);
		#endif
		#ifdef SPY_ON
    	Spy_Run();
		#endif
    }
}
