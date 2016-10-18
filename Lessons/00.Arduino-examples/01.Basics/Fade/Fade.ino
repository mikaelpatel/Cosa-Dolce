/**
 * @file Fade.ino
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
 * This example shows how to fade an LED on PWM3 (D9) using the Cosa
 * PWMPin functions. If you want to change the pin you're using, be
 * sure to use another PWM capable pin. On most Arduino, the PWM pins
 * are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and
 * ~11. See Cosa Board descriptions for further details.
 *
 * @section Circuit
 *
 *    +--------- D9/PWM3
 *    |
 *  [330]
 *    |
 *    V  LED
 *   ---
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
 * Rewrite of the Arduino example sketch; 01.Basics/Fade.
 *
 * This file is part of the Cosa Dolce teaching support project.
 */

#include "Cosa/PWMPin.hh"
#include "Cosa/RTT.hh"

PWMPin led(Board::PWM3);
int brightness = 0;
int fadeAmount = 5;

void setup()
{
  RTT::begin();
  led.begin();
}

void loop()
{
  led = brightness;
  brightness += fadeAmount;
  if (brightness <= 0 || brightness >= 255)
    fadeAmount = -fadeAmount;
  delay(10);
}
