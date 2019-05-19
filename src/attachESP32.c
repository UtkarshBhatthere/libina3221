#ifndef _ATTACH_ESP_32_H_
#define _ATTACH_ESP_32_H_

#ifdef _ESP_32_


#include "esp_err.h"
#include "driver/i2c.h"
#include "freertos/portmacro.h"

#define ACK_CHECK_EN    0x01
#define ACK_CHECK_DIS   0x00
#define ACK_VAL         0x00
#define NACK_VAL        0x01
#define I2C_NUM         I2C_NUM_0


/*****************************************************************************
 * *************************** Instructions **********************************
 * @1: Since the device hosting the code will always be master we don't need *
 *     attach API's for Slave Config.                                        *
 * @2: Just include inaTypes. in your API library (.c/.c++) file and redefine*
 *     inaI2CSend() and inaI2CReceive().                                     *
 *****************************************************************************/

inaErr_t inaI2CSend(inaModule_t module, inaRegAddr_t regAddr, inaRegContent_t* data, uint16_t datLen)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (module.addr << 1), ACK_CHECK_EN);
    i2c_master_write_byte(cmd, regAddr, ACK_CHECK_EN);
    i2c_master_write(cmd, data, datLen, ACK_CHECK_EN);
    i2c_master_stop(cmd);
    esp_err_t err = i2c_master_cmd_begin(I2C_NUM, cmd, 100/portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);

}
inaErr_t inaI2CReceive(inaModule_t module, inaRegAddr_t regAddr, inaRegContent_t* data, uint16_t datLen)
{
    if (datLen == 0) {
        return 0;
    }
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (module.addr << 1), ACK_CHECK_EN);
    i2c_master_write_byte(cmd, regAddr, ACK_CHECK_EN);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, ( module.addr << 1 ) | I2C_MASTER_READ, ACK_CHECK_EN);
    if (datLen > 1) {
        i2c_master_read(cmd, data, datLen - 1, ACK_VAL);
    }
    i2c_master_read_byte(cmd, data + datLen - 1, NACK_VAL);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(I2C_NUM, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}

#endif /* @_ESP_32_ */

#endif /* @ATTACH_ESP_32 */