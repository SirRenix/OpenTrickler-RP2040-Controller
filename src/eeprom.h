#ifndef CAT24C256_EEPROM_H_
#define CAT24C256_EEPROM_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "http_rest.h"

#define EEPROM_METADATA_BASE_ADDR               0 * 1024       // 0K
#define EEPROM_SCALE_CONFIG_BASE_ADDR           1 * 1024       // 1K
#define EEPROM_WIRELESS_CONFIG_BASE_ADDR        2 * 1024       // 2K
#define EEPROM_MOTOR_CONFIG_BASE_ADDR           4 * 1024       // 4K
#define EEPROM_CHARGE_MODE_BASE_ADDR            5 * 1024       // 5K
#define EEPROM_APP_CONFIG_BASE_ADDR             6 * 1024       // 6k
#define EEPROM_NEOPIXEL_LED_CONFIG_BASE_ADDR    7 * 1024       // 7k
#define EEPROM_ROTARY_BUTTON_CONFIG_BASE_ADDR   8 * 1024       // 8k 
#define EEPROM_PROFILE_DATA_BASE_ADDR           9 * 1024       // 9k

#define EEPROM_METADATA_REV                     2              // 16 byte 


typedef struct {
    uint16_t eeprom_metadata_rev;
    char unique_id[8];
} __attribute__((packed)) eeprom_metadata_t;

// EEPROM save handler function
typedef bool (*eeprom_save_handler_t)(void);


#ifdef __cplusplus
extern "C" {
#endif

bool eeprom_init(void);
bool eeprom_config_save();
bool eeprom_read(uint16_t data_addr, uint8_t * data, size_t len);
bool eeprom_write(uint16_t data_addr, uint8_t * data, size_t len);

bool eeprom_get_board_id(char ** board_id_buffer, size_t bytes_to_copy);

/*
 * Fill all EEPROM with 0xFF
 */
uint8_t eeprom_erase(bool);
uint8_t eeprom_save_all(void);
void eeprom_register_handler(eeprom_save_handler_t handler);

bool http_rest_system_control(struct fs_file *file, int num_params, char *params[], char *values[]);


#ifdef __cplusplus
}
#endif

#endif  // CAT24C256_EEPROM_H_