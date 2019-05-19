#ifndef _MODULE_OBJECT_H_
#define _MODULE_OBJECT_H_

#include "stdint.h"

typedef enum{
    Failure = -1,                       //For Failed method returns.
    Success = !Failure,                 //For Successful method returns.
    ChannelOneCriticalAlert,            //For Channel One Critical Alert.
    ChannelTwoCriticalAlert,            //For Channel Two Critical Alert.
    ChannelThreeCriticalAlert,          //For Channel Three Critical Alert.
    ChannelOneWarningAlert,             //For Channel One Warning Alert.
    ChannelTwoWarningAlert,             //For Channel Two Warning Alert.
    ChannelThreeWarningAlert,           //For Channel Three Warning Alert.
    PowerValidAlert,                    //For Invalid Power Alert
    TimingControlAlert,                 //For Timing COntrol ALert.
    ConversionReady                     //For Conversion Ready Alert.
} inaErr_t;

typedef enum{
    ChannelOne = 1,
    ChannelTwo = 2,
    ChannelThree = 3
} inaChannel_t;

typedef uint8_t  inaSCL_t;
typedef uint8_t  inaSDA_t;
typedef uint8_t  inaI2CSpeed_t;
typedef uint8_t  inaModuleAddr_t;
typedef uint8_t  inaRegAddr_t;
typedef uint16_t inaRegContent_t;
typedef uint8_t  inaRegFlag_t;
typedef float    inaVoltage_t;
typedef uint32_t inaShuntResistance_t;
typedef uint32_t inaCurrent_t;

typedef struct{
    inaRegContent_t ShuntVoltage;
    inaRegContent_t BusVoltage;
} inaChannelData_t;

typedef struct{
    inaRegContent_t CriticalAlertLimit;
    inaRegContent_t WarningAlertLimit;
} inaChannelAlertLimit_t;

typedef struct{
    inaSCL_t scl;
    inaSDA_t sda;
    inaI2CSpeed_t speed;
    inaRegAddr_t addr;
    inaShuntResistance_t rShunt;
}inaModule_t;

#endif /* @MODULE_OBJECT */