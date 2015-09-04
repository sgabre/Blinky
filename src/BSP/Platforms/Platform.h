#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifdef TWR_K20D72M
	#include "BSP/MCU/MK20D7.h"
	#include "BSP/Platforms/Tower.h"
#else
    #error "No valid platform defined"
#endif

#endif
