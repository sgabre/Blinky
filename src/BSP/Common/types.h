/*
 * File:		types.h
 * Purpose:		Definitions common to all ARM Cortex M4 processors
 *
 * Notes:
 */

#ifndef _TYPES_H
#define _TYPES_H

/*
 * Misc. Defines
 */
#ifdef	FALSE
#undef	FALSE
#endif
#define FALSE	(0)

#ifdef	TRUE
#undef	TRUE
#endif
#define	TRUE	(1)

#ifdef	NULL
#undef	NULL
#endif
#define NULL	(0)

#ifdef  ON
#undef  ON
#endif
#define ON      (1)

#ifdef  OFF
#undef  OFF
#endif
#define OFF     (0)

/***********************************************************************/
/*
 * The basic data types
 */
typedef unsigned char		uint8;  /*  8 bits */
typedef unsigned short int	uint16; /* 16 bits */
typedef unsigned long int	uint32; /* 32 bits */

typedef signed char            int8;    /*  8 bits */
typedef signed short int       int16;   /* 16 bits */
typedef signed long int        int32;   /* 32 bits */

typedef signed char         sint8;   /*  8 bits */
typedef signed short int    sint16;  /* 16 bits */
typedef signed long int     sint32;  /* 32 bits */

typedef float	        	float32;  /* 32 bits */
typedef double		        float64;  /* 67 bits */

typedef volatile int8		vint8;  /*  8 bits */
typedef volatile int16		vint16; /* 16 bits */
typedef volatile int32		vint32; /* 32 bits */

typedef volatile uint8		vuint8;  /*  8 bits */
typedef volatile uint16		vuint16; /* 16 bits */
typedef volatile uint32		vuint32; /* 32 bits */

/***********************************************************************/
#endif	/* _TYPES_H */

