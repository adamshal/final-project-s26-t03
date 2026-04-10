/*
 * synth.h — DDS wavetable engine interface
 * ESE3500 Final Project — Guitar Synthesizer Controller
 * Team 3: Synth Specialist (Guitar Hero Edition)
 * Authors: Adam Shalabi, Brandon Parkansky, Panos Dimtsoudis
 */

#ifndef SYNTH_H
#define SYNTH_H

#include <stdint.h>

/* Starts the Timer1 audio interrupt at 31250 Hz. */
void synth_init(void);

/* Tunes the oscillator to the given note index and unmutes. */
void synth_set_note(uint8_t note_idx);

/* Silences the audio output. */
void synth_mute(void);

/* Shifts the current pitch by the given number of semitones. */
void synth_set_bend(int8_t semitones);

#endif /* SYNTH_H */
