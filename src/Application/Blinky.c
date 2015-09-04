#include "BSP/Common/Common.h"

#include "BSP/MCU/CPU/CPU.h"
#include "BSP/MCU/PIT/PIT.h"

#include "BSP/Drivers/LED/LED.h"
#include "Utils/Delay.h"
#ifdef SPY_ON
#include "Application/Spy/Spy.h"
#endif

static void Periodic(void)
{
    PIT_ClearInterruptFlag();
    Interrupt_Disable(INT_PIT0-16);
	Led_Blink(eBlue);//eRed
    Interrupt_Enable(INT_PIT0-16);
    PIT_ClearInterruptFlag();
}
void main (void)
{
    CPU_Setup();

    Trace_Setup();
	TRACE("Blinky Software\n");
	
    #ifdef SPY_ON
    Spy_Setup();
	#endif
    
    
    Led_Setup();
	PIT_Setup((uint32) Periodic);
	 PIT_Start();
	 
    while(1)
    {
		#ifndef SPY_ON
    	Led_Blink(eGreen);
		#endif
    	TRACE(".");
		#ifdef SPY_ON
    	Spy_Run();
		#endif
    }
}
