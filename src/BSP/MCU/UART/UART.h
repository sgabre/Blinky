/**
 * @file UART.h
 * @version 1.0
 * @date 2011-11-15
 * @brief Provide common UART routines for polled serial IO
 */
#ifndef __UART_H__
#define __UART_H__

void UART_Setup (UART_MemMapPtr,uint32 sysclk, uint32 baud);
char UART_GetChar (UART_MemMapPtr);
void UART_PutChar (UART_MemMapPtr,  char ch);
int UART_IsChar (UART_MemMapPtr);
void UART_EnableRxInterrupt(UART_MemMapPtr channel);
void UART_EnableTxInterrupt(UART_MemMapPtr channel);

#endif /* __UART_H__ */
