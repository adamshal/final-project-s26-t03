/*
 * inputs.h — Button debounce, ADC, and strum interrupt interface
 * ESE3500 Final Project — Guitar Synthesizer Controller
 * Team 3: Synth Specialist (Guitar Hero Edition)
 * Authors: Adam Shalabi, Brandon Parkansky, Panos Dimtsoudis
 */

#ifndef INPUTS_H
#define INPUTS_H

#include <stdint.h>

/* Returned when no fret button is pressed. */
#define FRET_NONE  0xFFU

/* Latest ADC readings for whammy bar and joystick axes. */
extern volatile uint16_t inputs_whammy;
extern volatile uint16_t inputs_joy_x;
extern volatile uint16_t inputs_joy_y;

/* Called by ISR when the strum switch fires. */
void on_strum(void);

/* Called by inputs_tick when the mute button is pressed. */
void on_mute(void);

/* Called by inputs_tick when the active fret changes. */
void on_pitch_change(uint8_t fret);

/* Configures all input pins, the strum interrupt, and the ADC. */
void inputs_init(void);

/* Advances debounce counters and fires callbacks on state changes; call every 1 ms. */
void inputs_tick(void);

/* Reads whammy and joystick ADC channels and updates the extern variables. */
void inputs_adc_scan(void);

#endif /* INPUTS_H */
