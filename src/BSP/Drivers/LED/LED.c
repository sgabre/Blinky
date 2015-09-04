/*
 * LED.c
 *
 *  Created on: 17 févr. 2015
 *      Author: GSI
 */

#include "BSP/Common/Common.h"

#include "BSP/Drivers/LED/LED.h"
#include "BSP/MCU/GPIO/iGPIO.h"
#include "BSP/MCU/Port/iPort.h"
#include "BSP/MCU/SIM/iSIM.h"


#ifdef TWR_K20D72M
#define LED0_Setup()    iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_PORTC, iENABLE);\
                        iGPIO_SetPortOutputDirectionMask(PTC_BASE_PTR, iGPIO_PIN_7); \
                        iPort_SetPinMuxControl(PORTC_BASE_PTR,7, iPORT_MUX_CONTROL_ALT1);\

#define LED0_On()        iGPIO_SetPortDataOutputMask(PTC_BASE_PTR, iGPIO_PIN_7);
#define LED0_Off()       iGPIO_ClearPortDataOutputMask(PTC_BASE_PTR, iGPIO_PIN_7);
#define LED0_Blink()     iGPIO_TogglePortDataOutputMask(PTC_BASE_PTR, iGPIO_PIN_7);

#define LED1_Setup()     iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_PORTC, iENABLE);\
                         iGPIO_SetPortOutputDirectionMask(PTC_BASE_PTR, iGPIO_PIN_8); \
                         iPort_SetPinMuxControl(PORTC_BASE_PTR,8, iPORT_MUX_CONTROL_ALT1);\

#define LED1_On()        iGPIO_SetPortDataOutputMask(PTC_BASE_PTR, iGPIO_PIN_8);
#define LED1_Off()       iGPIO_ClearPortDataOutputMask(PTC_BASE_PTR, iGPIO_PIN_8);
#define LED1_Blink()     iGPIO_TogglePortDataOutputMask(PTC_BASE_PTR, iGPIO_PIN_8);


#elif EJ151_REV1 || EJ151_REV2


#ifdef ES79SW
#define LED0_Setup()    	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;\
    						PORTA_PCR16 = PORT_PCR_MUX(1); \
    						GPIOA_PDDR |= 0x00010000UL ;\
    						PORTA_PCR16 |= PORT_PCR_ODE_MASK;\
    						GPIOA_PCOR |= 0x00010000UL ;\



#define LED0_On()        iGPIO_SetPortDataOutputMask(PTA_BASE_PTR, iGPIO_PIN_16);
#define LED0_Off()       iGPIO_ClearPortDataOutputMask(PTA_BASE_PTR, iGPIO_PIN_16);
#define LED0_Blink()     iGPIO_TogglePortDataOutputMask(PTA_BASE_PTR, iGPIO_PIN_16);

#define LED1_Setup()	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;\
						PORTA_PCR17 = PORT_PCR_MUX(1);\
						GPIOA_PDDR |= 0x00020000UL ;\
						PORTA_PCR17 |= PORT_PCR_ODE_MASK;\
						GPIOA_PCOR |= 0x00020000UL ;\

#define LED1_On()       iGPIO_SetPortDataOutputMask(PTA_BASE_PTR, iGPIO_PIN_17);
#define LED1_Off()      iGPIO_ClearPortDataOutputMask(PTA_BASE_PTR, iGPIO_PIN_17);
#define LED1_Blink()    iGPIO_TogglePortDataOutputMask(PTA_BASE_PTR, iGPIO_PIN_17);
#endif



#ifdef ES80SW
#define LED0_Setup()    iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_PORTB, iENABLE);\
                        iGPIO_SetPortOutputDirectionMask(PTB_BASE_PTR, iGPIO_PIN_0); \
                        iPort_SetPinMuxControl(PORTB_BASE_PTR,0, iPORT_MUX_CONTROL_ALT1);\
                        iPort_SetPinOpenDrain(PORTB_BASE_PTR, iGPIO_PIN_0, iPORT_OPEN_DRAIN_ENABLE);\



#define LED0_On()        iGPIO_SetPortDataOutputMask(PTB_BASE_PTR, iGPIO_PIN_0);
#define LED0_Off()       iGPIO_ClearPortDataOutputMask(PTB_BASE_PTR, iGPIO_PIN_0);
#define LED0_Blink()     iGPIO_TogglePortDataOutputMask(PTB_BASE_PTR, iGPIO_PIN_0);

#define LED1_Setup()     iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_PORTB, iENABLE);\
                        iGPIO_SetPortOutputDirectionMask(PTB_BASE_PTR, iGPIO_PIN_1); \
                        iPort_SetPinMuxControl(PORTB_BASE_PTR,1, iPORT_MUX_CONTROL_ALT1);\
                        iPort_SetPinOpenDrain(PORTB_BASE_PTR, iGPIO_PIN_1, iPORT_OPEN_DRAIN_ENABLE);\

#define LED1_On()       iGPIO_SetPortDataOutputMask(PTB_BASE_PTR, iGPIO_PIN_1);
#define LED1_Off()      iGPIO_ClearPortDataOutputMask(PTB_BASE_PTR, iGPIO_PIN_1);
#define LED1_Blink()    iGPIO_TogglePortDataOutputMask(PTB_BASE_PTR, iGPIO_PIN_1);
#endif

#endif

void Led_Setup(void)
{
    /* Setup the Green Led I/O */
    LED0_Setup();
    LED0_Off();

    /* Setup the Blue Led I/O */
    LED1_Setup();
    LED1_Off();

}
void Led_On(uint8 led)
{
  switch(led)
  {
      case eGreen:
          LED0_On();
      break;

    case eBlue:
        LED1_On();
      break;

    default:
      break;
  }
}

void Led_Off(uint8 led)
{
  switch(led)
  {
    case eGreen:
        LED0_Off();
      break;

    case eBlue:
        LED1_Off();
      break;

    default:
      break;
  }
}

void Led_Blink(uint8 led)
{
  switch(led)
  {
    case eGreen:
        LED0_Blink();
      break;

    case eBlue:
        LED1_Blink();
      break;

    default:
      break;
  }
}
