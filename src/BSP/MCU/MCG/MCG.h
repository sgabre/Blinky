#ifndef MCG_H
#define MCG_H

void MCG_Setup(void);
void MCG_SetClock(uint32 value);
uint32 MCG_GetClock(void);
uint32 MCG_GetCoreClock(void);
uint32 MCG_GetBusClock(void);
uint32 MCG_GetFlexBusClock(void);
uint32 MCG_GetFlashClock(void);



/********************************************************************/
#endif /* __MCG_H__ */
