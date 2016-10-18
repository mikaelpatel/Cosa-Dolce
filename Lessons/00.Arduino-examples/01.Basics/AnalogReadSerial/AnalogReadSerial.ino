/**
 * @file AnalogReadSerial.ino
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
 * Reads an analog input on pin A0 and prints the result to the serial
 * monitor. Graphical representation is available using serial plotter
 * (Tools > Serial Plotter menu).
 *
 * @section Circuit
 * Attach the center pin of a potentiometer to pin A0, and the outside
 * pins to +5V and ground.
 *
 *   VCC
 *    |
 *  [VR]-------> A0
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
 * Rewrite of the Arduino example sketch; 01.Basics/AnalogReadSerial.
 *
 * This file is part of the Cosa Dolce teaching support project.
 */

#include "Cosa/AnalogPin.hh"
#include "Cosa/UART.hh"
#include "Cosa/IOStream.hh"
#include "Cosa/Watchdog.hh"

AnalogPin sensor(Board::A0);
IOStream ios(&uart);

void setup()
{
  uart.begin(9600);
  Watchdog::begin();
  AnalogPin::powerup();
}

void loop()
{
  ios << sensor << endl;
  delay(100);
}
