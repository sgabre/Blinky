/* GNUC Startup library
 *    Copyright � 2005 Freescale semiConductor Inc. All Rights Reserved.
 *
 * $Date: 2011/09/21 06:41:34 $
 * $Revision: 1.4 $
 */


/*
 *	startup.c	-	entry-point for ARM programs
 *
 */
#include "BSP/Common/Common.h"
#include <string.h>
#include <stdlib.h>
#include "BSP/MCU/MK20D7.h"
#include "BSP/MCU/INT/Vectors.h"
#include "BSP/MCU/Watchdog/Watchdog.h"

#define __MAX_CMDLINE_ARGS 10
static char *argv[__MAX_CMDLINE_ARGS] = { 0 };

#if __GNUC__
#define __call_static_initializers __init_cpp
#endif
extern int __argc_argv(char **, int);
extern char __SP_INIT[];
extern void __call_static_initializers(void);
extern int main(int, char **);

extern void _start(void);

extern void Registers_Setup();
extern void User_Setup();


extern void __copy_rom_sections_to_ram(void);
/*
 * Routine to flush cache follow the ROM to RAM copy
 */
void __FlushCache(unsigned long dst, unsigned long size)
{
	//TBD
}


/*
 *	Routine to copy a single section from ROM to RAM ...
 */
void __CopyROMSection(unsigned long dst, unsigned long src, unsigned long size)
{
	unsigned long len = size;

	const int size_int = sizeof(int);
	const int mask_int = sizeof(int)-1;

	const int size_short = sizeof(short);
	const int mask_short = sizeof(short)-1;

	const int size_char = sizeof(char);

	if( dst == src || size == 0)
	{
		return;
	}


	while( len > 0)
	{

		if( !(src & mask_int) && !(dst & mask_int) && len >= size_int)
		{
			*((int *)dst)  = *((int*)src);
			dst += size_int;
			src += size_int;
			len -= size_int;
		}
		else if( !(src & mask_short) && !(dst & mask_short) && len >= size_short)
		{
			*((short *)dst)  = *((short*)src);
			dst += size_short;
			src += size_short;
			len -= size_short;
		}
		else
		{
			*((char *)dst)  = *((char*)src);
			dst += size_char;
			src += size_char;
			len -= size_char;
		}
	}
}


static void BSS_Setup(void)
{
	extern char __START_BSS[];
	extern char __END_BSS[];

	unsigned long len = __END_BSS - __START_BSS;
  unsigned long dst = (unsigned long) __START_BSS;

	const int size_int = sizeof(int);
	const int mask_int = sizeof(int)-1;

	const int size_short = sizeof(short);
	const int mask_short = sizeof(short)-1;

	const int size_char = sizeof(char);

	if( len == 0)
	{
		return;
	}


	while( len > 0)
	{

		if( !(dst & mask_int) && len >= size_int)
		{
			*((int *)dst)  = 0;
			dst += size_int;
			len -= size_int;
		}
		else if( !(dst & mask_short) && len >= size_short)
		{
			*((short *)dst)  = 0;
			dst += size_short;
			len -= size_short;
		}
		else
		{
			*((char *)dst)  = 0;
			dst += size_char;
			len -= size_char;
		}
	}
}


// __init_registers, __init_hardware, __init_user suggested by Kobler
#ifdef ARM
void __attribute__ ((weak)) Registers_Setup(void)
#elif IAR
void Registers_Setup(void)
#endif
{
  #if defined(SCB_CPACR)
  /* Initialize FPU */
  SCB_CPACR |= SCB_CPACR_CP10(3U) | SCB_CPACR_CP11(3U); 
  #endif

}

#ifdef ARM
void __attribute__ ((weak)) User_Setup(void)
#elif IAR
void  User_Setup(void)
#endif
{

}


// To keep iar debugger happy
void __iar_program_start(void);
void __thumb_startup(void);
void __iar_program_start()
{
	__thumb_startup();
}

void __thumb_startup(void)
{
		int addr = (int)__SP_INIT;

	    extern unsigned long ___ROM_AT[];
	    extern unsigned long _sdata[];
	    extern unsigned long ___data_size;

	    extern unsigned long __sVectorTable;
	    extern unsigned long __sRAMVectorTable;
	    extern unsigned long __VectorTableSize;


	    unsigned long data_ram = (unsigned long)&_sdata;
	    unsigned long data_rom = (unsigned long)&___ROM_AT;
	    unsigned long size     = (unsigned long)&___data_size; /* This is actually a RAM address in CodeWarrior */

		// Setup registers
		Registers_Setup();

		  /*** PE initialization code after reset ***/
		  SCB_VTOR = (uint32_t)(&__sVectorTable); /* Set the interrupt vector table position */
		  //Vector_Write(uint32_t vtor);

		  Watchdog_Disable();

		// setup the stack before we attempt anything else
		// skip stack setup if __SP_INIT is 0
		// assume sp is already setup.
		  //asm("mov r0,%0");
		  __asm (
		"mov	r0,%0\n\t"
		"cmp	r0,#0\n\t"
		"beq	skip_sp\n\t"
		"mov	sp,r0\n\t"
		"sub	sp,#4\n\t"
		"mov	r0,#0\n\t"
		"mvn	r0,r0\n\t"
		"str	r0,[sp,#0]\n\t"
		"add	sp,#4\n\t"
		"skip_sp:\n\t"
		::"r"(addr));


		//	zero-fill the .bss section
		BSS_Setup();

		__CopyROMSection(data_ram, data_rom, size);


		__CopyROMSection((uint32_t)&__sRAMVectorTable, (uint32_t)&__sVectorTable,0x400);
		SCB_VTOR = (uint32_t)(&__sRAMVectorTable); /* Set the interrupt vector table position */

		//	call C++ static initializers
		//  __call_static_initializers();

		// initializations before main, user specific
		User_Setup();

		main(0, argv);

		//	should never get here
		while (1);

}

