/*!
 * \file MCG.c
 *
 * TODO Give a brief description of the MCG.c file
 *
 * Notes:
 * Assumes the MCG mode is in the default FEI mode out of reset
 */

/* Common Inclusion */
#include "BSP/Common/Common.h"

/* Local Inclusion */
#include "BSP/MCU/MCG/MCG.h"

/* External Inclusion */

/* Private Macros Definition */
/* Constants for use in PLL Initialization & Configuration */
#define NO_OSCINIT 0
#define OSCINIT 1

#define OSC_0 0
#define OSC_1 1

#define LOW_POWER 0
#define HIGH_GAIN 1

#define CANNED_OSC  0
#define CRYSTAL 1

#define PLL_0 0
#define PLL_1 1

#define PLL_ONLY 0
#define MCGOUT 1
/* Private Constants Definition ============================================= */

/* Private Types Definition ================================================= */

/* Private Enumeration Definition =========================================== */

 /* Private Structures Definition  =========================================== */
typedef struct MCG_ts
{
	uint8 IsSetup;
	uint32 Clock; /*!< Clock in Hertz */
}MCG_ts;

/* Private Union Definition ================================================= */

/* Private variables  Definition ============================================ */
static MCG_ts mThis;

/* Private Functions Declaration  =========================================== */
static int pll_init(int crystal_val, unsigned char hgo_val, unsigned char erefs_val, signed char prdiv_val, signed char vdiv_val, unsigned char mcgout_select);

/* Public Functions Definition  ============================================= */

/*!
 * \brief Initializes & configures this Software Unit
 *
 * \return  none.
 */
void MCG_Setup(void)
{
	if(mThis.IsSetup == 0)
	{
		#if defined(NO_PLL_INIT)
		// ON REV 1.0 THE SLOW IRC IS NON-FUNCTIONAL AT < 2.05V. THE DEFAULT FREQUENCY WILL VARY FROM PART TO PART IN FEI MODE
        mThis.Clock = 21000000; //FEI mode
		#else
       /* Ramp up the system clock */
       /* Set the system dividers */
       /* NOTE: The PLL init will not configure the system clock dividers,
        * so they must be configured appropriately before calling the PLL
        * init function to ensure that clocks remain in valid ranges.
        */
        SIM_CLKDIV1 = ( 0
                        | SIM_CLKDIV1_OUTDIV1(0)
                        | SIM_CLKDIV1_OUTDIV2(0)
			| SIM_CLKDIV1_OUTDIV3(1)
                        | SIM_CLKDIV1_OUTDIV4(2) );

        if (PMC_REGSC &  PMC_REGSC_ACKISO_MASK)
        {
                /* Write to release hold on I/O */
        	PMC_REGSC |= PMC_REGSC_ACKISO_MASK; 
        }

       /* Initialize PLL */
       /* PLL will be the source for MCG CLKOUT so the core, system, and flash clocks are derived from it */
       mThis.Clock = pll_init(CLK0_FREQ_HZ,  /* CLKIN0 frequency */
                             LOW_POWER,     /* Set the oscillator for low power mode */
                             CLK0_TYPE,     /* Crystal or canned oscillator clock input */
                             PLL0_PRDIV,    /* PLL predivider value */
                             PLL0_VDIV,     /* PLL multiplier */
                             MCGOUT);       /* Use the output from this PLL as the MCGOUT */

       /* Check the value returned from pll_init() to make sure there wasn't an error */
       if (mThis.Clock < 0x100)
       {
         while(1);
       }
       #endif
	}
}

/*!
 * \brief System Clock Setter
 *
 * \param[in]  System Clock in Hz
 *
 * \retun None
 */
void MCG_SetClock(uint32 value)
{
	mThis.Clock = value;
}

/*!
 * \brief System Clock Getter
 *
 * \return  System Clock in Hz
 */
uint32 MCG_GetClock(void)
{
     return (mThis.Clock  / 1000);
}

/*!
 * \brief Core Clock Getter
 *
 * \return Core Clock in Hz
 */
uint32 MCG_GetCoreClock(void)
{
	return (mThis.Clock  / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV1_MASK) >> 28)+ 1) );
}

/*!
 * \brief Peripheral Clock Getter
 *
 * \return  Peripheral Clock in Hz
 */
uint32 MCG_GetBusClock(void)
{
	return (mThis.Clock  / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV2_MASK) >> 24)+ 1));
}

/*!
 * \brief FlexBus Clock Getter
 *
 * \return  FlexBus Clock in Hz
 */
uint32 MCG_GetFlexBusClock(void)
{
	return (mThis.Clock  / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV3_MASK) >> 20)+ 1));
}

/*!
 * \brief Flash Clock Getter
 *
 * \return  Flash Clock in Hz
 */
uint32 MCG_GetFlashClock(void)
{
	return (mThis.Clock  / (((SIM_CLKDIV1 & SIM_CLKDIV1_OUTDIV4_MASK) >> 16)+ 1));
}

 /*********************************************************************************************/
/* Functon name : pll_init
 *
 * Mode transition: Option to move from FEI to PEE mode or to just initialize the PLL
 *
 * This function initializess either PLL0 or PLL1. Either OSC0 or OSC1 can be selected for the
 * reference clock source. The oscillators can be configured to use a crystal or take in an
 * external square wave clock.
 * NOTE : This driver does not presently (as of Sept 9 2011) support the use of OSC1 as the
 * reference clock for the MCGOUT clock used for the system clocks.
 * The PLL outputs a PLLCLK and PLLCLK2X. PLLCLK2X is the actual PLL frequency and PLLCLK is
 * half this frequency. PLLCLK is used for MCGOUT and is also typically used by the
 * peripherals that can select the PLL as a clock source. So the PLL frequency generated will
 * be twice the desired frequency.
 * Using the function parameter names the PLL frequency is calculated as follows:
 * PLL freq = ((crystal_val / prdiv_val) * vdiv_val)
 * Refer to the readme file in the mcg driver directory for examples of pll_init configurations.
 * All parameters must be provided, for example crystal_val must be provided even if the
 * oscillator associated with that parameter is already initialized.
 * The various passed parameters are checked to ensure they are within the allowed range. If any
 * of these checks fail the driver will exit and return a fail/error code. An error code will
 * also be returned if any error occurs during the PLL initialization sequence. Refer to the
 * readme file in the mcg driver directory for a list of all these codes.
 *
 * Parameters: crystal_val - external clock frequency in Hz either from a crystal or square
 *                           wave clock source
 *             hgo_val     - selects whether low power or high gain mode is selected
 *                           for the crystal oscillator. This has no meaning if an
 *                           external clock is used.
 *             erefs_val   - selects external clock (=0) or crystal osc (=1)
 *             prdiv_val   - value to divide the external clock source by to create the desired
 *                           PLL reference clock frequency
 *             vdiv_val    - value to multiply the PLL reference clock frequency by
 *             mcgout_select  - 0 if the PLL is just to be enabled, non-zero if the PLL is used
 *                              to provide the MCGOUT clock for the system.
 *
 * Return value : PLL frequency (Hz) divided by 2 or error code
 */

static int pll_init(int crystal_val, unsigned char hgo_val, unsigned char erefs_val, signed char prdiv_val, signed char vdiv_val, unsigned char mcgout_select)
{
  unsigned char frdiv_val;
  unsigned char temp_reg;
  unsigned char prdiv, vdiv;
  short i;
  int ref_freq;
  int pll_freq;


  /* Check if in FEI mode */

    /* Step 1: Check FLL ref is internal ref clk */
     if( (MCG_S & MCG_S_IREFST_MASK) == 0x00)
    {
      /* Return error code */
      //EXCEPTION(INVALID_MODE);
      return 0x1;
    }

    /* Step 2: Check PLLS mux has selected FLL */
     if( (MCG_S & MCG_S_PLLST_MASK) != 0x00)
    {
      /* Return error code */
      //EXCEPTION(INVALID_MODE);
      return 0x1;
    }

    /* Step 3: check CLKS mux has selcted FLL output */
    if (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x00)
    {
      /* Return error code */
      //EXCEPTION(INVALID_MODE);
      return 0x1;
    }

    /* Check external frequency is less than the maximum frequency */
    if  (crystal_val > 50000000)
    {
      //EXCEPTION(INVALID_PARAM);
      return 0x21;
    }

    /* check crystal frequency is within spec. if crystal osc is being used as PLL ref */
    if (erefs_val)
    {
      if ((crystal_val < 3000000) || (crystal_val > 32000000))
      {
        /* return 1 if one of the available crystal options is not available */
        //EXCEPTION(INVALID_PARAM);
        return 0x22;
      }
    }

    /* make sure HGO will never be greater than 1. Could return an error instead if desired. */
    if (hgo_val > 0)
    {
      hgo_val = 1; // force hgo_val to 1 if > 0
    }

    /* Check PLL divider settings are within spec. */
    if ((prdiv_val < 1) || (prdiv_val > 25))
    {
      //EXCEPTION(INVALID_PARAM);
      return 0x41;
    }

    if ((vdiv_val < 24) || (vdiv_val > 55))
    {
      //EXCEPTION(INVALID_PARAM);
      return 0x42;
    }

    /* Check PLL reference clock frequency is within spec. */
    ref_freq = crystal_val / prdiv_val;

    if ((ref_freq < 2000000) || (ref_freq > 4000000))
    {
      //EXCEPTION(INVALID_PARAM);
      return 0x43;
    }

    /* Check PLL output frequency is within spec. */
    pll_freq = (crystal_val / prdiv_val) * vdiv_val;
    if ((pll_freq < 48000000) || (pll_freq > 100000000))
    {
      //EXCEPTION(INVALID_CONFIG);
      return 0x45;
    }

    /* configure the MCG_C2 register */
    // the RANGE value is determined by the external frequency. Since the RANGE parameter affects the FRDIV divide value
    // it still needs to be set correctly even if the oscillator is not being used

    temp_reg = MCG_C2;
    temp_reg &= ~(MCG_C2_RANGE0_MASK | MCG_C2_HGO0_MASK | MCG_C2_EREFS0_MASK); // clear fields before writing new values

    if (crystal_val <= 3000000)
    {
      temp_reg |= (MCG_C2_RANGE0(1) | (hgo_val << MCG_C2_HGO0_SHIFT) | (erefs_val << MCG_C2_EREFS0_SHIFT));
    }
    else
    {
      temp_reg |= (MCG_C2_RANGE0(2) | (hgo_val << MCG_C2_HGO0_SHIFT) | (erefs_val << MCG_C2_EREFS0_SHIFT));
    }
    MCG_C2 = temp_reg;

    // determine FRDIV based on reference clock frequency
    // since the external frequency has already been checked only the maximum frequency for each FRDIV value needs to be compared here.
    if (crystal_val <= 1250000)
    {
      frdiv_val = 0;
    }
    else if (crystal_val <= 2500000)
    {
      frdiv_val = 1;
    }
    else if (crystal_val <= 5000000)
    {
      frdiv_val = 2;
    }
    else if (crystal_val <= 10000000)
    {
      frdiv_val = 3;
    }
    else if (crystal_val <= 20000000)
    {
      frdiv_val = 4;
    }
    else
    {
      frdiv_val = 5;
    }

    // Select external oscillator and Reference Divider and clear IREFS to start ext osc
    // If IRCLK is required it must be enabled outside of this driver, existing state will be maintained
    // CLKS=2, FRDIV=frdiv_val, IREFS=0, IRCLKEN=0, IREFSTEN=0
    temp_reg = MCG_C1;
    temp_reg &= ~(MCG_C1_CLKS_MASK | MCG_C1_FRDIV_MASK | MCG_C1_IREFS_MASK); // Clear values in these fields
    temp_reg = MCG_C1_CLKS(2) | MCG_C1_FRDIV(frdiv_val); // Set the required CLKS and FRDIV values
    MCG_C1 = temp_reg;

    // if the external oscillator is used need to wait for OSCINIT to set
    if (erefs_val)
    {
      for (i = 0 ; i < 10000 ; i++)
      {
        if (MCG_S & MCG_S_OSCINIT0_MASK) break; // jump out early if OSCINIT sets before loop finishes
      }
      /* Check bit is really set and return with error if not set */
      if (!(MCG_S & MCG_S_OSCINIT0_MASK))
      {
        //EXCEPTION(NOT_AVAILABLE);
        return 0x23;
      }
    }

    /* Wait for clock status bits to show clock source is ext ref clk */
    for (i = 0 ; i < 2000 ; i++)
    {
      if (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) == 0x2) break; // jump out early if CLKST shows EXT CLK slected before loop finishes
    }
    /* check EXT CLK is really selected and return with error if not */
    if (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x2)
    {
      //EXCEPTION(NOT_AVAILABLE);
      return 0x1A;
    }

    // Now in FBE
    // It is recommended that the clock monitor is enabled when using an external clock as the clock source/reference.
    // It is enabled here but can be removed if this is not required.
    MCG_C6 |= MCG_C6_CME0_MASK;

    // Configure PLL
    // Configure MCG_C5
    // If the PLL is to run in STOP mode then the PLLSTEN bit needs to be OR'ed in here or in user code.
    temp_reg = MCG_C5;
    temp_reg &= ~MCG_C5_PRDIV0_MASK;
    temp_reg |= MCG_C5_PRDIV0(prdiv_val - 1);    //set PLL ref divider
    MCG_C5 = temp_reg;

    // Configure MCG_C6
    // The PLLS bit is set to enable the PLL, MCGOUT still sourced from ext ref clk
    // The loss of lock interrupt can be enabled by seperately OR'ing in the LOLIE bit in MCG_C6
    temp_reg = MCG_C6; // store present C6 value
    temp_reg &= ~MCG_C6_VDIV0_MASK; // clear VDIV settings
    temp_reg |= MCG_C6_PLLS_MASK | MCG_C6_VDIV0(vdiv_val - 24); // write new VDIV and enable PLL
    MCG_C6 = temp_reg; // update MCG_C6

    // wait for PLLST status bit to set
    for (i = 0 ; i < 2000 ; i++)
    {
      if (MCG_S & MCG_S_PLLST_MASK) break; // jump out early if PLLST sets before loop finishes
    }
    /* check bit is really set and return with error if not set */
    if (!(MCG_S & MCG_S_PLLST_MASK))
    {
      //EXCEPTION(NOT_AVAILABLE);
      return 0x16;
    }

    // Wait for LOCK bit to set
    for (i = 0 ; i < 2000 ; i++)
    {
      if (MCG_S & MCG_S_LOCK0_MASK) break; // jump out early if LOCK sets before loop finishes
    }

    /* check bit is really set and return with error if not set */
    if (!(MCG_S & MCG_S_LOCK0_MASK))
    {
      //EXCEPTION(NOT_AVAILABLE);
      return 0x44;
    }

    // Use actual PLL settings to calculate PLL frequency
    prdiv = ((MCG_C5 & MCG_C5_PRDIV0_MASK) + 1);
    vdiv = ((MCG_C6 & MCG_C6_VDIV0_MASK) + 24);

    // now in PBE

    MCG_C1 &= ~MCG_C1_CLKS_MASK; // clear CLKS to switch CLKS mux to select PLL as MCG_OUT

    // Wait for clock status bits to update
    for (i = 0 ; i < 2000 ; i++)
    {
      if (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) == 0x3) break; // jump out early if CLKST = 3 before loop finishes
    }
    /* check CLKST is set correctly and return with error if not */
    if (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x3)
    {
      //EXCEPTION(NOT_AVAILABLE);
      return 0x1B;
    }

    // Now in PEE

    return ((crystal_val / prdiv) * vdiv); //MCGOUT equals PLL output frequency
  } // pll_init



