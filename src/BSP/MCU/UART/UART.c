/**
 * @file UART.c
 * @version 1.0
 * @date 2011-11-15
 * @brief Provide common UART routines for serial IO 
 *
 * This file implements the Microcontroller UART Driver
 *
 * @addtogroup Microcontroller_Driver_defines Microcontroller Driver
 * @{
 * @addtogroup UART_Peripheral Universal Asynchronous Receiver/Transmitter (UART)
 * @{
 */

#include "BSP/Common/Common.h"

#include "BSP/MCU/UART/UART.h"
#include "BSP/MCU/MCG/MCG.h"
#include "BSP/MCU/SIM/iSIM.h"
#include "BSP/MCU/Port/iPort.h"
#include "BSP/MCU/GPIO/iGPIO.h"

/*
 * [---------TOWER---------]
 * [       Debug Port      ]
 * [Signal  |Name |Pin|ALT ]
 * [UART1_TX|PTE0 |  1|ALT3]
 * [UART1_RX|PTE1 |  2|ALT3]
 * [        COM Port       ]
 * [Signal  |Name |Pin|ALT ]
 * [UART0_RX|PTD6 | 99|ALT3]
 * [UART0_TX|PTD7 |100|ALT3]
 *
 * [---------EJ-151--------]
 *
 * [---------REV-1---------]
 *
 * [---------REV-2---------]
 */

#ifdef TWR_K20D72M
#define UART0_Setup()	iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_UART0, iENABLE); \
						iPort_SetPinMuxControl(PORTD_BASE_PTR, 6, iPORT_MUX_CONTROL_ALT3);\
						iPort_SetPinMuxControl(PORTD_BASE_PTR, 7, iPORT_MUX_CONTROL_ALT3);\

#define UART1_Setup()	iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_UART1, iENABLE); \
				        iPort_SetPinMuxControl(PORTE_BASE_PTR, 0, iPORT_MUX_CONTROL_ALT3); \
				        iPort_SetPinMuxControl(PORTE_BASE_PTR, 1, iPORT_MUX_CONTROL_ALT3); \


#define UART2_Setup()	SIM_SCGC4 |= SIM_SCGC4_UART2_MASK; \
				        PORTD_PCR3 = PORT_PCR_MUX(0x3);	\
				        PORTD_PCR2 = PORT_PCR_MUX(0x3);\

#define UART3_Setup()	SIM_SCGC4 |= SIM_SCGC4_UART3_MASK;\
				        PORTC_PCR17 = PORT_PCR_MUX(0x3);\
				        PORTC_PCR16 = PORT_PCR_MUX(0x3);\

#define UART4_Setup()	SIM_SCGC1 |= SIM_SCGC1_UART4_MASK;\
				        PORTE_PCR24 = PORT_PCR_MUX(0x3);\
				        PORTE_PCR25 = PORT_PCR_MUX(0x3);\


#elif EJ151_REV1
#ifdef ES80SW
#define UART0_Setup()

#define UART1_Setup()	iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_UART1, iENABLE); \
				        iPort_SetPinMuxControl(PORTE_BASE_PTR,0, iPORT_MUX_CONTROL_ALT3);\
				        iPort_SetPinMuxControl(PORTE_BASE_PTR,1, iPORT_MUX_CONTROL_ALT3);\


#define UART2_Setup()


#define UART3_Setup()	iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_UART3, iENABLE);\
				        iPort_SetPinMuxControl(PORTE_BASE_PTR,4, iPORT_MUX_CONTROL_ALT3);\
				        iPort_SetPinMuxControl(PORTE_BASE_PTR,5, iPORT_MUX_CONTROL_ALT3);\

#define UART4_Setup()
#endif
#ifdef ES79SW
#endif
#elif EJ151_REV2

#ifdef ES80SW
#define UART0_Setup()

#define UART1_Setup()	iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_UART1, iENABLE); \
				        iPort_SetPinMuxControl(PORTE_BASE_PTR,0, iPORT_MUX_CONTROL_ALT3);\
				        iPort_SetPinMuxControl(PORTE_BASE_PTR,1, iPORT_MUX_CONTROL_ALT3);\


#define UART2_Setup()


#define UART3_Setup()	iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_UART3, iENABLE);\
				        iPort_SetPinMuxControl(PORTE_BASE_PTR,4, iPORT_MUX_CONTROL_ALT3);\
				        iPort_SetPinMuxControl(PORTE_BASE_PTR,5, iPORT_MUX_CONTROL_ALT3);\

#define UART4_Setup()
#endif

#ifdef ES79SW
#define UART0_Setup() 	iSIM_SetClockGate(SIM_BASE_PTR, iSIM_CLOCK_GATE_UART0, iENABLE); \
						iPort_SetPinMuxControl(PORTB_BASE_PTR,16, iPORT_MUX_CONTROL_ALT3);\
						iPort_SetPinMuxControl(PORTB_BASE_PTR,17, iPORT_MUX_CONTROL_ALT3);\


#define UART1_Setup()

#define UART2_Setup()

#define UART3_Setup()

#define UART4_Setup()
#endif

#endif
/*!
 * \brief Initialize the UART for 8N1 operation, interrupts disabled, and
 * no hardware flow-control
 *
 * NOTE: Since the UARTs are pinned out in multiple locations on most
 *       Kinetis devices, this driver does not enable UART pin functions.
 *       The desired pins should be enabled before calling this init function.
 *
 * \param[in] uartch      UART channel to initialize
 * \param[in] sysclk      UART module Clock in kHz(used to calculate baud)
 * \param[in] baud        UART baud rate
 */
void UART_Setup(UART_MemMapPtr channel, uint32 sysclk, uint32 baud)
{
    register uint16 sbr, brfa;
    uint8 temp;

    if (channel == UART0_BASE_PTR)
    {
    	UART0_Setup();
    }
    else if (channel == UART1_BASE_PTR)
    {
    	UART1_Setup();
    }

    else if (channel == UART2_BASE_PTR)
    {
    	UART2_Setup();
    }

    else if (channel == UART3_BASE_PTR)
    {
    	UART3_Setup();
    }
    else if (channel == UART4_BASE_PTR)
    {
    	UART4_Setup();
    }

    /* Make sure that the transmitter and receiver are disabled while we 
     * change settings.
     */
    UART_C2_REG(channel) &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

    /* Configure the UART for 8-bit mode, no parity */
    UART_C1_REG(channel) = 0; /* We need all default settings, so entire register is cleared */

    /* Calculate baud settings */
    sbr = (uint16) ((sysclk * 1000) / (baud * 16));

    /* Save off the current value of the UARTx_BDH except for the SBR field */
    temp = UART_BDH_REG(channel) & ~(UART_BDH_SBR(0x1F));

    UART_BDH_REG(channel) = temp | UART_BDH_SBR(((sbr & 0x1F00) >> 8));
    UART_BDL_REG(channel) = (uint8) (sbr & UART_BDL_SBR_MASK);

    /* Determine if a fractional divider is needed to get closer to the baud rate */
    brfa = (((sysclk * 32000) / (baud * 16)) - (sbr * 32));

    /* Save off the current value of the UARTx_C4 register except for the BRFA field */
    temp = UART_C4_REG(channel) & ~(UART_C4_BRFA(0x1F));

    UART_C4_REG(channel) = temp | UART_C4_BRFA(brfa);

    /* Enable receiver and transmitter */
    UART_C2_REG(channel) |= (UART_C2_TE_MASK | UART_C2_RE_MASK);
}

/*!
 * \brief Wait for a character to be received on the specified UART
 *
 * \param[in] channel      UART channel to read from
 * \return the received character.
 */
char UART_GetChar(UART_MemMapPtr channel)
{
    /* Wait until character has been received */
    while (!(UART_S1_REG(channel) & UART_S1_RDRF_MASK))
        ;

    /* Return the 8-bit data from the receiver */
    return UART_D_REG(channel);
}

/*!
 * \brief Wait for space in the UART Tx FIFO and then send a character
 *
 * \param[in] channel   UART channel to send to
 * \param[in] ch        character to send
 */
void UART_PutChar(UART_MemMapPtr channel, char ch)
{
    /* Wait until space is available in the FIFO */
    while (!(UART_S1_REG(channel) & UART_S1_TDRE_MASK));

    /* Send the character */
    UART_D_REG(channel) = (uint8) ch;
}

/*!
 * \brief Check to see if a character has beebn received
 *
 * \param[in] channel      UART channel to check for a character
 * \return 
 *  0       No character received
 *  1       Character has been received
 */
int UART_IsChar(UART_MemMapPtr channel)
{
    return (UART_S1_REG(channel) & UART_S1_RDRF_MASK);
}

void UART_EnableRxInterrupt(UART_MemMapPtr channel)
{
    /* Make sure that the transmitter and receiver are disabled while we change settings. */
    UART_C2_REG(channel) &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

    /* Enable Rx Interruption */
    UART_C2_REG(channel) |= UART_C2_RIE_MASK;

    /* Enable receiver and transmitter */
    UART_C2_REG(channel) |= (UART_C2_TE_MASK | UART_C2_RE_MASK);
}

void UART_EnableTxInterrupt(UART_MemMapPtr channel)
{
    /* Make sure that the transmitter and receiver are disabled while we change settings. */
    UART_C2_REG(channel) &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

    /* Enable Rx Interruption */
    UART_C2_REG(channel) |= UART_C2_TCIE_MASK;

    /* Enable receiver and transmitter */
    UART_C2_REG(channel) |= (UART_C2_TE_MASK | UART_C2_RE_MASK);
}

/** @} //end of group Watchdog_Driver_defines
 * @} // end of group Microcontroller_Driver_defines */
