/*
 * Delay.h
 *
 *  Created on: 4 sept. 2015
 *      Author: GSI
 */

#ifndef DELAY_H_
#define DELAY_H_



#define _SEC			BUS_CLOCK_HZ
#define _MS				_SEC/1000
#define _US				_MS/1000


void Delay(uint32 value);

#endif /* DELAY_H_ */
