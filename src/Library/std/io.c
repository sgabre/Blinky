/*
 * File:		io.c
 * Purpose:		Serial Input/Output routines
 *
 * Notes:       TERMINAL_PORT defined in <board>.h
 */

#include "BSP/Common/Common.h"
#include "BSP/MCU/UART/UART.h"

/********************************************************************/
char
in_char (void)
{
	return UART_GetChar(TERM_PORT);
}
/********************************************************************/
void
out_char (char ch)
{
	UART_PutChar(TERM_PORT, ch);
}
/********************************************************************/
int
char_present (void)
{
	return UART_IsChar(TERM_PORT);
}
/********************************************************************/
