/*
 * FlashConfiguration.c
 *
 *  Created on: 2 sept. 2015
 *      Author: GSI
 */
#include "BSP/Common/Common.h"



/* Flash configuration field */
#if defined(IAR)
#pragma location = ".cfmconfig"
const uint8 __FlashConfigurationtable[0x10] =
#elif ARM
__attribute__ ((section (".cfmconfig"))) const uint8 __FlashConfigurationtable[0x10] =
#endif
{
/* NV_BACKKEY3: KEY=0xFF */
0xFFU,
/* NV_BACKKEY2: KEY=0xFF */
0xFFU,
/* NV_BACKKEY1: KEY=0xFF */
0xFFU,
/* NV_BACKKEY0: KEY=0xFF */
0xFFU,
/* NV_BACKKEY7: KEY=0xFF */
0xFFU,
/* NV_BACKKEY6: KEY=0xFF */
0xFFU,
/* NV_BACKKEY5: KEY=0xFF */
0xFFU,
/* NV_BACKKEY4: KEY=0xFF */
0xFFU,
/* NV_FPROT3: PROT=0xFF */
0xFFU,
/* NV_FPROT2: PROT=0xFF */
0xFFU,
/* NV_FPROT1: PROT=0xFF */
0xFFU,
/* NV_FPROT0: PROT=0xFF */
0xFFU,
/* NV_FSEC: KEYEN=1,MEEN=3,FSLACC=3,SEC=2 */
0x7EU,
/* NV_FOPT: ??=1,??=1,??=1,??=1,??=1,NMI_DIS=1,EZPORT_DIS=1,LPBOOT=1 */
0xFFU,
/* NV_FEPROT: EPROT=0xFF */
0xFFU,
/* NV_FDPROT: DPROT=0xFF */
0xFFU
};
