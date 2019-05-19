/*******************************************************************************
 * @author: Utkarsh Bhatt
 * @Date: 14th May, 2019
 ******************************************************************************/

#include "inaAPI.h"
/*   Layer-1 API's --HAL--   */
/*   Reading Registers   */
inaRegContent_t inaReadConfigReg(inaModule_t module)
{
    inaRegContent_t received;
    inaI2CReceive(module, ina_ConfigRegister, &received, 1);
    return received;
}

inaRegContent_t inaReadBusVoltageRaw(inaModule_t module, inaChannel_t channel)
{
    inaRegContent_t received;
    inaRegAddr_t channelDefinedAddress;
    if(channel == ChannelOne)
        channelDefinedAddress = ina_ChaOneBusVoltage;
    if(channel == ChannelTwo)
        channelDefinedAddress = ina_ChaTwoBusVoltage;
    if(channel == ChannelThree)
        channelDefinedAddress = ina_ChaThreeBusVoltage;
    inaI2CReceive(module, channelDefinedAddress, &received, 1);
    return received;
}

inaRegContent_t inaReadShuntVoltageRaw(inaModule_t module, inaChannel_t channel)
{
    inaRegContent_t received;
    inaRegAddr_t channelDefinedAddress;
    if(channel == ChannelOne)
        channelDefinedAddress = ina_ChaOneShuntVoltage;
    if(channel == ChannelTwo)
        channelDefinedAddress = ina_ChaTwoShuntVoltage;
    if(channel == ChannelThree)
        channelDefinedAddress = ina_ChaThreeShuntVoltage;
    inaI2CReceive(module, channelDefinedAddress, &received, 1);
    return received;
}

inaRegContent_t inaReadCritialLimit(inaModule_t module, inaChannel_t channel)
{
    inaRegContent_t received;
    inaRegAddr_t channelDefinedAddress;
    if(channel == ChannelOne)
        channelDefinedAddress = ina_ChaOneCriticalAlertLimit;
    if(channel == ChannelTwo)
        channelDefinedAddress = ina_ChaTwoCriticalAlertLimit;
    if(channel == ChannelThree)
        channelDefinedAddress = ina_ChaThreeCriticalAlertLimit;
    inaI2CReceive(module, channelDefinedAddress, &received, 1);
    return received;
}

inaRegContent_t inaReadWarningLimit(inaModule_t module, inaChannel_t channel)
{
    inaRegContent_t received;
    inaRegAddr_t channelDefinedAddress;
    if(channel == ChannelOne)
        channelDefinedAddress = ina_ChaOneWarningAlertLimit;
    if(channel == ChannelTwo)
        channelDefinedAddress = ina_ChaTwoWarningAlertLimit;
    if(channel == ChannelThree)
        channelDefinedAddress = ina_ChaThreeWarningAlertLimit;
    inaI2CReceive(module, channelDefinedAddress, &received, 1);
    return received;
}

inaRegContent_t inaReadShuntSum(inaModule_t module)
{
    inaRegContent_t received;
    inaI2CReceive(module, ina_ShuntVoltageSum, &received, 1);
    return received;
}

inaRegContent_t inaReadShuntSumLimit(inaModule_t module)
{
    inaRegContent_t received;
    inaI2CReceive(module, ina_ShuntVoltageSumLimit, &received, 1);
    return received;
}

inaRegContent_t inaReadEnableMask(inaModule_t module)
{
    inaRegContent_t received;
    inaI2CReceive(module, ina_Mask_Enable, &received, 1);
    return received;
}

inaRegContent_t inaReadUpperPowerLimit(inaModule_t module)
{
    inaRegContent_t received;
    inaI2CReceive(module, ina_PowerValidUpperLimit, &received, 1);
    return received;
}

inaRegContent_t inaReadLowerPowerLimit(inaModule_t module)
{
    inaRegContent_t received;
    inaI2CReceive(module, ina_PowerValidLowerLimit, &received, 1);
    return received;
}

inaRegContent_t inaReadManufacturerID(inaModule_t module)
{
    inaRegContent_t received;
    inaI2CReceive(module, ina_ManufacturerID, &received, 1);
    return received;
}

inaRegContent_t inaReadDieID(inaModule_t module)
{
    inaRegContent_t received;
    inaI2CReceive(module, ina_DieID, &received, 1);
    return received;
}

/*   Writing Registers   */
inaErr_t inaWriteConfigReg(inaModule_t module, inaRegContent_t regVal)
{
    inaErr_t err;
    err = inaI2CSend(module, ina_ConfigRegister, &regVal, 1);
    return  err;
}

inaErr_t inaWriteCriticalLimit(inaModule_t module, inaChannel_t channel, inaRegContent_t regVal)
{
    inaErr_t err;
    inaRegAddr_t channelDefinedAddress;
    if(channel == ChannelOne)
        channelDefinedAddress = ina_ChaOneCriticalAlertLimit;
    if(channel == ChannelTwo)
        channelDefinedAddress = ina_ChaTwoCriticalAlertLimit;
    if(channel == ChannelThree)
        channelDefinedAddress = ina_ChaThreeCriticalAlertLimit;
    err = inaI2CSend(module, channelDefinedAddress, &regVal, 1);
    return  err;
}

inaErr_t inaWriteWarningLimit(inaModule_t module, inaChannel_t channel, inaRegContent_t regVal)
{
    inaErr_t err;
    inaRegAddr_t channelDefinedAddress;
    if(channel == ChannelOne)
        channelDefinedAddress = ina_ChaOneWarningAlertLimit;
    if(channel == ChannelTwo)
        channelDefinedAddress = ina_ChaTwoWarningAlertLimit;
    if(channel == ChannelThree)
        channelDefinedAddress = ina_ChaThreeWarningAlertLimit;
    err = inaI2CSend(module, channelDefinedAddress, &regVal, 1);
    return  err;
}

inaErr_t inaWriteShuntSumLimit(inaModule_t module, inaRegContent_t regVal)
{
    inaErr_t err;
    err = inaI2CSend(module, ina_ShuntVoltageSumLimit, &regVal, 1);
    return  err;
}

inaErr_t inaWriteEnableMask(inaModule_t module, inaRegContent_t regVal)
{
    inaErr_t err;
    err = inaI2CSend(module, ina_Mask_Enable, &regVal, 1);
    return  err;  
}

inaErr_t inaWriteUpperPowerLimit(inaModule_t module, inaRegContent_t regVal)
{
    inaErr_t err;
    err = inaI2CSend(module, ina_PowerValidUpperLimit, &regVal, 1);
    return  err;
}

inaErr_t inaWriteLowerPowerLimit(inaModule_t module, inaRegContent_t regVal)
{
    inaErr_t err;
    err = inaI2CSend(module, ina_PowerValidLowerLimit, &regVal, 1);
    return  err; 
}

/*   Layer-2 API's --Register-Operation--   */
/*   Setting Values in Configuration Register  */
inaErr_t inaModuleReset(inaModule_t module){
    inaErr_t err;
    inaRegContent_t regData = inaReadConfigReg(module);
    regData |= ina_ConfigResetMask;
    err = inaWriteConfigReg(module, regData);
    return err;
}

inaErr_t inaEnableChannel(inaModule_t module, inaChannel_t channel){
    inaErr_t err;
    inaRegContent_t channelDefinedMask = inaReadConfigReg(module);
    if(channel == ChannelOne)
        channelDefinedMask |= ina_ConfigChaOneMask;
    if(channel == ChannelTwo)
        channelDefinedMask |= ina_ConfigChaTwoMask;
    if(channel == ChannelThree)
        channelDefinedMask |= ina_ConfigChaThreeMask;
    err = inaWriteConfigReg(module, channelDefinedMask);
    return err;
}

inaErr_t inaSetAveragingSampleNum(inaModule_t module, inaAveragingMode_t averagingMode){
    inaErr_t err;
    inaRegContent_t regData = inaReadConfigReg(module);
    regData &= ~ina_ConfigAvgMask;                                  //Setting just concerned bits to 0's.
    regData |= (averagingMode << ina_ConfigAvgShiftMask);           //Setting just concerned bits acc to the passed parameter.
    err = inaWriteConfigReg(module, regData);
    return err;
}

inaErr_t inaSetBusVolatageConvTime(inaModule_t module, inaVoltageConvTime_t voltConvTime)
{
    inaErr_t err;
    inaRegContent_t regData = inaReadConfigReg(module);
    regData &= ~ina_ConfigVBusConvTimeMask;                         //Setting just concerned bits to 0's.
    regData |= (voltConvTime << ina_ConfigBusVoltageShiftMask);     //Setting just concerned bits acc to the passed parameter.
    err = inaWriteConfigReg(module, regData);
    return err;
}

inaErr_t inaSetShuntVolatageConvTime(inaModule_t module, inaVoltageConvTime_t voltConvTime)
{
    inaErr_t err;
    inaRegContent_t regData = inaReadConfigReg(module);
    regData &= ~ina_ConfigVShuntConvTimeMask;                       //Setting just concerned bits to 0's.
    regData |= (voltConvTime << ina_ConfigShuntVoltageShiftMask);   //Setting just concerned bits acc to the passed parameter.
    err = inaWriteConfigReg(module, regData);
    return err;
}

inaErr_t inaSetOperatingMode(inaModule_t module, inaOperatingMode_t OperatingMode)
{
    inaErr_t err;
    inaRegContent_t regData = inaReadConfigReg(module);
    regData &= ~ina_ConfigModesMask;                                //Setting just concerned bits to 0's.
    regData |= (OperatingMode << ina_ConfigOpModeShiftMask);        //Setting just concerned bits acc to the passed parameter.
    err = inaWriteConfigReg(module, regData);
    return err;
}

/*   Setting Values in Mask/Enable Register   */
inaErr_t inaSetSumChannelControl(inaModule_t module, inaChannel_t channel)
{
    inaErr_t err;
    inaRegContent_t regData = inaReadEnableMask(module);
    regData &= ~ina_EnMaskSummationControl;                                   //Setting just concerned bits to 0's.
    regData |= (0b1 << (ina_EnMaskSummationControlShiftMask + (3-channel)));  //Setting just concerned bits acc to the passed parameter.
    err = inaWriteEnableMask(module, regData);
    return err;

}

inaErr_t inaSetCriticalAlertEnable(inaModule_t module)
{
    inaErr_t err;
    inaRegContent_t regData = inaReadEnableMask(module);
    regData &= ~ina_EnMaskCriticalLatchEn;                           //Setting just concerned bits to 0's.
    regData |= ina_EnMaskCriticalLatchEn;                            //Setting just concerned bits acc to the passed parameter.
    err = inaWriteEnableMask(module, regData);
    return err;
}

inaErr_t inaSetWarningAlertEnable(inaModule_t module)
{
    inaErr_t err;
    inaRegContent_t regData = inaReadEnableMask(module);
    regData &= ~ina_EnMaskWarningLatchEn;
    regData |= ina_EnMaskWarningLatchEn;
    err = inaWriteEnableMask(module, regData);
    return err;
}

/*   Getting Values in Mask/Enable Register   */
inaRegFlag_t inaGetCriticalAlertFlag(inaModule_t module)
{
    inaErr_t err;
    inaRegContent_t regData;
    regData = inaReadEnableMask(module);
    regData &= ina_EnMaskCriticalFlag;
    regData = regData >> ina_EnMaskCriticalFlagShiftMask; //Since Channel3 is the Starting location of the Flagwidth.
    return regData;
}

inaRegFlag_t inaGetSummationAlertFlag(inaModule_t module)
{
    inaErr_t err;
    inaRegContent_t regData;
    regData = inaReadEnableMask(module);
    regData &= ina_EnMaskSummationAlertFlag;
    regData = regData >> ina_EnMaskSummationAlertShiftMask;
    return regData;
}

inaRegFlag_t inaGetWarningAlertFlag(inaModule_t module)
{
    inaErr_t err;
    inaRegContent_t regData;
    regData = inaReadEnableMask(module);
    regData &= ina_EnMaskWarningFlag;
    regData = regData >> ina_EnMaskWarningFlagShiftMask;
    return regData;
}

inaRegFlag_t inaGetPowerValidAlertFlag(inaModule_t module)
{
    inaErr_t err;
    inaRegContent_t regData;
    regData = inaReadEnableMask(module);
    regData &= ina_EnMaskPowerValidFlag;
    regData = regData >> ina_EnMaskPowerValidShiftMask;
    return regData;
}

inaRegFlag_t inaGetTimingControlAlertFlag(inaModule_t module)
{
    inaErr_t err;
    inaRegContent_t regData;
    regData = inaReadEnableMask(module);
    regData &= ina_EnMaskTimingControlAlertFlag;
    regData = regData >> ina_EnMaskTimingControlShiftMask;
    return regData;
}

inaRegFlag_t inaGetConversionAlertFlag(inaModule_t module)
{
    inaErr_t err;
    inaRegContent_t regData;
    regData = inaReadEnableMask(module);
    regData &= ina_EnMaskConvReadyFlag;
    regData = regData >> ina_EnMaskConversionReadyShiftMask;
    return regData;
}

/*   Getting Values from other Registers   */
inaChannelData_t inaReadChannelDataRaw(inaModule_t module, inaChannel_t channel)
{
    inaChannelData_t ChannelData;
    ChannelData.BusVoltage = inaReadBusVoltageRaw(module, channel);
    ChannelData.ShuntVoltage = inaReadShuntVoltageRaw(module, channel);
    return ChannelData;
}

inaChannelAlertLimit_t inaReadChannelAlertLimit(inaModule_t module, inaChannel_t channel)
{
    inaChannelAlertLimit_t AlertData;
    AlertData.CriticalAlertLimit = inaReadCritialLimit(module, channel);
    AlertData.WarningAlertLimit = inaReadWarningLimit(module, channel);
    return AlertData;
}

/*   Layer-3 API's --Sensor-Operation--   */

/* Calculate Current Value */
inaCurrent_t inaCurrentCalculation(inaModule_t module, inaChannel_t channel)
{
    inaVoltage_t voltsRaw;
    voltsRaw = inaReadShuntVoltageRaw(module, channel);
    voltsRaw *= 0.008;
    return voltsRaw/module.rShunt;      //Voltage to current.
}