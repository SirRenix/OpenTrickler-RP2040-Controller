#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "hardware/spi.h"

#define DISPlAY0_SPI spi0
#define DISPLAY0_RX_PIN PICO_DEFAULT_SPI_RX_PIN
#define DISPLAY0_TX_PIN PICO_DEFAULT_SPI_TX_PIN
#define DISPLAY0_CS_PIN PICO_DEFAULT_SPI_CSN_PIN
#define DISPLAY0_SCK_PIN PICO_DEFAULT_SPI_SCK_PIN
#define DISPLAY0_A0_PIN 20
#define DISPLAY0_RESET_PIN 21

#define BUTTON0_ENCODER_PIN1 15
#define BUTTON0_ENCODER_PIN2 14
#define BUTTON0_ENC_PIN 22
#define BUTTON0_RST_PIN 12

#define NEOPIXEL_PIN 26

#endif  // CONFIGURATION_H_