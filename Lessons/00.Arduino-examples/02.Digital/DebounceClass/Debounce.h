/**
 * @file Debounce.h
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

#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include "Cosa/RTT.hh"
#include "Cosa/InputPin.hh"

/**
 * Debounced input class. Detects and debounces changes on input pin.
 */
class Debounce {
public:
  /**
   * Construct debounced input pin with given board pin.
   * @param[in] pin digital pin.
   */
  Debounce(Board::DigitalPin pin) :
    m_pin(pin),
    m_state(false),
    m_previousReading(false),
    m_previousDebounceMillis(0)
  {}

  /**
   * Return the current debounced input pin state.
   * @return bool.
   */
  operator bool()
  {
    return (m_state);
  }

  /**
   * Check if the debounce pin state has changed. Should be frequently
   * called to allow debounce logic to work. Returns true(1) if the
   * state was changed otherwise false(0).
   * @return bool.
   */
  bool changed()
  {
    // Get current clockk and read input pin
    uint32_t currentMillis = RTT::millis();
    bool reading = m_pin;
    bool res = false;

    // Restart the debounce timer if input pin changed
    if (reading != m_previousReading) {
      m_previousDebounceMillis = currentMillis;
    }

    // Check if the debounce delay has expired
    else if ((currentMillis - m_previousDebounceMillis) > DEBOUNCE_DELAY_MILLIS) {
      if (reading != m_state) {
	m_state = reading;
	res = true;
      }
    }

    // Save the input pin reading
    m_previousReading = reading;
    return (res);
  }

  /**
   * Check if the input pin was pushed (falling). Should be frequently
   * called to allow debounce logic to work. Returns true(1) if the
   * debounce was pushed otherwise false(0).
   * @return bool.
   */
  bool pushed()
  {
    return (changed() && !m_state);
  }

  /**
   * Check if the input was released (rising). Should be frequently
   * called to allow debounce logic to work. Returns true(1) if the
   * debounce was released otherwise false(0).
   * @return bool.
   */
  bool released()
  {
    return (changed() && m_state);
  }

protected:
  /** Debounce delay time in milli-seconds. */
  const uint32_t DEBOUNCE_DELAY_MILLIS = 50L;

  InputPin m_pin;
  bool m_state;
  bool m_previousReading;
  uint32_t m_previousDebounceMillis;
};

#endif
