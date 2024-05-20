// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2020 Scott Shawcroft for Adafruit Industries
//
// SPDX-License-Identifier: MIT

#include "shared-bindings/board/__init__.h"
#include "shared-module/displayio/__init__.h"

static const mp_rom_map_elem_t board_module_globals_table[] = {
    CIRCUITPYTHON_BOARD_DICT_STANDARD_ITEMS

    // Not broken out - Button
    { MP_ROM_QSTR(MP_QSTR_IO0), MP_ROM_PTR(&pin_GPIO0) },  // RTC_GPIO0,GPIO0

    // S2 Pico Board top, left, top-bottom
    { MP_ROM_QSTR(MP_QSTR_IO1), MP_ROM_PTR(&pin_GPIO1) },  // RTC_GPIO1,GPIO1,TOUCH1,ADC1_CH0
    { MP_ROM_QSTR(MP_QSTR_IO2), MP_ROM_PTR(&pin_GPIO2) },  // RTC_GPIO2,GPIO2,TOUCH2,ADC1_CH1
    { MP_ROM_QSTR(MP_QSTR_IO3), MP_ROM_PTR(&pin_GPIO3) },  // RTC_GPIO3,GPIO3,TOUCH3,ADC1_CH2
    { MP_ROM_QSTR(MP_QSTR_IO4), MP_ROM_PTR(&pin_GPIO4) },  // RTC_GPIO4,GPIO4,TOUCH4,ADC1_CH3
    { MP_ROM_QSTR(MP_QSTR_IO5), MP_ROM_PTR(&pin_GPIO5) },  // RTC_GPIO5,GPIO5,TOUCH5,ADC1_CH4
    { MP_ROM_QSTR(MP_QSTR_IO6), MP_ROM_PTR(&pin_GPIO6) },  // RTC_GPIO6,GPIO6,TOUCH6,ADC1_CH5
    { MP_ROM_QSTR(MP_QSTR_IO7), MP_ROM_PTR(&pin_GPIO7) },  // RTC_GPIO7,GPIO7,TOUCH7,ADC1_CH6

    // JST SH Connector
    { MP_ROM_QSTR(MP_QSTR_IO8), MP_ROM_PTR(&pin_GPIO8) },  // RTC_GPIO8,GPIO8,TOUCH8,ADC1_CH7
    { MP_ROM_QSTR(MP_QSTR_IO9), MP_ROM_PTR(&pin_GPIO9) },  // RTC_GPIO8,GPIO8,TOUCH8,ADC1_CH7

    // Not broken out - LED
    { MP_ROM_QSTR(MP_QSTR_IO10), MP_ROM_PTR(&pin_GPIO10) },// RTC_GPIO10,GPIO10,TOUCH10,ADC1_CH9,FSPICS0,FSPIIO4

    // S2 Pico Board top, right, bottom-top
    { MP_ROM_QSTR(MP_QSTR_IO11), MP_ROM_PTR(&pin_GPIO11) },// RTC_GPIO11,GPIO11,TOUCH11,ADC2_CH0,FSPID,FSPIIO5
    { MP_ROM_QSTR(MP_QSTR_IO12), MP_ROM_PTR(&pin_GPIO12) },// RTC_GPIO12,GPIO12,TOUCH12,ADC2_CH1,FSPICLK,FSPIIO6
    { MP_ROM_QSTR(MP_QSTR_IO13), MP_ROM_PTR(&pin_GPIO13) },// RTC_GPIO13,GPIO13,TOUCH13,ADC2_CH2,FSPIQ,FSPIIO7
    { MP_ROM_QSTR(MP_QSTR_IO14), MP_ROM_PTR(&pin_GPIO14) },// RTC_GPIO14,GPIO14,TOUCH14,ADC2_CH3,FSPIWP,FSPIDQS
    { MP_ROM_QSTR(MP_QSTR_IO15), MP_ROM_PTR(&pin_GPIO15) },// XTAL_32K_P: RTC_GPIO15,GPIO15,U0RTS,ADC2_CH4,XTAL_32K_P
    { MP_ROM_QSTR(MP_QSTR_IO16), MP_ROM_PTR(&pin_GPIO16) },// XTAL_32K_N: RTC_GPIO16,GPIO16,U0CTS,ADC2_CH5,XTAL_32K_N
    { MP_ROM_QSTR(MP_QSTR_IO17), MP_ROM_PTR(&pin_GPIO17) },// DAC_1: RTC_GPIO17,GPIO17,U1TXD,ADC2_CH6,DAC_1

    // Not broken out - SSD1306 reset
    { MP_ROM_QSTR(MP_QSTR_IO18), MP_ROM_PTR(&pin_GPIO18) },// DAC_2: RTC_GPIO18,GPIO18,U1RXD,ADC2_CH7,DAC_2,CLK_OUT3

    { MP_ROM_QSTR(MP_QSTR_IO21), MP_ROM_PTR(&pin_GPIO21) },// RTC_GPIO21,GPIO21
    { MP_ROM_QSTR(MP_QSTR_IO33), MP_ROM_PTR(&pin_GPIO33) },// SPIIO4,GPIO33,FSPIHD
    { MP_ROM_QSTR(MP_QSTR_IO34), MP_ROM_PTR(&pin_GPIO34) },// SPIIO5,GPIO34,FSPICS0
    { MP_ROM_QSTR(MP_QSTR_IO35), MP_ROM_PTR(&pin_GPIO35) },// SPIIO6,GPIO35,FSPID
    { MP_ROM_QSTR(MP_QSTR_IO36), MP_ROM_PTR(&pin_GPIO36) },// SPIIO7,GPIO36,FSPICLK
    { MP_ROM_QSTR(MP_QSTR_IO37), MP_ROM_PTR(&pin_GPIO37) },// SPIDQS,GPIO37,FSPIQ
    { MP_ROM_QSTR(MP_QSTR_IO38), MP_ROM_PTR(&pin_GPIO38) },//        GPIO38,FSPIWP

    { MP_ROM_QSTR(MP_QSTR_BUTTON), MP_ROM_PTR(&pin_GPIO0) },
    { MP_ROM_QSTR(MP_QSTR_LED),  MP_ROM_PTR(&pin_GPIO10) },
    { MP_ROM_QSTR(MP_QSTR_SDA),  MP_ROM_PTR(&pin_GPIO8) },
    { MP_ROM_QSTR(MP_QSTR_SCL),  MP_ROM_PTR(&pin_GPIO9) },
    { MP_ROM_QSTR(MP_QSTR_LCD_RST), MP_ROM_PTR(&pin_GPIO18) },
    { MP_ROM_QSTR(MP_QSTR_SS),  MP_ROM_PTR(&pin_GPIO34) },  // Not labelled on booard, on schematic
    { MP_ROM_QSTR(MP_QSTR_MOSI),  MP_ROM_PTR(&pin_GPIO35) },// Not labelled on booard, on schematic
    { MP_ROM_QSTR(MP_QSTR_SCK),  MP_ROM_PTR(&pin_GPIO36) }, // Not labelled on booard, on schematic
    { MP_ROM_QSTR(MP_QSTR_MISO),  MP_ROM_PTR(&pin_GPIO37) },// Not labelled on booard, on schematic
    { MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj) },

    { MP_ROM_QSTR(MP_QSTR_DISPLAY), MP_ROM_PTR(&displays[0].display)}
};
MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);
