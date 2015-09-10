/*!
 * \file Trace.h
 *
 * TODO Give a brief description of the Trace.h file
 */

#ifndef TRACE_H_
#define TRACE_H_

#ifdef TRACE_ON
#include <stdlib.h>
#include "Library/std/io.h"
#ifdef IAR
#include "intrinsics.h"
#endif
#endif


/* Public Macros Definition */
#ifdef TRACE_ON
#define TRACE printf
#else
#define TRACE
#endif

/* Public Constants Definition ============================================= */

/* Public Types Definition ================================================= */

/* Public Enumeration Definition =========================================== */

/* Public Structures Definition  =========================================== */

/* Public Union Definition ================================================= */

/* Public variables  Definition ============================================ */

/* Public Functions Declaration  =========================================== */



void Trace_Setup(void);
void TraceLong(uint8 type, uint32 value);
void TraceFloat(uint8 type, float32 value);
void Trace_Reset(void);
#endif /* TRACE_H_ */
