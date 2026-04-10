/*
 * envelope.h — ADSR envelope state machine interface
 * ESE3500 Final Project — Guitar Synthesizer Controller
 * Team 3: Synth Specialist (Guitar Hero Edition)
 * Authors: Adam Shalabi, Brandon Parkansky, Panos Dimtsoudis
 */

#ifndef ENVELOPE_H
#define ENVELOPE_H

#include <stdint.h>

/* Tick counter incremented every sample by envelope_tick(). */
extern volatile uint32_t envelope_ticks;

/* Precomputes step sizes and resets the envelope to idle. */
void envelope_init(void);

/* Starts the attack phase. */
void envelope_trigger(void);

/* Starts the release phase from any active state. */
void envelope_release(void);

/* Advances the envelope state machine by one sample tick. */
void envelope_tick(void);

/* Returns the current gain scalar (0 = silence, 65535 = full). */
uint16_t envelope_get(void);

#endif /* ENVELOPE_H */
