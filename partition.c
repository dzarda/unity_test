#include "partition.h"
#include <stdlib.h>

#define check_in_range(part, addr, ptr, bytes) \
	if (addr + bytes > part->start + part->size) { \
		return ERR_BAD_ADDRESS; \
	}

#define check_args_valid(part, addr, ptr, bytes) \
	if (ptr == NULL || bytes == 0) { \
		return ERR_INVALID_ARG; \
	}

status_code_t partition_read(const partition_t *part, uint32_t addr, unsigned char *dest, uint32_t bytes)
{
	check_args_valid(part, addr, dest, bytes);
	check_in_range(part, addr, dest, bytes);
	return STATUS_OK;
}

status_code_t partition_write(const partition_t *part, uint32_t addr, unsigned char *src, uint32_t bytes)
{
	check_args_valid(part, addr, src, bytes);
	check_in_range(part, addr, src, bytes);
	return STATUS_OK;
}
