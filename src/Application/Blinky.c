#include "BSP/Common/Common.h"

#include "BSP/MCU/CPU/CPU.h"

#include "BSP/Drivers/LED/LED.h"

void main (void)
{
    CPU_Setup();

    Led_Setup();

    while(1)
    {
    	Led_Blink(eGreen);
    }
}
