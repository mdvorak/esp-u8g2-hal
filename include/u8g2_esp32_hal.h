#ifndef U8G2_ESP32_HAL_H
#define U8G2_ESP32_HAL_H
/*
 * u8g2_esp32_hal.h
 *
 *  Created on: Feb 12, 2017
 *      Author: kolban
 */

#ifndef U8G2_ESP32_HAL_H_
#define U8G2_ESP32_HAL_H_
#include "u8g2.h"

#include "driver/gpio.h"
#include "driver/i2c.h"
#include "driver/spi_master.h"

#ifdef __cplusplus
extern "C" {
#endif

#define U8G2_ESP32_HAL_UNDEFINED (-1)

#define I2C_MASTER_NUM I2C_NUM_1     //  I2C port number for master dev
#define I2C_MASTER_TX_BUF_DISABLE 0  //  I2C master do not need buffer
#define I2C_MASTER_RX_BUF_DISABLE 0  //  I2C master do not need buffer
#define I2C_MASTER_FREQ_HZ 50000     //  I2C master clock frequency

typedef struct {
  gpio_num_t clk;
  gpio_num_t mosi;
  gpio_num_t sda;  // data for I²C
  gpio_num_t scl;  // clock for I²C
  gpio_num_t cs;
  gpio_num_t reset;
  gpio_num_t dc;
  i2c_port_t i2c_num;
  uint32_t i2c_clk_speed;
} u8g2_esp32_hal_t;

#define U8G2_ESP32_HAL_DEFAULT  \
  {                             \
    U8G2_ESP32_HAL_UNDEFINED,   \
    U8G2_ESP32_HAL_UNDEFINED, \
    U8G2_ESP32_HAL_UNDEFINED, \
    U8G2_ESP32_HAL_UNDEFINED, \
    U8G2_ESP32_HAL_UNDEFINED, \
    U8G2_ESP32_HAL_UNDEFINED, \
    U8G2_ESP32_HAL_UNDEFINED, \
    I2C_MASTER_NUM,           \
    I2C_MASTER_FREQ_HZ        \
  }

void u8g2_esp32_hal_init(u8g2_esp32_hal_t u8g2_esp32_hal_param);
uint8_t u8g2_esp32_spi_byte_cb(u8x8_t* u8x8,
                               uint8_t msg,
                               uint8_t arg_int,
                               void* arg_ptr);
uint8_t u8g2_esp32_i2c_byte_cb(u8x8_t* u8x8,
                               uint8_t msg,
                               uint8_t arg_int,
                               void* arg_ptr);
uint8_t u8g2_esp32_gpio_and_delay_cb(u8x8_t* u8x8,
                                     uint8_t msg,
                                     uint8_t arg_int,
                                     void* arg_ptr);

#ifdef __cplusplus
}
#endif

#endif /* U8G2_ESP32_HAL_H_ */

#endif