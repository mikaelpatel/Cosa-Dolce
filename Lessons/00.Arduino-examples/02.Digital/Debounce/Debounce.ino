/**
 * @file Debounce.ino
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
 * Each time the input pin goes from LOW to HIGH (e.g. because of a
 * push-button press), the output pin is toggled from LOW to HIGH or
 * HIGH to LOW.  There's a minimum delay between toggles to debounce
 * the circuit (i.e. to ignore noise).
 *
 * @section Circuit
 * Built-in LED attached from pin D13 to ground, pushbutton attached
 * to pin D2 from +5V, 10K resistor attached to pin D2 from ground.
 * Note: on most Arduinos there is already an LED on the board
 * attached to pin D13.
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
 * Rewrite of the Arduino example sketch; 02.Digital/Debounce.
 *
 * This file is part of the Cosa Dolce teaching support project.
 */

#include "Cosa/InputPin.hh"
#include "Cosa/OutputPin.hh"
#include "Cosa/RTT.hh"

InputPin button(Board::D2);
OutputPin led(Board::LED, 1);

// Debounced button state
bool buttonState = false;
bool previousButtonReading = false;

// Latest debounce time in milli-seconds
uint32_t previousDebounceMillis = 0;

// Debounce delay in in milli-seconds
const uint32_t DEBOUNCE_DELAY_MILLIS = 50;

void setup()
{
  RTT::begin();
}

void loop()
{
  // Get current clock and button pin
  uint32_t currentMillis = RTT::millis();
  bool reading = button;

  // Restart the debounce timer if button pin changed
  if (reading != previousButtonReading) {
    previousDebounceMillis = currentMillis;
  }

  // Check if the debounce delay has expired
  else if ((currentMillis - previousDebounceMillis) > DEBOUNCE_DELAY_MILLIS) {

    // Check the button state did actually change
    if (reading != buttonState) {
      buttonState = reading;

      // Toggle LED on rising transition of button
      if (buttonState) {
        led.toggle();
      }
    }
  }

  // Save the button pin reading
  previousButtonReading = reading;
}
