cmake_minimum_required(VERSION 3.11.0)

idf_component_register(
        SRCS
        src/u8g2_esp32_hal.c
        INCLUDE_DIRS include
        REQUIRES driver freertos u8g2)
