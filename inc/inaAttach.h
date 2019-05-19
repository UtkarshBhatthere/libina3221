#ifndef _ATTACH_H_
#define _ATTACH_H_

#include "inaTypes.h"

/*****************************************************************************
 * *************************** Instructions **********************************
 * @1: Just include inaTypes. in your API library (.c/.c++) file and define  *
 *     the below declared API's.                                             *
 * @2: Runtime Issues with the sensor may disturb the working of the INA3221 *
 *     chip, to prevent this multiple flags (with Hard Intrpt) are available *
 *     If error handling of this sort is to performed then kindly define the *
 *     specific handlers for the listed API's.                               *
 * @3: Since the device hosting the code will always be master we don't need *
 *     attach API's for Slave Config.                                        *
 *****************************************************************************/

inaErr_t inaI2CSend(inaModule_t module, inaRegAddr_t regAddr, inaRegContent_t* data, uint16_t datLen);
inaErr_t inaI2CReceive(inaModule_t module, inaRegAddr_t regAddr, inaRegContent_t* data, uint16_t datLen);


/* Layer 2.5 for alerts. */
inaErr_t inaPowerValidAlertHandler();
inaErr_t inaSummationAlertHandler();
inaErr_t inaCriticalAlertHandler(inaChannel_t channel);
inaErr_t inaWarningAlertHandler(inaChannel_t channel);
inaErr_t inaTimingControlAlertHandler();

#endif /*   @ATTACH    */