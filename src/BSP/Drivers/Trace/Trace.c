/*!
 * \file Trace.c
 *
 * TODO Give a brief description of the Trace.c file
 */

/* Common Inclusion */
#include "BSP/Common/Common.h"

/* Local Inclusion */
#include "BSP/Drivers/Trace/Trace.h"

/* External Inclusion */
#include "BSP/MCU/MCG/MCG.h"
#include "BSP/MCU/UART/UART.h"

/* Private Macros Definition */

/* Private Constants Definition ============================================= */

/* Private Types Definition ================================================= */

/* Private Enumeration Definition =========================================== */

 /* Private Structures Definition  =========================================== */
#ifdef TRACE_ON
typedef struct Trace_ts
{
    uint8 IsSetup;
}Trace_ts;
/* Private Union Definition ================================================= */

/* Private variables  Definition ============================================ */
static Trace_ts mThis;

/* Private Functions Declaration  =========================================== */
static void Trace_SetupPort(void);
#endif

/* Public Functions Definition  ============================================= */

/*LDRA_HEADER_END*/
/*!
 * \brief Initializes & configures this Software Unit
 *
 * \global [out] mThis.IsSetup is set as initialized and configured
 *
 * \return  none.
 *
 * \UT ES-080B System #16
 */

void Trace_Setup(void)
{
#ifdef TRACE_ON
    if(mThis.IsSetup == 0U)
    {
        SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
        SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;

        SIM_SOPT2 |= SIM_SOPT2_TRACECLKSEL_MASK; /* Set the trace clock to the core clock frequency */
        /* Enable the TRACE_CLKOUT pin function on PTA6 (alt7 function) */
        /* Enable high drive strength to support high toggle rate */
        PORTA_PCR6 = ( PORT_PCR_MUX(0x7) | PORT_PCR_DSE_MASK);
        /*LDRA_ANALYSIS*/
        Trace_SetupPort();
        mThis.IsSetup = 1U;
    }
#endif
}

#ifdef TRACE_ON
/*!
 * \brief Initializes & configures the Debug Port
 *
 * \return  none.
 *
 * \UT ES-080B System #17
 */
static void Trace_SetupPort(void)
{
	uint32 Clock = 0;
	Clock = MCG_GetClock();
	UART_Setup(TERM_PORT, Clock, TERMINAL_BAUD);
}


void Trace_Reset(void)
{
	memset(&mThis,0,sizeof(Trace_ts));
}

#endif
