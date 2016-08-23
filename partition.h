#pragma once

#include "status_codes.h"
#include "memory_device.h"
#include <stdint.h>

struct partition {
	struct memory_device *mem_dev;
	uint32_t start;
	uint32_t size;
};

#define DECLARE_PARTITION(NAME, MEM_DEV, START, SIZE) \
struct partition NAME = { \
	.mem_dev = MEM_DEV, \
	.start = START, \
	.size = SIZE \
}

status_code_t partition_read(const struct partition *part, uint32_t addr, char *dest, uint32_t bytes);
status_code_t partition_write(const struct partition *part, uint32_t addr, char *src, uint32_t bytes);
status_code_t partition_erase(const struct partition *part, uint32_t addr, uint32_t bytes);
