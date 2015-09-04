/******************************************************************************
 * File:    vectors.c
 *
 * Purpose: Configure interrupt vector table for Kinetis.
 ******************************************************************************/

#include "BSP/Common/Common.h"
#include "BSP/MCU/INT/Vectors.h"

#define CONFIG_1        (pointer*)0xffffffff
#define CONFIG_2        (pointer*)0xffffffff
#define CONFIG_3        (pointer*)0xffffffff
#define CONFIG_4        (pointer*)0xfffffffe



/******************************************************************************
 * Vector Table
 ******************************************************************************/
typedef void pointer(void);
typedef void (*vector_entry)( void );


extern unsigned long __BOOT_STACK_ADDRESS[];
extern void __startup(void);
extern uint32 __RVT[];

void default_isr(void);
void abort_isr(void);
void hard_fault_handler_c(unsigned int * hardfault_args);
void HardFaultHandler(void);



#ifdef IAR
#pragma location = ".VectorTable"
const vector_entry __vector_table[] = //@ ".intvec" =
#else
__attribute__ ((section (".vectortable"))) const vector_entry __vector_table =
#endif
{
    (pointer*)__BOOT_STACK_ADDRESS,
    __startup,
    HardFaultHandler,
    HardFaultHandler,
    HardFaultHandler,
    HardFaultHandler,
    HardFaultHandler,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,
    default_isr,

};
// VECTOR_TABLE end
/******************************************************************************
 * default_isr(void)
 *
 * Default ISR definition.
 *
 * In:  n/a
 * Out: n/a
 ******************************************************************************/
void default_isr( void )
{
#define VECTORNUM                     (*(volatile uint8_t*)(0xE000ED04))
    //ERROR("\n****default_isr entered on vector %d*****\r\n\n", VECTORNUM);
    return;
}
/******************************************************************************/
/* Generic interrupt handler for the PTA4 GPIO interrupt connected to an 
 * abort switch. 
 * NOTE: For true abort operation this handler should be modified
 * to jump to the main process instead of executing a return.
 */
void abort_isr( void )
{
    /* Write 1 to the PTA4 interrupt flag bit to clear the interrupt */
    PORTA_PCR4 |= PORT_PCR_ISF_MASK;

    //TRACE("\n****Abort button interrupt****\n\n");
    return;
}
/******************************************************************************/
/* Exception frame without floating-point storage 
 * hard fault handler in C,
 * with stack frame location as input parameter
 */
void HardFaultHandler(void)
{
  /*
    //Exception stack frame  
    TRACE("[\nHard fault handler]\n");
    TRACE("BusFault Status Register[BFAR] = %x\n", (*((volatile unsigned long *) (0xE000ED38))));
    TRACE("Configurable Fault Status Register [CFSR] = %x\n", (*((volatile unsigned long *) (0xE000ED28))));
    TRACE("HardFault Status Register [HFSR] = %x\n", (*((volatile unsigned long *) (0xE000ED2C))));
    TRACE("DFSR = %x\n", (*((volatile unsigned long *) (0xE000ED30))));
    TRACE("Auxiliary Fault Status Register [AFSR] = %x\n", (*((volatile unsigned long *) (0xE000ED3C))));
    TRACE("MemManage Fault Address Register [MMAR] = %x\n", (*((volatile unsigned long *) (0xE000ED34))));// GoSi Not able to check if the MMAR register addres is correct
    */
    for(;;);/*infinite loop*/
}

/***********************************************************************/
/*
 * Change the value of the vector table offset register to the specified value.
 *
 * Parameters:
 * vtor     new value to write to the VTOR
 */

void Vector_Write(int vtor)
{
        /* Write the VTOR with the new value */
        SCB_VTOR = vtor;
}


void Vector_PlugIn(uint16 irq,uint32 FunctionAddress)
{
   if(FunctionAddress != 0)
   {
       __RVT[irq] = (uint32)FunctionAddress;   // plug isr into vector table in case not there already
   }
}

/* End of "vectors.c" */
