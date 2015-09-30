/*
 * CPU.c
 *
 *  Created on: 8 janv. 2015
 *      Author: gsi
 */
#include "BSP/Common/Common.h"

#include "BSP/MCU/CPU/CPU.h"
#include "BSP/MCU/MCG/MCG.h"

/* Global variables */
volatile uint8_t SR_reg;               /* Current value of the FAULTMASK register */
volatile uint8_t SR_lock = 0x00U;      /* Lock */

void Cpu_SetBASEPRI(uint32_t Level);

/*
** ===================================================================
**     Method      :  Cpu_SetBASEPRI (component MK20DX256LL7)
**
**     Description :
**         This method sets the BASEPRI core register.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Cpu_SetBASEPRI(uint32_t Level)
{
	__asm ("msr basepri, %[input]"::[input] "r" (Level):);
}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MK20DX256LL7)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CPU_Setup(void)
{
	MCG_Setup();

	/* Initialization of the SIM module */
  /* PORTA_PCR4: ISF=0,MUX=7 */
  //PORTA_PCR4 = (uint32_t)((PORTA_PCR4 & (uint32_t)~(uint32_t)(PORT_PCR_ISF_MASK)) | (uint32_t)(PORT_PCR_MUX(0x07)));

  /* Initialization of the RCM module */
  /* RCM_RPFW: RSTFLTSEL=0 */
  //RCM_RPFW &= (uint8_t)~(uint8_t)(RCM_RPFW_RSTFLTSEL(0x1F));
  /* RCM_RPFC: RSTFLTSS=0,RSTFLTSRW=0 */
  //RCM_RPFC &= (uint8_t)~(uint8_t)(RCM_RPFC_RSTFLTSS_MASK |RCM_RPFC_RSTFLTSRW(0x03));

  /* Initialization of the FTFL_FlashConfig module */
  /* Initialization of the PMC module */
  /* PMC_LVDSC1: LVDACK=1,LVDIE=0,LVDRE=1,LVDV=0 */
  //PMC_LVDSC1 = (uint8_t)((PMC_LVDSC1 & (uint8_t)~(uint8_t)(PMC_LVDSC1_LVDIE_MASK |PMC_LVDSC1_LVDV(0x03))) | (uint8_t)(PMC_LVDSC1_LVDACK_MASK |PMC_LVDSC1_LVDRE_MASK));
  /* PMC_LVDSC2: LVWACK=1,LVWIE=0,LVWV=0 */
  //PMC_LVDSC2 = (uint8_t)((PMC_LVDSC2 & (uint8_t)~(uint8_t)(PMC_LVDSC2_LVWIE_MASK |PMC_LVDSC2_LVWV(0x03))) | (uint8_t)(PMC_LVDSC2_LVWACK_MASK));
  /* PMC_REGSC: BGEN=0,ACKISO=0,BGBE=0 */
  //PMC_REGSC &= (uint8_t)~(uint8_t)(PMC_REGSC_BGEN_MASK |PMC_REGSC_ACKISO_MASK |PMC_REGSC_BGBE_MASK);
  /* SMC_PMPROT: ??=0,??=0,AVLP=0,??=0,ALLS=0,??=0,AVLLS=0,??=0 */
  //SMC_PMPROT = 0x00U;                  /* Setup Power mode protection register */

	/* Common initialization of the CPU registers */
  /* NVICIP20: PRI20=0 */
  //NVICIP20 = NVIC_IP_PRI20(0x00);
  /* Enable interrupts of the given priority level */
  //Cpu_SetBASEPRI(0U);
}
