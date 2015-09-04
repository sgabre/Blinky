/*
 * LED.h
 *
 *  Created on: 17 févr. 2015
 *      Author: GSI
 */

#ifndef LED_H_
#define LED_H_

typedef enum eLED
{
  eGreen,
  eBlue,
  eDMAX
}eLED;

void Led_Setup(void);
void Led_Blink(uint8 led);
void Led_On(uint8 led);
void Led_Off(uint8 led);

#endif /* LED_H_ */
