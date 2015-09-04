/*
 * File:		arm_cm4.h
 * Purpose:		Definitions common to all ARM Cortex M4 processors
 *
 * Notes:
 */

#ifndef _INTERRUPT_H
#define _INTERRUPT_H

/*ARM Cortex M4 implementation for interrupt priority shift*/
#define ARM_INTERRUPT_LEVEL_BITS          4

/***********************************************************************/
/* function prototypes for arm-cm4.c */
void stop (void);
void wait (void);

void Interrupt_Enable (int);
void Interrupt_Disable (int);
void Interrupt_SetPriority (int, int);

/***********************************************************************/
  /*!< Macro to enable all interrupts. */
#define EnableInterrupts() asm(" CPSIE i");/*LDRA_INSPECTED 183 S*/

  /*!< Macro to disable all interrupts. */
#define DisableInterrupts() asm(" CPSID i");/*LDRA_INSPECTED 183 S*/
/***********************************************************************/

/***********************************************************************/
#endif	/* _CPU_ARM_CM4_H */

