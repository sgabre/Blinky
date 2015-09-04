#include "BSP/Common/Common.h"

#include "BSP/MCU/CPU/CPU.h"

#include "BSP/Drivers/LED/LED.h"
#include "Utils/Delay.h"

void main (void)
{
    CPU_Setup();

    Trace_Setup();

    TRACE("Blinky Software\n");

    Led_Setup();

    while(1)
    {
    	Led_Blink(eGreen);
    	Delay(500*_MS);
    }
}
