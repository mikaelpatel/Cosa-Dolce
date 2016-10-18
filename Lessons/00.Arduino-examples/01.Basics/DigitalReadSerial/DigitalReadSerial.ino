/**
 * @file DigitalReadSerial.ino
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
 * Reads a digital input on pin D2, prints the result to the serial
 * monitor. Use a pull-down resistor.
 *
 * @section Circuit
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
 * @section Note
 * While the Arduino core implicity includes all the header files,
 * Cosa requires explicit include of the components used by the
 * sketch. The setup function is also responsible for initiating all
 * components used.
 *
 * @section Acknowledgement
 * Rewrite of the Arduino example sketch; 01.Basics/DigitalReadSerial.
 *
 * This file is part of the Cosa Dolce teaching support project.
 */

#include "Cosa/InputPin.hh"
#include "Cosa/UART.hh"
#include "Cosa/IOStream.hh"

InputPin button(Board::D2);
IOStream ios(&uart);

void setup()
{
  uart.begin(9600);
}

void loop()
{
  ios << button << endl;
  delay(100);
}
