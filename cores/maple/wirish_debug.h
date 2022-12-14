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
 * @file core/maple/wirish_debug.h
 * @brief High level debug port configuration
 */

#ifndef _WIRISH_WIRISH_DEBUG_H_
#define _WIRISH_WIRISH_DEBUG_H_

#include <libmaple/gpio.h>

/**
 * @brief Disable the JTAG and Serial Wire (SW) debug ports.
 *
 * You can call this function in order to use the JTAG and SW debug
 * pins as ordinary GPIOs.
 *
 * @see enableDebugPorts()
 */
void disableDebugPorts(void);

/**
 * @brief Enable the JTAG and Serial Wire (SW) debug ports (JTAG-DP disabled, SW-DP enabled).
 *
 * @see disableSWD()
 */
void enableSWD(void);

/**
 * @brief Enable the JTAG and Serial Wire (SW) debug ports (JNRST disabled).
 *
 * @see enableSWDJTAGnoJNRST()
 */
void enableSWDJTAGnoJNRST(void);

/**
 * @brief Enable the JTAG and Serial Wire (SW) debug ports.
 *
 * @see enableFullSWDJTAG()
 */
void enableFullSWDJTAG(void);

#endif
