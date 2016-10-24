/**
 * @file DigitalInputPullup.ino
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
 * This example demonstrates the use of INPUT_PULLUP. It reads a
 * digital input on pin D2 and prints the results to the serial
 * monitor.
 *
 * @section Circuit
 * Momentary switch attached from pin D2 to ground. Built-in LED on
 * pin D13. Unlike INPUT pin mode, there is no pull-down resistor
 * necessary. An internal 20K-ohm resistor is pulled to 5V. This
 * configuration causes the input to read HIGH when the switch is
 * open, and LOW when it is closed.
 *
 *              VCC
 *               |
 *             [20K]
 *               |
 *    +--------> D2
 *    |
 *   \
 *    |
 *   GND
 *
 * @section Acknowledgement
 * Rewrite of the Arduino example sketch; 02.Digital/DigitalInputPullup.
 *
 * This file is part of the Cosa Dolce teaching support project.
 */

#include "Cosa/InputPin.hh"
#include "Cosa/OutputPin.hh"
#include "Cosa/UART.hh"
#include "Cosa/IOStream.hh"

OutputPin led(Board::LED);
InputPin button(Board::D2, InputPin::PULLUP_MODE);
IOStream ios(&uart);

void setup()
{
  uart.begin(9600);
}

void loop()
{
  bool reading = button;
  ios << reading << endl;
  led = !reading;
  delay(100);
}
