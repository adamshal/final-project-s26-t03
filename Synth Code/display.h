/*
 * display.h — SSD1306 128x64 OLED driver interface
 * ESE3500 Final Project — Guitar Synthesizer Controller
 * Team 3: Synth Specialist (Guitar Hero Edition)
 * Authors: Adam Shalabi, Brandon Parkansky, Panos Dimtsoudis
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <stdbool.h>

/* Set when the display needs a redraw. */
extern volatile uint8_t g_display_dirty;

/* Initialises TWI and brings the OLED out of reset. */
void display_init(void);

/* Clears the entire display to black. */
void display_clear(void);

/* Moves the write cursor to the given column and page. */
void display_set_cursor(uint8_t col, uint8_t page);

/* Renders a single ASCII character at the current cursor position. */
void display_print_char(char c);

/* Renders a null-terminated string at the current cursor position. */
void display_print_string(const char *s);

/* Renders a note name looked up by index from flash. */
void display_print_note(uint8_t note_index);

/* Draws a whammy-bar level indicator on the bottom row. */
void display_show_whammy(uint8_t adc_val);

/* Refreshes the note name and whammy bar (simple layout). */
void display_update(uint8_t note_idx, uint16_t whammy);

/* Full UI refresh: double-height note, whammy segments, mute/strum status. */
void display_update_ui(uint8_t note_index, uint8_t whammy,
                       bool muted, bool strumming);

#endif /* DISPLAY_H */
