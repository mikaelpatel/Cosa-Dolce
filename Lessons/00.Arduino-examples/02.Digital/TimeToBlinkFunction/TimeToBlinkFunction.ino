/**
 * @file TimeToBlinkFunction.ino
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2016, Mikael Patel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * @section Description
 * Turns on and off a light emitting diode (LED) connected to a
 * digital pin, without using the delay() function. This means that
 * other code can run at the same time without being interrupted by
 * the LED code. Uses the Real-Time Timer (RTT) for millis().
 *
 * Please note the rewrite uses a function, timeToBlink(), to abstract
 * the blink time handling and increase readability.
 *
 * @section Circuit
 * LED attached from pin D13 to ground. Note: on most Arduinos, there
 * is already an LED on the board that's attached to pin D13, so no
 * hardware is needed for this example.
 *
 * @section Acknowledgement
 * Rewrite of the Arduino example sketch; 02.Digital/BlinkWithoutDelay.
 *
 * This file is part of the Cosa Dolce teaching support project.
 */

#include "Cosa/OutputPin.hh"
#include "Cosa/RTT.hh"

OutputPin led(Board::LED);

// Blink interval in milli-seconds
const uint32_t BLINK_INTERVAL_MILLIS = 1000L;

// Latest blink time in milli-seconds
uint32_t previousBlinkMillis = 0;

/**
 * Return true if the blink time interval has expired otherwise false.
 * @return bool.
 */
bool timeToBlink()
{
  uint32_t currentMillis = RTT::millis();
  if ((currentMillis - previousBlinkMillis) < BLINK_INTERVAL_MILLIS)
    return (false);
  previousBlinkMillis = currentMillis;
  return (true);
}

void setup()
{
  RTT::begin();
}

void loop()
{
  if (timeToBlink()) led.toggle();
}
