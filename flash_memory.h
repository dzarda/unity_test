#pragma once

#include <stdint.h>
#include "status_codes.h"

struct flash_mem {
	const uint32_t write_size;
	const uint32_t erase_size;
};

#define DECLARE_FLASH_MEM(NAME, WRITE_SIZE, ERASE_SIZE) \
	struct flash_mem NAME = { \
		WRITE_SIZE, \
		ERASE_SIZE \
	};

status_code_t flash_read(const struct flash_mem *mem, uint32_t addr, char *dest, uint32_t bytes);
status_code_t flash_write(const struct flash_mem *mem, uint32_t addr, char *src, uint32_t bytes);
status_code_t flash_erase(const struct flash_mem *mem, uint32_t addr, uint32_t bytes);
