/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief  Generic F103C4 and F103C6 board header.
 */

#ifndef _BOARD_GENERIC_STM32F103_C4_C6_H_
#define _BOARD_GENERIC_STM32F103_C4_C6_H_

#define CYCLES_PER_MICROSECOND	  (F_CPU / 1000000U)
#define SYSTICK_RELOAD_VAL        (F_CPU / 1000) - 1 // takes a cycle to reload

// Total number of GPIO pins that are broken out to headers and intended for use
#define BOARD_NR_GPIO_PINS        37

// Number of pins capable of PWM output
#define BOARD_NR_PWM_PINS         12

// Number of pins capable of ADC conversion
#define BOARD_NR_ADC_PINS         9

// Number of USARTs/UARTs whose pins are broken out to headers
#define BOARD_NR_USARTS           2

// USART 1 pin numbers
#define BOARD_USART1_TX_PIN       PA9
#define BOARD_USART1_RX_PIN       PA10

// USART 1 alternate pin numbers
#define BOARD_USART1_ALT_TX_PIN   PB6
#define BOARD_USART1_ALR_RX_PIN   PB7

// USART 2 pin numbers
#define BOARD_USART2_TX_PIN       PA2
#define BOARD_USART2_RX_PIN       PA3

// Number of SPI ports broken out to headers
#define BOARD_NR_SPI              1

// SPI 1 pin numbers
#define BOARD_SPI1_NSS_PIN        PA4
#define BOARD_SPI1_MOSI_PIN       PA7
#define BOARD_SPI1_MISO_PIN       PA6
#define BOARD_SPI1_SCK_PIN        PA5

// SPI 1 alternate pin numbers
#define BOARD_SPI1_ALT_NSS_PIN    PA15
#define BOARD_SPI1_ALT_MOSI_PIN   PB5
#define BOARD_SPI1_ALT_MISO_PIN   PB4
#define BOARD_SPI1_ALT_SCK_PIN    PB3

// Debug port pins (JTAG, SWD)
#define BOARD_JTMS_SWDIO_PIN      PA13
#define BOARD_JTCK_SWCLK_PIN      PA14
#define BOARD_JTDI_PIN            PA15
#define BOARD_JTDO_PIN            PB3
#define BOARD_NJTRST_PIN          PB4

// This needs to match with the PIN_MAP array in board.cpp
enum {
  PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,
  PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
  PC13, PC14, PC15,
  PD0, PD1
};

#endif
