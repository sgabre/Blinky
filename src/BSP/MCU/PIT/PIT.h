/*
 * PIT.h
 *
 *  Created on: 30 avr. 2014
 *      Author: gsi
 */

#ifndef PIT_H_
#define PIT_H_

void PIT_Setup(uint32 FunctionAddress);
void PIT_ClearInterruptFlag(void);
void PIT_Start(void);
void PIT_Stop(void);
void PIT_SetPeriod(uint32 period);

#endif /* PIT_H_ */
