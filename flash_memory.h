#pragma once

#include <stdint.h>
#include "status_codes.h"

struct memory_device {
	const uint32_t write_size;
	const uint32_t erase_size;
};
#define MEMORY_DEVICE_DEFINED

#define DECLARE_FLASH_MEMORY_DEVICE(NAME, WRITE_SIZE, ERASE_SIZE) \
	struct memory_device NAME = { \
		WRITE_SIZE, \
		ERASE_SIZE \
	}

status_code_t memory_read(const struct memory_device *mem, uint32_t addr, char *dest, uint32_t bytes);
status_code_t memory_write(const struct memory_device *mem, uint32_t addr, char *src, uint32_t bytes);
status_code_t memory_erase(const struct memory_device *mem, uint32_t addr, uint32_t bytes);
