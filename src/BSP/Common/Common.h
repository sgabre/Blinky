/*
 * File:        common.h
 * Purpose:     File to be included by all project files
 *
 * Notes:
 */

#ifndef COMMON_H
#define COMMON_H

#include "BSP/Platforms/Platform.h"

#include <string.h>
#include "BSP/Common/types.h"

#include "BSP/MCU/INT/INT.h"

#ifdef TRACE_ON
#include <stdlib.h>
#include "Library/std/io.h"
#ifdef IAR
#include "intrinsics.h"
#endif
#endif

#include "BSP/Drivers/Trace/Trace.h"



#endif /* _COMMON_H_ */
