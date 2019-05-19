#ifndef _API_H_
#define _API_H_

#include "inaRegisterMap.h"
#include "inaTypes.h"
#include "inaAttach.h"

/*   API's   */

/*   Layer-1 API's --HAL--   */
/*   Reading Registers   */
inaRegContent_t inaReadConfigReg(inaModule_t module);
inaRegContent_t inaReadBusVoltageRaw(inaModule_t module, inaChannel_t channel);
inaRegContent_t inaReadShuntVoltageRaw(inaModule_t module, inaChannel_t channel);
inaRegContent_t inaReadCritialLimit(inaModule_t module, inaChannel_t channel);
inaRegContent_t inaReadWarningLimit(inaModule_t module, inaChannel_t channel);
inaRegContent_t inaReadShuntSum(inaModule_t module);
inaRegContent_t inaReadShuntSumLimit(inaModule_t module);
inaRegContent_t inaReadEnableMask(inaModule_t module);
inaRegContent_t inaReadUpperPowerLimit(inaModule_t module);
inaRegContent_t inaReadLowerPowerLimit(inaModule_t module);
inaRegContent_t inaReadManufacturerID(inaModule_t module);
inaRegContent_t inaReadDieID(inaModule_t module);

/*   Writing Registers   */
inaErr_t inaWriteConfigReg(inaModule_t module, inaRegContent_t regVal);
inaErr_t inaWriteCriticalLimit(inaModule_t module, inaChannel_t channel, inaRegContent_t regVal);
inaErr_t inaWriteWarningLimit(inaModule_t module, inaChannel_t channel, inaRegContent_t regVal);
inaErr_t inaWriteShuntSumLimit(inaModule_t module, inaRegContent_t regVal);
inaErr_t inaWriteEnableMask(inaModule_t module, inaRegContent_t regVal);
inaErr_t inaWriteUpperPowerLimit(inaModule_t module, inaRegContent_t regVal);
inaErr_t inaWriteLowerPowerLimit(inaModule_t module, inaRegContent_t regVal);

/*   Layer-2 API's --Register-Operation--   */
/*   Setting Values in Configuration Register  */
inaErr_t inaModuleReset(inaModule_t module);
inaErr_t inaEnableChannel(inaModule_t module, inaChannel_t channel);
inaErr_t inaSetAveragingSampleNum(inaModule_t module, inaAveragingMode_t averagingMode);
inaErr_t inaSetBusVolatageConvTime(inaModule_t module, inaVoltageConvTime_t voltConvTime);
inaErr_t inaSetShuntVolatageConvTime(inaModule_t module, inaVoltageConvTime_t voltConvTime);
inaErr_t inaSetOperatingMode(inaModule_t module, inaOperatingMode_t OperatingMode);

/*   Setting Values in Mask/Enable Register   */
inaErr_t inaSetSumChannelControl(inaModule_t module, inaChannel_t channel);
inaErr_t inaSetCriticalAlertEnable(inaModule_t module);
inaErr_t inaSetWarningAlertEnable(inaModule_t module);


/*   Getting Values in Mask/Enable Register   */
inaRegFlag_t inaGetCriticalAlertFlag(inaModule_t module);
inaRegFlag_t inaGetSummationAlertFlag(inaModule_t module);
inaRegFlag_t inaGetWarningAlertFlag(inaModule_t module);
inaRegFlag_t inaGetPowerValidAlertFlag(inaModule_t module);
inaRegFlag_t inaGetTimingControlAlertFlag(inaModule_t module);
inaRegFlag_t inaGetConversionAlertFlag(inaModule_t module);

/*   Getting Values from other Registers   */
inaChannelData_t inaReadChannelData(inaModule_t module, inaChannel_t channel);
inaChannelAlertLimit_t inaReadChannelAlertLimit(inaModule_t module, inaChannel_t channel);

/*   Layer-3 API's --Sensor-Operation--   */
/* Calculate Current Value */
inaCurrent_t inaCurrentCalculation(inaModule_t module, inaChannel_t channel);

#endif /* @API */