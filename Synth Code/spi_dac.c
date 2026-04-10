/*
 * spi_dac.c — AD5686RARUZ SPI DAC driver
 * ESE3500 Final Project — Guitar Synthesizer Controller
 * Team 3: Synth Specialist (Guitar Hero Edition)
 * Authors: Adam Shalabi, Brandon Parkansky, Panos Dimtsoudis
 *
 * AD5686RARUZ 24-bit SPI frame:
 *   [23:20] CMD   — 0x3 = Write Input Register n and Update DAC Register n
 *   [19:16] ADDR  — 0x1 = DAC A, 0x2 = B, 0x4 = C, 0x8 = D
 *   [15:0]  DATA  — 16-bit sample, MSB first
 */

#include <avr/io.h>
#include "spi_dac.h"

#define DAC_DDR   DDRB
#define DAC_PORT  PORTB
#define DAC_CS    PB2
#define DAC_MOSI  PB3
#define DAC_SCK   PB5

/* Write to Input Register n and update DAC Register n immediately. */
#define AD5686_CMD_WRITE_UPDATE  0x03U
/* DAC A is address 0x1 (not 0x0 — that is an invalid address for this cmd). */
#define AD5686_ADDR_DAC_A        0x01U

/* Asserts the DAC chip-select line. */
static inline void cs_assert(void)
{
    DAC_PORT &= ~(1 << DAC_CS);
}

/* Deasserts the DAC chip-select line. */
static inline void cs_deassert(void)
{
    DAC_PORT |= (1 << DAC_CS);
}

/* Shifts one byte out over SPI and waits for completion. */
static void spi_transmit(uint8_t byte)
{
    SPDR0 = byte;
    while (!(SPSR0 & (1 << SPIF)));
    (void)SPDR0;
}

/* Configures SPI master mode and the AD5686 chip-select pin. */
void spi_dac_init(void)
{
    DAC_DDR |= (1 << DAC_MOSI) | (1 << DAC_SCK) | (1 << DAC_CS);
    cs_deassert();
    SPCR0 = (1 << SPE) | (1 << MSTR) | (1 << CPHA);
    SPSR0 |= (1 << SPI2X);
}

/* Sends a 16-bit sample to DAC channel A over SPI. */
void spi_dac_write(uint16_t sample)
{
    uint8_t byte0 = (uint8_t)((AD5686_CMD_WRITE_UPDATE << 4) |
                               AD5686_ADDR_DAC_A);
    uint8_t byte1 = (uint8_t)(sample >> 8);
    uint8_t byte2 = (uint8_t)(sample & 0xFFU);

    cs_assert();
    spi_transmit(byte0);
    spi_transmit(byte1);
    spi_transmit(byte2);
    cs_deassert();
}
