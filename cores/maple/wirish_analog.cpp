/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Perry Hung.
 * Copyright (c) 2011, 2012 LeafLabs, LLC.
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
 * @file wirish/wirish_analog.cpp
 * @brief Wiring-style analogRead() implementation.
 */

#include "io.h"
#include <libmaple/adc.h>
#include "boards.h"

#define INT_TEMPERATURE_CH 16
#define INT_VOLTAGE_CH 17

const float VRefInt = 1.20; // Volts Ref Int (1.16 - 1.24)

const float AverageSlope = 0.0043; // V/oC (0.004 - 0.0046)
const float V25 = 1.43;            // Volts (1.34 - 1.52)

/* Unlike Wiring and Arduino, this assumes that the pin's mode is set
 * to INPUT_ANALOG. That's faster, but it does require some extra work
 * on the user's part. Not too much, we think ;). */
uint16 analogRead(uint8 pin)
{
    adc_dev *dev = PIN_MAP[pin].adc_device;

    if (dev == NULL)
    {
        return 0;
    }

    return adc_read(dev, PIN_MAP[pin].adc_channel);
}

float internalVoltage()
{
    uint16_t adc = adc_read(ADC1, INT_VOLTAGE_CH);
    return VRefInt * 4096.0 / (float)adc;
}

float internalTemperature()
{
    uint16_t adc = adc_read(ADC1, INT_TEMPERATURE_CH);
    float volts = 3.3 / 4096.0 * (float)adc;
    return ((V25 - volts) / AverageSlope) + 25.0;
}
