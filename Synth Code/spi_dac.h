/*
 * spi_dac.h — AD5686RARUZ SPI DAC driver interface
 * ESE3500 Final Project — Guitar Synthesizer Controller
 * Team 3: Synth Specialist (Guitar Hero Edition)
 * Authors: Adam Shalabi, Brandon Parkansky, Panos Dimtsoudis
 *
 * Hardware: Analog Devices AD5686RARUZ (16-bit quad SPI DAC, internal 2.5V ref)
 *   VOUT_A → Adafruit 5647 Mono Class-D Amp input → Adafruit 4445 3W 4Ω speaker
 *   VOUT_A → SparkFun PRT-08032 3.5mm headphone jack
 *   Power: 8×AA (12V) → LTC1174CS8-5 (5V) → DAC AVDD/DVDD
 * SPI pins (ATmega2560): SCK=PB5, MOSI=PB3, CS=PB2 (active-low)
 * SPI mode: CPOL=0, CPHA=1 (Mode 1), 8 MHz
 */

#ifndef SPI_DAC_H
#define SPI_DAC_H

#include <stdint.h>

/* Configures SPI master mode and the DAC chip-select pin. */
void spi_dac_init(void);

/* Sends a 16-bit sample to DAC channel A over SPI. */
void spi_dac_write(uint16_t sample);

#endif /* SPI_DAC_H */
