/**
 * @file Blink.ino
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
 * Turns on an LED on for one second, then off for one second. Uses
 * busy wait for delay.
 *
 * @section Note
 * While the Arduino core implicity includes all the header files,
 * Cosa requires explicit include of the components used by the
 * sketch. The setup function is also responsible for initiating all
 * components used.
 *
 * @section Acknowledgement
 * Rewrite of the Arduino example sketch; 01.Basics/Blink.
 *
 * This file is part of the Cosa Dolce teaching support project.
 */

#include "Cosa/OutputPin.hh"

OutputPin led(Board::LED);

void loop()
{
  led.on();
  delay(1000);
  led.off();
  delay(1000);
}
