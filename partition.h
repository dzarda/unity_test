#pragma once

#include <stdint.h>
#include "status_codes.h"

typedef struct {
	uint32_t start;
	uint32_t size;
} partition_t;

#define DECLARE_PARTITION(NAME, START, SIZE) \
partition_t NAME = { \
	.start = START, \
	.size = SIZE \
}

status_code_t partition_read(const partition_t *part, uint32_t addr, unsigned char *dest, uint32_t bytes);
status_code_t partition_write(const partition_t *part, uint32_t addr, unsigned char *src, uint32_t bytes);
