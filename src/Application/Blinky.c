#include "BSP/Common/Common.h"

#include "BSP/MCU/CPU/CPU.h"
#include "BSP/MCU/PIT/PIT.h"

#include "BSP/Drivers/LED/LED.h"
#include "Utils/Delay.h"

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
    Led_Setup();
	PIT_Setup((uint32) Periodic);
	 PIT_Start();
	 
    while(1)
    {
    	Led_Blink(eGreen);
    	Delay(500*_MS);
    }
}
