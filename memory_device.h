#pragma once

#include <stdint.h>
#include "status_codes.h"

struct mem_dev {
};

#define DECLARE_MEM_DEV(NAME) \
	struct mem_dev NAME = { \
	};

status_code_t memory_read(const struct mem_dev *mem, uint32_t addr, char *dest, uint32_t bytes);
status_code_t memory_write(const struct mem_dev *mem, uint32_t addr, char *src, uint32_t bytes);

