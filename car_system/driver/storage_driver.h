#ifndef __STORAGE_DRIVER_H_
#define __STORAGE_DRIVER_H_

#include "esp_err.h"
#include <stdio.h>

/*
  MicroSD Card
  https://docs.espressif.com/projects/esp-idf/en/release-v6.1/esp32s3/api-reference/peripherals/sdmmc_host.html
*/

#define MICROSD_PIN_SPI_MOSI (37)
#define MICROSD_PIN_SPI_CLK (36)
#define MICROSD_PIN_SPI_MISO (35)
#define MICROSD_PIN_SPI_CS (38)
#define MICROSD_MAX_FREQ (10000)
#define MICROSD_MOUNT_POINT "/sdcard"

esp_err_t STORAGE_DRIVER_Init(void);
FILE *STORAGE_DRIVER_FileRead(const char *path);

#endif // __STORAGE_DRIVER_H_