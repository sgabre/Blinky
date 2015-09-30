/*
 * File:	start.c
 * Purpose:	Kinetis start up routines. 
 *
 * Notes:		
 */


#include "BSP/Common/Common.h"
#include "BSP/MCU/Watchdog/Watchdog.h"

#ifdef IAR
    #pragma section = ".data"
    #pragma section = ".data_init"
    #pragma section = ".bss"
    #pragma section = "CodeRelocate"
    #pragma section = "CodeRelocateRam"
#endif

extern void main(void);

/*
 * Routine to flush cache follow the ROM to RAM copy
 */
void __FlushCache(unsigned long dst, unsigned long size)
{
    //TBD
}

/*
 *  Routine to copy a single section from ROM to RAM ...
 */
void __CopyROMSection(unsigned long dst, unsigned long src, unsigned long size)
{
    unsigned long len = size;

    const int size_int = sizeof(int);
    const int mask_int = sizeof(int) - 1;

    const int size_short = sizeof(short);
    const int mask_short = sizeof(short) - 1;

    const int size_char = sizeof(char);

    if (dst == src || size == 0)
    {
        return;
    }

    while (len > 0)
    {

        if (!(src & mask_int) && !(dst & mask_int) && len >= size_int)
        {
            *((int *) dst) = *((int*) src);
            dst += size_int;
            src += size_int;
            len -= size_int;
        }
        else if (!(src & mask_short) && !(dst & mask_short) && len >= size_short)
        {
            *((short *) dst) = *((short*) src);
            dst += size_short;
            src += size_short;
            len -= size_short;
        }
        else
        {
            *((char *) dst) = *((char*) src);
            dst += size_char;
            src += size_char;
            len -= size_char;
        }
    }
}

static void BSS_Setup(unsigned long dst, unsigned long len)
{
    const int size_int = sizeof(int);
    const int mask_int = sizeof(int) - 1;

    const int size_short = sizeof(short);
    const int mask_short = sizeof(short) - 1;

    const int size_char = sizeof(char);

    if (len == 0)
    {
        return;
    }

    while (len > 0)
    {

        if (!(dst & mask_int) && len >= size_int)
        {
            *((int *) dst) = 0;
            dst += size_int;
            len -= size_int;
        }
        else if (!(dst & mask_short) && len >= size_short)
        {
            *((short *) dst) = 0;
            dst += size_short;
            len -= size_short;
        }
        else
        {
            *((char *) dst) = 0;
            dst += size_char;
            len -= size_char;
        }
    }
}

void __thumb_startup(void)
{ 
	/* Disable the watchdog timer */
    Watchdog_Disable();

#ifdef ARM
    extern char _sBSS[];
    extern char _eBSS[];
    extern uint32 _sROMData;
    extern uint32 _sRAMData;
    extern char _eRAMData[];
#endif

    /* Declare a counter we'll use in all of the copy loops */
    uint32 size;

    /* Declare pointers for various data sections. These pointers
     * are initialized using values pulled in from the linker file
     */
    uint8* sRAMData;
    uint8* sROMData;
    uint8* eROMData;
    uint8* sBSS;
    uint8* eBSS;


    /* Addresses for VECTOR_TABLE and VECTOR_RAM come from the linker file */
    extern uint32 __sVectorTable[];
    extern uint32 __sRAMVectorTable[];

    /* Copy the vector table to RAM */
    if (__sRAMVectorTable != __sVectorTable)
    {
        for (size = 0; size < 0x104; size++)
            __sRAMVectorTable[size] = __sVectorTable[size];
    }
    /* Point the VTOR to the new copy of the vector table */
    Vector_Write((uint32)__sRAMVectorTable);

    /* Get the addresses for the .bss section (zero-initialized data) */
    #ifdef ARM
    extern char _sBSS[];
    extern char _eBSS[];
    #elif (defined(IAR))
    sBSS = __section_begin(".bss");
    eBSS = __section_end(".bss");
    #endif


    /* Clear the zero-initialized data section */
    size = eBSS - sBSS;
    while(size--)
    {
      *sBSS++ = 0;
    }


    /* Get the addresses for the .data section (initialized data section) */
    #ifdef ARM
    sRAMData = (uint8 *)_sRAMData;
    sROMData = (uint8 *)_sROMData;
    eROMData  = (uint8 *)_eRAMData;
    size = (unsigned long) (((unsigned long) &_eRAMData) - ((unsigned long) &_sRAMData));;
    #elif (defined(IAR))
    sRAMData = __section_begin(".data");
    sROMData = __section_begin(".data_init");
    eROMData = __section_end(".data_init");
    #endif

    /* Copy initialized data from ROM to RAM */
    size = eROMData - sROMData;
    while (size--)
    {
        *sRAMData++ = *sROMData++;
    }
    
    

    /* Get addresses for any code sections that need to be copied from ROM to RAM.
     * The IAR tools have a predefined keyword that can be used to mark individual
     * functions for execution from RAM. Add "__ramfunc" before the return type in
     * the function prototype for any routines you need to execute from RAM instead
     * of ROM. ex: __ramfunc void foo(void);
     */
    #ifdef IAR
    uint8* code_relocate_ram = __section_begin("CodeRelocateRam");
    uint8* code_relocate = __section_begin("CodeRelocate");
    uint8* code_relocate_end = __section_end("CodeRelocate");

        /* Copy functions from ROM to RAM */
        size = code_relocate_end - code_relocate;
        while (size--)
          *code_relocate_ram++ = *code_relocate++;
    #endif



	/* Jump to main process */
	main();

	/* No actions to perform after this so wait forever */
	while(1);
}
