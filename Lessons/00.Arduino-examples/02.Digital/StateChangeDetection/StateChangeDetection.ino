/**
 * @file StateChangeDetection.ino
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
 * State change detection (edge detection): Often, you don't need to
 * know the state of a digital input all the time, but you just need
 * to know when the input changes from one state to another. For
 * example, you want to know when a button goes from OFF to ON. This
 * is called state change detection, or edge detection.
 *
 * This example shows how to detect when a button or button changes
 * from off to on and on to off.
 *
 * @section Circuit
 * Pushbutton attached to pin D2 from +5V, 10K resistor attached to
 * pin D2 from ground. LED attached from pin D13 to ground (or use the
 * built-in LED on most Arduino boards)
 *
 *   VCC
 *    |
 *   \
 *    |
 *    +--------> D2
 *    |
 *  [10K]
 *    |
 *   GND
 *
 * @section Acknowledgement
 * Rewrite of the Arduino example sketch; 02.Digital/StateChangeDetection.
 *
 * This file is part of the Cosa Dolce teaching support project.
 */

#include "Cosa/InputPin.hh"
#include "Cosa/OutputPin.hh"
#include "Cosa/UART.hh"
#include "Cosa/IOStream.hh"

InputPin button(Board::D2);
OutputPin led(Board::LED);

uint16_t buttonPushCounter = 0;
bool previousButtonReading = 0;

IOStream ios(&uart);

void setup()
{
  uart.begin(9600);
}

void loop()
{
  // Read button and check if state has changed
  bool buttonReading = button;
  if (buttonReading != previousButtonReading) {

    // Check if transition was from off to on
    if (buttonReading) {
      ios << ++buttonPushCounter << PSTR(": on ");
    }
    // Or from on to off
    else {
      ios << PSTR("off") << endl;
    }
    delay(50);
  }

  // Save button reading
  previousButtonReading = buttonReading;

  // Turn led on every fourth transition from off to on
  led = (buttonPushCounter % 4 == 0);
}
