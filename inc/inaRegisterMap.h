#ifndef _REGISTER_MAP_H_
#define _REGISTER_MAP_H_

/*   Register Table   */
#define ina_ConfigRegister               (uint8_t)(0x00)
#define ina_ChaOneShuntVoltage           (uint8_t)(0x01)
#define ina_ChaOneBusVoltage             (uint8_t)(0x02)
#define ina_ChaTwoShuntVoltage           (uint8_t)(0x03)
#define ina_ChaTwoBusVoltage             (uint8_t)(0x04)
#define ina_ChaThreeShuntVoltage         (uint8_t)(0x05)
#define ina_ChaThreeBusVoltage           (uint8_t)(0x06)
#define ina_ChaOneCriticalAlertLimit     (uint8_t)(0x07)
#define ina_ChaOneWarningAlertLimit      (uint8_t)(0x08)
#define ina_ChaTwoCriticalAlertLimit     (uint8_t)(0x09)
#define ina_ChaTwoWarningAlertLimit      (uint8_t)(0x0A)
#define ina_ChaThreeCriticalAlertLimit   (uint8_t)(0x0B)
#define ina_ChaThreeWarningAlertLimit    (uint8_t)(0x0C)
#define ina_ShuntVoltageSum              (uint8_t)(0x0D)
#define ina_ShuntVoltageSumLimit         (uint8_t)(0x0E)
#define ina_Mask_Enable                  (uint8_t)(0x0F)
#define ina_PowerValidUpperLimit         (uint8_t)(0x10)
#define ina_PowerValidLowerLimit         (uint8_t)(0x11)
#define ina_ManufacturerID               (uint8_t)(0xFE)
#define ina_DieID                        (uint8_t)(0xFF)

/*   Essential Bit(s) Mask   */
#define ina_SignMask                     (uint16_t)(0x8000)
#define ina_DataMask                     (uint16_t)(0x7FF8)
#define ina_AlertRegDataMask             (uint16_t)(0xFFF8)
#define ina_ShuntVoltageDataMask         (uint16_t)(0xFFFE)
#define ina_IDDataMask                   (uint16_t)(0xFFFF)

/*   Configuration Register Bit(s) Mask   */
#define ina_ConfigResetMask              (uint16_t)(0x8000)
#define ina_ConfigChaOneMask             (uint16_t)(0x4000)
#define ina_ConfigChaTwoMask             (uint16_t)(0x2000)
#define ina_ConfigChaThreeMask           (uint16_t)(0x1000)
#define ina_ConfigAvgMask                (uint16_t)(0x0E00)
#define ina_ConfigVBusConvTimeMask       (uint16_t)(0x01C0)
#define ina_ConfigVShuntConvTimeMask     (uint16_t)(0x0038)
#define ina_ConfigModesMask              (uint16_t)(0x0003)

/*   Channel One Shunt Voltage Register Bit(s) Mask   */
#define ina_ChaOneShuntVoltageSignMask   inaSignMask
#define ina_ChaOneShuntVoltageDataMask   inaDataMask

/*   Channel One Bus Voltage Register Bit(s) Mask   */
#define ina_ChaOneBusVoltageSignMask     inaSignMask
#define ina_ChaOneBusVoltageDataMask     inaDataMask

/*   Channel Two Shunt Voltage Register Bit(s) Mask   */
#define ina_ChaTwoShuntVoltageSignMask   inaSignMask
#define ina_ChaTwoShuntVoltageDataMask   inaDataMask

/*   Channel Two Bus Voltage Register Bit(s) Mask   */
#define ina_ChaTwoBusVoltageSignMask     inaSignMask
#define ina_ChaTwoBusVoltageDataMask     inaDataMask

/*   Channel Three Shunt Voltage Register Bit(s) Mask   */
#define ina_ChaThreeShuntVoltageSignMask inaSignMask
#define ina_ChaThreeShuntVoltageDataMask inaDataMask

/*   Channel Three Bus Voltage Register Bit(s) Mask   */
#define ina_ChaThreeBusVoltageSignMask   inaSignMask
#define ina_ChaThreeBusVoltageDataMask   inaDataMask

/*   Channel One Critical Alert Register Bit(s) Mask   */
#define ina_ChaOneCriticalAlertDataMask   inaAlertRegDataMask

/*   Channel One Warning Alert Register Bit(s) Mask   */
#define ina_ChaOneWarningAlertDataMask    inaAlertRegDataMask

/*   Channel Two Critical Alert Register Bit(s) Mask   */
#define ina_ChaTwoCriticalAlertDataMask   inaAlertRegDataMask

/*   Channel Two Warning Alert Register Bit(s) Mask   */
#define ina_ChaTwoWarningAlertDataMask    inaAlertRegDataMask

/*   Channel Three Critical Alert Register Bit(s) Mask   */
#define ina_ChaThreeCriticalAlertDataMask inaAlertRegDataMask

/*   Channel Three Warning Alert Register Bit(s) Mask   */
#define ina_ChaThreeWarningAlertDataMask  inaAlertRegDataMask

/*   Shunt Voltage Sum Register Bit(s) Mask   */
#define ina_MaskShuntVoltageSumSignMask   inaSignMask
#define ina_MaskShuntVoltageSumDataMask   inaShuntVoltageDataMask

/*   Shunt Voltage Sum Limit Register Bit(s) Mask   */
#define ina_MaskShuntVoltageSumSignMask   inaSignMask
#define ina_MaskShuntVoltageSumDataMask   inaShuntVoltageDataMask

/*   Power Valid Upper Limit Register Bit(s) Mask   */
#define ina_PowerValidUpperLimitSignMask  inaSignMask
#define ina_PowerValidUpperLimitDataMask  inaDataMask

/*   Power Valid Lower Limit Register Bit(s) Mask   */
#define ina_PowerValidLowerLimitSignMask  inaSignMask
#define ina_PowerValidLowerLimitDataMask  inaDataMask

/*   Mask/Enable Register   */
#define ina_EnMaskSummationControl         (uint16_t)(0x7000)
#define ina_EnMaskSummationControlChaOne   (uint16_t)(0x4000)
#define ina_EnMaskSummationControlChaTwo   (uint16_t)(0x2000)
#define ina_EnMaskSummationControlChaThree (uint16_t)(0x1000)
#define ina_EnMaskWarningLatchEn           (uint16_t)(0x0800)
#define ina_EnMaskCriticalLatchEn          (uint16_t)(0x0400)
#define ina_EnMaskCriticalFlag             (uint16_t)(0x0380)
#define ina_EnMaskCriticalFlagChaOne       (uint16_t)(0x0200)
#define ina_EnMaskCriticalFlagChaTwo       (uint16_t)(0x0100)
#define ina_EnMaskCriticalFlagChaThree     (uint16_t)(0x0080)
#define ina_EnMaskSummationAlertFlag       (uint16_t)(0x0040)
#define ina_EnMaskWarningFlag              (uint16_t)(0x0038)
#define ina_EnMaskWarningFlagChaOne        (uint16_t)(0x0020)
#define ina_EnMaskWarningFlagChaTwo        (uint16_t)(0x0010)
#define ina_EnMaskWarningFlagChaThree      (uint16_t)(0x0008)
#define ina_EnMaskPowerValidFlag           (uint16_t)(0x0002)
#define ina_EnMaskTimingControlAlertFlag   (uint16_t)(0x0001)
#define ina_EnMaskConvReadyFlag            (uint16_t)(0x0000)

/*   Config Register Shift Values  */
#define ina_ConfigAvgShiftMask                  (uint8_t)(9)
#define ina_ConfigBusVoltageShiftMask           (uint8_t)(6)
#define ina_ConfigShuntVoltageShiftMask         (uint8_t)(3)
#define ina_ConfigOpModeShiftMask               (uint8_t)(0)

/* Mask/Enable Register Shift Values */
#define ina_EnMaskSummationControlShiftMask     (uint8_t)(12)
#define ina_EnMaskCriticalFlagShiftMask         (uint8_t)(7)
#define ina_EnMaskSummationAlertShiftMask       (uint8_t)(6)
#define ina_EnMaskWarningFlagShiftMask          (uint8_t)(3)
#define ina_EnMaskPowerValidShiftMask           (uint8_t)(2)
#define ina_EnMaskTimingControlShiftMask        (uint8_t)(1)
#define ina_EnMaskConversionReadyShiftMask      (uint8_t)(0)

/*   Enumerations   */

/*   Config Register   */

/*   Averaging Modes - Configuration Register   */
typedef enum{
    avgModeSamples1     = 0b000,
    avgModeSamples4     = 0b001,
    avgModeSamples16    = 0b010,
    avgModeSamples64    = 0b011,
    avgModeSamples128   = 0b100,
    avgModeSamples256   = 0b101,
    avgModeSamples512   = 0b110,
    avgModeSamples1024  = 0b111
}inaAveragingMode_t;

/*   Bus-Voltage/Shunt-Voltage Conversion Time   */
typedef enum{
    ConvTime140us       = 0b000,
    ConvTime204us       = 0b001,
    ConvTime332us       = 0b010,
    ConvTime588us       = 0b011,
    ConvTime1100us      = 0b100,
    ConvTime2116us      = 0b101,
    ConvTime4156us      = 0b110,
    ConvTime8244us      = 0b111
}inaVoltageConvTime_t;

/*   Operation Modes   */
typedef enum{
    OpModePowerDown             = 0b000,
    OpModeSinShotShuntV         = 0b001,
    OpModeSinShotBusV           = 0b010,
    OpModeSinShotShunt_BusV     = 0b011,
    OpModePowerDown_2           = 0b100,
    OpModeContinuousShuntV      = 0b101,
    OpModeContinuousBusV        = 0b110,
    OpModeContinuousShunt_BusV  = 0b111
}inaOperatingMode_t;


#endif /* @REGISTER_MAP */