/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2012 LeafLabs, LLC.
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
 * @brief  Generic F103C8 and F103CB chip setup.
 *
 * This file controls how init() behaves on the STM32F1. Be very
 * careful when changing anything here. Many of these values depend
 * upon each other.
 */

#include "boards_private.h"
#include <libmaple/gpio.h>
#include <libmaple/timer.h>
#include <boards.h>

// Allow boards to provide a PLL multiplier. This is useful for e.g. STM32F100 value line MCUs, which use slower multipliers.
#ifndef BOARD_RCC_PLLMUL
#if !USE_HSI_CLOCK
#if F_CPU == 128000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_16
#warning "The frequency is higher than the recommended maximum. This may reduce the life of the MCU"
#elif F_CPU == 120000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_15
#warning "The frequency is higher than the recommended maximum. This may reduce the life of the MCU"
#elif F_CPU == 112000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_14
#warning "The frequency is higher than the recommended maximum. This may reduce the life of the MCU"
#elif F_CPU == 96000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_12
#warning "The frequency is higher than the recommended maximum. This may reduce the life of the MCU"
#elif F_CPU == 88000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_11
#warning "The frequency is higher than the recommended maximum. This may reduce the life of the MCU"
#elif F_CPU == 80000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_10
#warning "The frequency is higher than the recommended maximum. This may reduce the life of the MCU"
#elif F_CPU == 72000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_9
#elif F_CPU == 64000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_8
#elif F_CPU == 56000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_7
#elif F_CPU == 48000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_6
#elif F_CPU == 40000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_5
#elif F_CPU == 32000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_4
#elif F_CPU == 24000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_3
#elif F_CPU == 16000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_2
#endif
#else
#if F_CPU == 64000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_16
#elif F_CPU == 60000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_15
#elif F_CPU == 56000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_14
#elif F_CPU == 52000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_13
#elif F_CPU == 48000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_12
#elif F_CPU == 44000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_11
#elif F_CPU == 40000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_10
#elif F_CPU == 36000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_9
#elif F_CPU == 32000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_8
#elif F_CPU == 28000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_7
#elif F_CPU == 24000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_6
#elif F_CPU == 20000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_5
#elif F_CPU == 16000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_4
#elif F_CPU == 12000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_3
#elif F_CPU == 8000000
#define BOARD_RCC_PLLMUL RCC_PLLMUL_2
#endif
#endif
#endif

namespace wirish
{
  namespace priv
  {
    static stm32f1_rcc_pll_data pll_data = {BOARD_RCC_PLLMUL};
#if !USE_HSI_CLOCK
    __weak rcc_pll_cfg w_board_pll_cfg = {RCC_PLLSRC_HSE, &pll_data};
#else
    __weak rcc_pll_cfg w_board_pll_cfg = {RCC_PLLSRC_HSI_DIV_2, &pll_data};
#endif
    __weak adc_prescaler w_adc_pre = ADC_PRE_PCLK2_DIV_6;
    __weak adc_smp_rate w_adc_smp = ADC_SMPR_55_5;

    __weak void board_reset_pll(void)
    {
      // TODO
    }

    __weak void board_setup_clock_prescalers(void)
    {
      rcc_set_prescaler(RCC_PRESCALER_AHB, RCC_AHB_SYSCLK_DIV_1);
      rcc_set_prescaler(RCC_PRESCALER_APB1, RCC_APB1_HCLK_DIV_2);
      rcc_set_prescaler(RCC_PRESCALER_APB2, RCC_APB2_HCLK_DIV_1);
      rcc_clk_disable(RCC_USB);
#if F_CPU == 72000000
      rcc_set_prescaler(RCC_PRESCALER_USB, RCC_USB_SYSCLK_DIV_1_5);
#elif F_CPU == 48000000
      rcc_set_prescaler(RCC_PRESCALER_USB, RCC_USB_SYSCLK_DIV_1);
#endif
    }

    __weak void board_setup_gpio(void)
    {
      gpio_init_all();
    }

    __weak void board_setup_usb(void)
    {
      // TODO
    }

    __weak void series_init(void)
    {
      // Initialize AFIO here, too, so peripheral remaps and external
      // interrupts work out of the box.
      afio_init();
    }
  }
}
