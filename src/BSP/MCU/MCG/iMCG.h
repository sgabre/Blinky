/*
 * iMCG.h
 *
 *  Created on: 4 sept. 2015
 *      Author: GSI
 */

#ifndef IMCG_H_
#define IMCG_H_

//MCG_C1
#define iMCG_SetClock(PeripheralBase, Divider)
#define iMCG_SetFLLExternalReferenceDivider(PeripheralBase, value)
#define iMCG_SetInternalReferenceSelect(PeripheralBase, value)
#define iMCG_SetInternalReferenceClock(PeripheralBase, state)
#define iMCG_SetInternalReferenceStop(PeripheralBase, state)

//MCG_C2
#define iMCG_SetLossClockReset(PeripheralBase, state)
#define iMCG_SetFrequencyRange(PeripheralBase, value)
#define iMCG_SetHighGainOscillator(PeripheralBase, value)
#define iMCG_SetExternalReference(PeripheralBase, value)
#define iMCG_SetLowPower(PeripheralBase, value)
#define iMCG_SetInternalReferenceClock(PeripheralBase, value)

//MCG_C3
#define iMCG_SetSlowInternalReferenceClockTrimSetting(PeripheralBase, value)

//MCG_C4
#define iMCG_SetDCOMaximumFrequency(PeripheralBase, value)
#define iMCG_SetDCORange(PeripheralBase, value)
//Fast Internal Reference Clock Trim Setting
//Slow Internal Reference Clock Fine Trim

//MCG_C5
/*
PLLClock
PLL Stop
PLL External Reference Divider
*/
//MCG_C6
/*
Loss of Lock Interrrupt Enable
PLL Select
Clock Monitor Enable
PLLVCO 0 Divider
*/

//MCG_S
/*
Loss of Lock Status
Lock Status
PLL Select Status
Internal Reference Status
Clock Mode Status
OSC Initialization
Internal Reference Clock Status
*/

//MCG_SC
/*
Automatic Trim Machine Enable
Automatic Trim Machine Select
Automatic Trim Machine Fail Flag
FLL Filter Preserve Enable
Fast Clock Internal Reference Divider
OSC0 Loss of Clock Status
*/

//MCG_ATCVH
//ATM Compare Value High
//MCG_ATCVL
//ATM Compare Value Low

//MCG_C7
//MCG OSC Clock Select


//MCG_C8
/*
Loss of Clock Reset Enable
Clock Monitor Enable1
RTC Loss of Clock Status
*/


#endif /* IMCG_H_ */
