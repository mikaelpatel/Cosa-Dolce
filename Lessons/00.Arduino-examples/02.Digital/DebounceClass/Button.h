/**
 * @file Button.h
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
 * This file is part of the Cosa Dolce teaching support project.
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "Cosa/RTT.hh"
#include "Cosa/InputPin.hh"

/**
 * Debounced button class. Detects and debounces changes on button
 * input pin.
 */
class Button {
public:
  /** Debounce delay time in milli-seconds. */
  const uint32_t DEBOUNCE_DELAY_MILLIS = 50L;

  /**
   * Construct debounced button with given board pin.
   * @param[in] pin digital pin.
   */
  Button(Board::DigitalPin pin) :
    m_pin(pin),
    m_state(false),
    m_lastReading(false),
    m_lastDebounceMillis(0)
  {}

  /**
   * Check if the button pin state has changed. Should be frequently
   * called allow debouncing logic to work. Returns true(1) if the
   * state was changed otherwise false(0).
   * @return bool.
   */
  bool changed()
  {
    uint32_t currentMillis = RTT::millis();
    bool reading = m_pin;
    bool res = false;
    if (reading != m_lastReading) {
      m_lastDebounceMillis = currentMillis;
    }
    else if ((currentMillis - m_lastDebounceMillis) > DEBOUNCE_DELAY_MILLIS) {
      if (reading != m_state) {
	m_state = reading;
	res = true;
      }
    }
    m_lastReading = reading;
    return (res);
  }

  /**
   * Check if the button was pushed (falling). Should be frequently
   * called allow debouncing logic to work. Returns true(1) if the
   * button was pushed otherwise false(0).
   * @return bool.
   */
  bool pushed()
  {
    return (changed() && !m_state);
  }

  /**
   * Check if the button was released (rising). Should be frequently
   * called allow debouncing logic to work. Returns true(1) if the
   * button was released otherwise false(0).
   * @return bool.
   */
  bool released()
  {
    return (changed() && m_state);
  }

  /**
   * Return the current button state.
   * @return bool.
   */
  operator bool()
  {
    return (m_state);
  }

 protected:
  InputPin m_pin;
  bool m_state;
  bool m_lastReading;
  uint32_t m_lastDebounceMillis;
};

#endif
