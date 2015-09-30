
#include "BSP/Common/Common.h"
#include "BSP/MCU/INT/Vectors.h"
#include "BSP/MCU/INT/DefaultInterrupt.h"
#include "BSP/MCU/INT/NMIInterrupt.h"

extern uint32 __SP_INIT;
extern uint32 __sRAMVectorTable[];

/* Interrupt vector table type definition */
typedef void (*const Vector_t)(void);

typedef struct
{
  void * __ptr;
  Vector_t __Vector[0xFF];
} VectorTable_ts;




#ifdef IAR
  extern void __startup(void);
#elif (ARM)
 extern void __thumb_startup(void);
#endif




#ifdef IAR
#pragma location = ".intvec"
const VectorTable_ts __vector_table =
#elif (ARM)
  __attribute__ ((section (".vectortable"))) const VectorTable_ts __vector_table =  
#endif
{
	/*[ISR name                           | No. Address  	 | Priority | Name                          ]*/
    &__SP_INIT,                        /* 0x00  0x00000000   -   ivINT_Initial_Stack_Pointer    used by PE */
	{
#ifdef IAR
		(Vector_t)&__startup,
#elif (ARM)
		(Vector_t)&__thumb_startup,
#endif
		(Vector_t)&__NMIInterrupt,	/* 0x02  0x00000008  | 2   		| ivINT_NMI  					]*/
		(Vector_t)&__DefaultInterrupt,	/* 0x03  0x0000000C  | 1   		| ivINT_Hard_Fault              ]*/
		(Vector_t)&__DefaultInterrupt,	/* 0x04  0x00000010  | -   		| ivINT_Mem_Manage_Fault        ]*/
		(Vector_t)&__DefaultInterrupt,	/* 0x05  0x00000014  | -   		| ivINT_Bus_Fault        		]*/
		(Vector_t)&__DefaultInterrupt,	/* 0x06  0x00000018  | -   		| ivINT_Usage_Fault        		]*/
		(Vector_t)&__DefaultInterrupt,		/* 0x07  0x0000001C  | -   		| ivINT_Reserved7               ]*/
		(Vector_t)&__DefaultInterrupt,		/* 0x08  0x00000020  | -   		| ivINT_Reserved8               ]*/
		(Vector_t)&__DefaultInterrupt,		/* 0x09  0x00000024  | -   		| ivINT_Reserved9               ]*/
		(Vector_t)&__DefaultInterrupt,		/* 0x0A  0x00000028  | -   		| ivINT_Reserved10              ]*/
		(Vector_t)&__DefaultInterrupt,		/* 0x0B  0x0000002C  | -   		| ivINT_SVCall                  ]*/
		(Vector_t)&__DefaultInterrupt,		/* 0x0C  0x00000030  | -   		| ivINT_DebugMonitor            ]*/
		(Vector_t)&__DefaultInterrupt,		/* 0x0D  0x00000034  | -   		| ivINT_Reserved13              ]*/
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
		(Vector_t)&__DefaultInterrupt,
	}
};
void Vector_PlugIn(uint16 irq,uint32 FunctionAddress)
{
   if(FunctionAddress != 0)
   {
    	 __sRAMVectorTable[irq] = (uint32)FunctionAddress;   // plug isr into vector table in case not there already
   }
}



void Vector_Write(uint32_t vtor)
{
        /* Write the VTOR with the new value */
	  SCB_VTOR = (uint32_t)(vtor); /* Set the interrupt vector table position */
}



